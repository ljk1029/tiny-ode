#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "my_md5.h"



int main() {
    MD5_CTX ctx;
    unsigned char digest[MD5_DIGEST_SIZE];
    char message[256];
    printf("Plain Text: ");
    scanf("%s", message);

    md5_init(&ctx);
    md5_update(&ctx, (unsigned char *)message, strlen(message));
    md5_final(&ctx, digest);

    printf("\n");
    printf("MD5 Digest: ");
    for (int i = 0; i < MD5_DIGEST_SIZE; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");

    return 0;
}
