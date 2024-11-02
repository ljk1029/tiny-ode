#include <libwebsockets.h>

static int callback_echo(struct lws *wsi, enum lws_callback_reasons reason, void *user, void *in, size_t len) {
    switch (reason) {
        case LWS_CALLBACK_ESTABLISHED:
            // 客户端连接建立
            printf("WebSocket connection established\n");
            break;

        case LWS_CALLBACK_RECEIVE:
            // 接收到客户端发送的数据
            printf("Received data: %s\n", (char *)in);

            // 发送回复
            lws_write(wsi, in, len, LWS_WRITE_TEXT);
            break;

        case LWS_CALLBACK_CLOSED:
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

    info.port = port;
    info.iface = address;
    info.protocols = (const struct lws_protocols[]){
        {"echo-protocol", callback_echo, 0, 4096, 0, NULL, 0},
        {NULL, NULL, 0, 0, 0, NULL, 0},
    };

    context = lws_create_context(&info);
    if (!context) {
        fprintf(stderr, "WebSocket context creation failed\n");
        return -1;
    }

    while (1) {
        lws_service(context, 0);
        // 可以在此处执行其他任务
    }

    lws_context_destroy(context);

    return 0;
}
