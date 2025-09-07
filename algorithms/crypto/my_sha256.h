#ifndef MY_SHA256_H
#define MY_SHA256_H

#include <stdint.h>
#include <stddef.h>

#define SHA256_BLOCK_SIZE 32

void sha256(const uint8_t *data, size_t len, uint8_t *hash);

#endif // MY_SHA256_H