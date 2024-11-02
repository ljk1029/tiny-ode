/**
 * 1. 调用curl_global_init()初始化libcurl
 * 2. 调用curl_easy_init()函数得到 easy interface型指针
 * 3. 调用curl_easy_setopt()设置传输选项
 * 4. 根据curl_easy_setopt()设置的传输选项，实现回调函数以完成用户特定任务
 * 5. 调用curl_easy_perform()函数完成传输任务
 * 6. 调用curl_easy_cleanup()释放内存
 *  在整过过程中设置curl_easy_setopt()参数是最关键的，几乎所有的libcurl程序都要使用它。
*/
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>


//#define URL_WEBSITE "www.baidu.com"
#define URL_WEBSITE "192.168.10.102:8080"
#define URL_WEBSITE_FILE "192.168.10.102:8080/download"


// 发起GET请求
int http_get() 
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL_WEBSITE);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    
    return 0;
}

// 发起POST请求
int http_post() 
{
    CURL *curl;
    CURLcode res;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL_WEBSITE);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "data=Hello");
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        curl_easy_cleanup(curl);
    }
    
    return 0;
}

// 设置请求头
int http_set() 
{
    CURL *curl;
    CURLcode res;
    struct curl_slist *headers = NULL;

    curl = curl_easy_init();
    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, URL_WEBSITE);
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
        res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }
    
    return 0;
}


// 下载文件
size_t write_callback(void *buffer, size_t size, size_t nmemb, FILE *stream) {
    return fwrite(buffer, size, nmemb, stream);
}

int http_down_file() 
{
    CURL *curl;
    CURLcode res;
    FILE *fp;

    curl = curl_easy_init();
    if (curl) {
        fp = fopen("output_c.txt", "wb");
        if (fp) {
            curl_easy_setopt(curl, CURLOPT_URL, URL_WEBSITE_FILE);
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            res = curl_easy_perform(curl);
            if (res != CURLE_OK) {
                fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
            }
            fclose(fp);
        }
        curl_easy_cleanup(curl);
    }
    
    return 0;
}


int http_test() 
{
    CURL *curl;
    CURLcode res;

    // 初始化 libcurl
    curl = curl_easy_init();
    if (curl) 
    {
        // 设置要访问的 URL
        curl_easy_setopt(curl, CURLOPT_URL, "https://www.baidu.com");

        // 执行 HTTP GET 请求
        res = curl_easy_perform(curl);

        // 检查请求是否成功
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        // 清理 libcurl 资源
        curl_easy_cleanup(curl);
    }

    return 0;
}

int main()
{
    printf("curl version: %s\n", curl_version());

    printf("http_get()\n");
    http_get();

    printf("http_post()\n");
    http_post();

    printf("http_set()\n");
    http_set();

    printf("http_file()\n");
    http_down_file();
    //http_test();
    return 0;
}
