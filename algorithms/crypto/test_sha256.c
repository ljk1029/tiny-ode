#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "my_sha256.h"



int main() {
    char message[] = "Hello, world!";
    uint8_t hash[SHA256_BLOCK_SIZE];

    sha256((uint8_t*)message, strlen(message), hash);

    printf("SHA-256 Hash:\n");
    for (int i = 0; i < SHA256_BLOCK_SIZE; ++i) {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}
