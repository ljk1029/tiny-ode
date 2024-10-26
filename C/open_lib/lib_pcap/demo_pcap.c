#include <pcap.h>
#include <stdio.h>
#include <stdlib.h>


#include <pcap.h>
#include <stdio.h>

int find_all_devs() 
{
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_if_t *alldevs, *d;

    // 获取所有可用的网络接口
    if (pcap_findalldevs(&alldevs, errbuf) == -1) {
        fprintf(stderr, "Error in pcap_findalldevs: %s\n", errbuf);
        return 1;
    }

    for(d=alldevs;d;d=d->next)
	{
		printf("name:        %s\n",d->name);
	}

    // 释放设备列表
    pcap_freealldevs(alldevs);

    return 0;
}


// 接收网络数据回调
void packet_handler(unsigned char *user_data, const struct pcap_pkthdr *pkthdr, const unsigned char *packet) 
{
    printf("Packet captured, length = %d bytes\n", pkthdr->len);
}

int init_pcap()
{
    char *dev; // 网络接口名称
    char errbuf[PCAP_ERRBUF_SIZE];
    pcap_t *handle;

    // 获取网络接口名称,这个已经废弃可以用上面函数查找
    dev = pcap_lookupdev(errbuf);
    if (dev == NULL) {
        fprintf(stderr, "Device not found: %s\n", errbuf);
        return 1;
    }

    // 打开网络接口
    handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
    if (handle == NULL) {
        fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
        return 2;
    }

/*
    // 设置过滤条件（可选）
    struct bpf_program fp;
    char filter_exp[] = "port 80";

    if (pcap_compile(handle, &fp, filter_exp, 0, PCAP_NETMASK_UNKNOWN) == -1) {
        fprintf(stderr, "Couldn't parse filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }
    if (pcap_setfilter(handle, &fp) == -1) {
        fprintf(stderr, "Couldn't install filter %s: %s\n", filter_exp, pcap_geterr(handle));
        return 2;
    }
*/
    // 开始捕获数据包
    printf("Capturing on device: %s\n", dev);
    pcap_loop(handle, 0, packet_handler, NULL);

    // 关闭捕获会话
    pcap_close(handle);

}


// 测试
int main(int argc, char *argv[]) 
{
    find_all_devs();
    init_pcap();
    return 0;
}
