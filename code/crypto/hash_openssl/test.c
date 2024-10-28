#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "md5.h"
#include "sha.h"


void test_md5()
{
    MD5_CTX ctx;
    unsigned char digest[256];
    char message[256];
    printf("Plain Text: ");
    scanf("%s", message);

    //MD5_Init(&ctx);
    //MD5_Update(&ctx, (unsigned char *)message, strlen(message));
    //MD5_Final(&ctx, digest);
    MD5((unsigned char *)message, strlen(message), digest);

    printf("\n");
    printf("MD5 Digest: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
}

void test_sha()
{
    MD5_CTX ctx;
    unsigned char digest[256];
    char message[256];
    printf("Plain Text: ");
    scanf("%s", message);

    //MD5_Init(&ctx);
    //MD5_Update(&ctx, (unsigned char *)message, strlen(message));
    //MD5_Final(&ctx, digest);
    MD5((unsigned char *)message, strlen(message), digest);

    printf("\n");
    printf("MD5 Digest: ");
    for (int i = 0; i < 16; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n"); 

    memset(digest, 0, 256);
    SHA1((unsigned char *)message, strlen(message), digest);
    printf("SHA1 Digest: ");
    for (int i = 0; i < 20; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
    
    memset(digest, 0, 256);
    int len = strlen(message);
    SHA256((unsigned char *)message, len, digest);
    printf("SHA256 Digest: ");
    for (int i = 0; i < 32; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n"); 

    memset(digest, 0, 256);
    SHA512((unsigned char *)message, strlen(message), digest);
    printf("SHA512 Digest: ");
    for (int i = 0; i < 64; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
}


int main()
{
    test_sha();
    return 0;
}