void stop_pcap(void)
{
	int ret = 0;

	if (thread_parser_thd)
	{
		exit_thread_parser_thd = TRUE;
		ret = pthread_join(thread_parser_thd, NULL);
		thread_parser_thd = 0;
		exit_thread_parser_thd = FALSE;
		log_i("thread_parser", "stop_pcap pthread_join thread_parser_thd\n");
	}

	system_call_free();

	if (pcap_t_handle != NULL)
	{
		pcap_close(pcap_t_handle);
		pcap_t_handle = NULL;
		pcap_init = FALSE;
	}

	if (ip_data_dispatcher_thd)
	{
		ret = pthread_join(ip_data_dispatcher_thd, NULL);
		ip_data_dispatcher_thd = 0;
		log_i("thread_parser", "stop_pcap pthread_join ip_data_dispatcher_thd\n");
	}

	sniffer_stop();
	destory_network_list(&pHeadNetList);

	return;
}

static void *dispatcher(void *args)
{
	pthread_t pthreadNetwork;
	pcap_if_t *p = NULL;
	char error[100];
	struct in_addr net_ip_addr;
	struct in_addr net_mask_addr;
	struct ether_header *ethernet;
	
	char *net_ip_string;
	char *net_mask_string;
	char *interface;
	u_int32_t net_ip;
	u_int32_t net_mask;
	
	struct pcap_pkthdr pack; 
	const u_char *content;
	static bool start_oneshot = false;
	pthread_detach(pthread_self());
	interface = args;
	get_local_ip(interface);	
	if((pcap_t_handle=pcap_open_live(interface,IF_INTERFACE_MAX_SIZE,1,100,error))==NULL){
		char log[256] = {0};
		sprintf(log,"%s\n",error);
		log_v("networkmonitor", log);
		return NULL;
	}
	//	pcap_setnonblock(pcap_t_handle, 1, error);
	if(pcap_lookupnet(interface,&net_ip,&net_mask,error)==-1){
		char log[256] = {0};
		sprintf(log,"%s",error);
		log_v("networkmonitor", log);
		return NULL;
	}

	create_crc_table();//from table
	tcp_scanner_init();//tcp init
	udp_scanner_init();//udp init
	system_call_init();//you can delete it
	piddetection_scanner_init();//pid init
	icmp_scan_init();//icmp init
	//igmp no init
	//arp  no init
	create_parserthread();//thread create

	get_local_mac(interface);
	net_ip_addr.s_addr=net_ip;
	net_ip_string  =inet_ntoa((struct in_addr){.s_addr=net_ip_addr.s_addr});
	net_mask_string=inet_ntoa((struct in_addr){.s_addr=net_mask});
	pcap_init = TRUE;
	pcap_loop(pcap_t_handle,-1,call,interface);
	return NULL;
}

void data_dispatcher_init(s8 *interface_name)
{
	static s8 tmp[IF_INTERFACE_NAME_MAX_SIZE];
	if(interface_name == NULL)
		return;
	if(ip_data_dispatcher_thd != 0)
		return;
	memset(tmp,0,sizeof(tmp));
	memcpy(tmp,interface_name,strnlen(interface_name,IF_INTERFACE_NAME_MAX_SIZE));
	int stacksize = 100*1024; 
	pthread_attr_t attr;
	int ret = pthread_attr_init(&attr); 
	if((ret = pthread_attr_setstacksize(&attr, stacksize)) != 0){
		char log[256] = {0};
		sprintf(log,"%s","statcksize set error");
		log_i("networkmonitor", log);
	}
	pthread_create(&ip_data_dispatcher_thd,&attr,dispatcher,tmp);
	if((ret = pthread_attr_destroy(&attr)) != 0){
		char log[256] = {0};
		sprintf(log,"%s","thread attr destory error");
		log_i("networkmonitor", log);
	}
	while(pcap_init == FALSE)
		usleep(10000);
}

void list_network_card()
{
	pcap_t *handle;
	pcap_if_t *alldev;
	pcap_if_t *p;
	char error[100];
	char *interface;
	int i=0,num;
	if(pcap_findalldevs(&alldev,error)==-1)
	{
		char log[256] = {0};
		sprintf(log,"%s""find all devices is error");
		log_i("networkmonitor", log);
		return;
	}
	for(p=alldev;p;p=p->next)
	{
		//printf("%d:%s\n",++i,p->name);
		if(p->description)
		{
			char log[256] = {0};
			sprintf(log,"%s",p->description);
			log_v("networkmonitor", log);
		}
	}
	if(i==1)
		interface=p->name;
	else
	{
		printf("please input which interface you want to use\n");
		scanf("%d",&num);
		if(num<1||num>i)
		{
			char log[256] = {0};
			sprintf(log,"%s","interface is unavillible");
			log_i("networkmonitor", log);
			return;
		}
		for(p=alldev,i=1;i<=num;p=p->next,i++)
			interface=p->name;
	}
}

