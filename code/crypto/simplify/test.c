#include <stdio.h>
#include <string.h>
#include "md5.h"
#include "sha256.h"

// MD5测试
int test_md5() 
{
    MD5_CTX ctx;
    unsigned char digest[MD5_DIGEST_SIZE];
    char message[256];
    printf("Plain Text: ");
    scanf("%s", message);

    md5((unsigned char *)message, strlen(message), digest);

    printf("\n");
    printf("MD5 Hash: ");
    for (int i = 0; i < MD5_DIGEST_SIZE; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
    return 0;
}

// sha256测试
int test_sha256() 
{
    char message[256] = {0};
    uint8_t hash[SHA256_BLOCK_SIZE];
    printf("Plain Text: ");
    scanf("%s", message);


    sha256((uint8_t*)message, strlen(message), hash);

    printf("SHA-256 Hash:\n");
    for (int i = 0; i < SHA256_BLOCK_SIZE; ++i) 
    {
        printf("%02x", hash[i]);
    }
    printf("\n");
    return 0;
}

int test_aes128_cbc() 
{
    unsigned char key[] = "0123456789abcdef";
    unsigned char iv[]  = "1234567890ABCDEF";//偏移量
	unsigned long outlen;
	unsigned char out_data[96];
	unsigned char in_data[96];
	char message[256] = {0};
    printf("Plain Text: ");
    scanf("%s", message);

	// 加密
	outlen=AES128_CBC_Encrypt(message, strlen(message), key, iv, out_data);
	printf("Encrypt_data: ");
	for(int i=0; i<outlen; i++) {
		printf("%.2x ",out_data[i]);
	}

	// 解密
	memcpy(iv, "1234567890ABCDEF", strlen("1234567890ABCDEF"));
	outlen=AES128_CBC_Decrypt(out_data, outlen, key, iv, in_data);
	printf("\nDecrypt_data: %s, len:%d\n", in_data, outlen);
	return 0;
}

int main()
{
    //test_md5();
    //test_sha256();
    test_aes128_cbc();
    return 0;
}