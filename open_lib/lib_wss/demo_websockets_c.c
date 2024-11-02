#include <libwebsockets.h>

static struct lws *client_wsi = NULL;

static int callback_client(struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len) {
    switch (reason) {
        case LWS_CALLBACK_CLIENT_ESTABLISHED:
            // 连接到服务器后的回调
            printf("Connected to WebSocket server\n");

            // 发送数据到服务器
            lws_write(client_wsi, (unsigned char *)"Hello, server!", 14, LWS_WRITE_TEXT);
            break;

        case LWS_CALLBACK_CLIENT_RECEIVE:
            // 接收来自服务器的数据
            printf("Received data from server: %s\n", (char *)in);
            break;

        case LWS_CALLBACK_CLIENT_CONNECTION_ERROR:
            // 连接错误处理
            fprintf(stderr, "WebSocket connection error\n");
            break;

        case LWS_CALLBACK_CLIENT_CLOSED:
            // 连接关闭
            printf("WebSocket connection closed\n");
            break;

        default:
            break;
    }

    return 0;
}

int main() {
    struct lws_context *context;
    struct lws_context_creation_info info;
    memset(&info, 0, sizeof(info));

    const char *address = "127.0.0.1";
    int port = 8080;

    info.port = CONTEXT_PORT_NO_LISTEN;
    info.iface = NULL;
    info.protocols = (const struct lws_protocols[]){
        {"echo-protocol", callback_client, 0, 4096, 0, NULL, 0},
        {NULL, NULL, 0, 0, 0, NULL, 0},
    };

    context = lws_create_context(&info);
    if (!context) {
        fprintf(stderr, "WebSocket client context creation failed\n");
        return -1;
    }

    // 创建 WebSocket 连接信息
    struct lws_client_connect_info ccinfo;
    memset(&ccinfo, 0, sizeof(ccinfo));
    ccinfo.context = context;
    ccinfo.address = address;
    ccinfo.port = port;
    ccinfo.path = "/";
    ccinfo.host = address;
    ccinfo.origin = address;

    // 创建 WebSocket 连接
    client_wsi = lws_client_connect_via_info(&ccinfo);

    if (!client_wsi) {
        fprintf(stderr, "WebSocket client connection failed\n");
        lws_context_destroy(context);
        return -1;
    }

    while (1) {
        lws_service(context, 0);
        // 可以在此处执行其他任务
    }

    lws_context_destroy(context);

    return 0;
}
