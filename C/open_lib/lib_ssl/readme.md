## 库编译
./config
make

如果安装到linux上
sudo make install

可以提前配置路径
./config --prefix=/path/to/custom/installation/directory
make
make install

版本验证
curl --version

指定openssl库时
./configure --with-ssl=/path/to/openssl
使用cmake时
cmake -DOPENSSL_ROOT_DIR=/usr/local/openssl -DOPENSSL_LIBRARIES=/usr/local/openssl/lib ..


绑定证书时
./configure --with-ca-bundle=/path/to/ca-bundle.crt


## 使用库编译
### 基本API
1.       调用curl_global_init()初始化libcurl
2.       调用curl_easy_init()函数得到 easy interface型指针
3.       调用curl_easy_setopt()设置传输选项
4.       根据curl_easy_setopt()设置的传输选项，实现回调函数以完成用户特定任务
5.       调用curl_easy_perform()函数完成传输任务
6.       调用curl_easy_cleanup()释放内存
在整过过程中设置curl_easy_setopt()参数是最关键的，几乎所有的libcurl程序都要使用它。

### curl_easy_setopt函数部分选项介绍
CURLOPT_URL 	
    设置访问URL

CURLOPT_WRITEFUNCTION，CURLOPT_WRITEDATA	
    回调函数原型为：size_t function( void *ptr, size_t size, size_t nmemb, void *stream); 函数将在libcurl接收到数据后被调用，因此函数多做数据保存的功能，如处理下载文件。CURLOPT_WRITEDATA 用于表明CURLOPT_WRITEFUNCTION函数中的stream指针的来源。如果你没有通过CURLOPT_WRITEFUNCTION属性给easy handle设置回调函数，libcurl会提供一个默认的回调函数，它只是简单的将接收到的数据打印到标准输出。你也可以通过 

CURLOPT_WRITEDATA	
    属性给默认回调函数传递一个已经打开的文件指针，用于将数据输出到文件里。

CURLOPT_HEADERFUNCTION	
    回调函数原型为 size_t function( void *ptr, size_t size,size_t nmemb, void *stream); libcurl一旦接收到http 头部数据后将调用该函数。

CURLOPT_HEADERDATA	CURLOPT_WRITEDATA 
    传递指针给libcurl，该指针表明CURLOPT_HEADERFUNCTION 函数的stream指针的来源。

CURLOPT_READFUNCTION 	
    libCurl需要读取数据传递给远程主机时将调用CURLOPT_READFUNCTION指定的函数，函数原型是：size_t function(void *ptr, size_t size, size_t nmemb,void *stream). 
CURLOPT_READDATA 
    CURLOPT_READDATA 表明CURLOPT_READFUNCTION函数原型中的stream指针来源。
CURLOPT_NOPROGRESS，	
    跟数据传输进度相关的参数。

CURLOPT_PROGRESSFUNCTION，CURLOPT_PROGRESSDATA	CURLOPT_PROGRESSFUNCTION 
    指定的函数正常情况下每秒被libcurl调用一次，为了使CURLOPT_PROGRESSFUNCTION被调用，CURLOPT_NOPROGRESS必须被设置为false，
	CURLOPT_PROGRESSDATA指定的参数将作为CURLOPT_PROGRESSFUNCTION指定函数的第一个参数

CURLOPT_TIMEOUT	 
    由于设置传输时间，
CURLOPT_CONNECTIONTIMEOUT 
    设置连接等待时间

CURLOPT_FOLLOWLOCATION	
    设置重定位URL

CURLOPT_RANGE: 	
    断点续传相关设置。CURLOPT_RANGE 指定char *参数传递给libcurl，用于指明http域的RANGE头域，例如：
	表示头500个字节：bytes=0-499
	表示第二个500字节：bytes=500-999
	表示最后500个字节：bytes=-500
	表示500字节以后的范围：bytes=500-
	第一个和最后一个字节：bytes=0-0,-1
	同时指定几个范围：bytes=500-600,601-999

CURLOPT_RESUME_FROM	
    传递一个long参数给libcurl，指定你希望开始传递的 偏移量。

### 状态码
curl_easy_perform 函数说明（error 状态码）
1     CURLE_OK 	返回0意味一切ok任务完成一切都好
2     CURLE_UNSUPPORTED_PROTOCOL	不支持的协议，由URL的头部指定
3     CURLE_COULDNT_CONNECT	不能连接到remote 主机或者代理
4     CURLE_REMOTE_ACCESS_DENIED	访问被拒绝
5     CURLE_HTTP_RETURNED_ERROR	Http返回错误
6     CURLE_READ_ERROR	读本地文件错误
要获取详细的错误描述字符串，可以通过const char *curl_easy_strerror(CURLcode errornum ) 这个函数取得.