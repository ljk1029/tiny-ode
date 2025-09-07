#ifndef MY_MD5_H
#define MY_MD5_H

#define MD5_BLOCK_SIZE 64
#define MD5_DIGEST_SIZE 16

typedef struct {
    uint32_t state[4];
    uint32_t count[2];
    unsigned char buffer[MD5_BLOCK_SIZE];
} MD5_CTX;

void md5_init(MD5_CTX *ctx);
void md5_update(MD5_CTX *ctx, const unsigned char *data, size_t len);
void md5_final(MD5_CTX *ctx, unsigned char *digest);
void md5_transform(uint32_t state[4], const unsigned char block[MD5_BLOCK_SIZE]);

#endif // MY_MD5_H