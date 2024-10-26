#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <openssl/pem.h>
#include <openssl/rsa.h>
#include <openssl/bio.h>

int main() {
    const char* private_key_pem = "-----BEGIN PRIVATE KEY-----\n"
                                  "MIIEvwIBADANBgkqhkiG9w0BAQEFAASCBKkwggSlAgEAAoIBAQDIHG9LAL+PAop4\n"
                                  "9du0kJBexUqmPAbcf0C2ghEioLhkvxb3PSrvX+KnFtK9zyJNJN+o+StXkY6R/FqE\n"
                                  "GqTSgX4jkltmrdBqNs2zd4iXXRcSJo7iROXLoE2YMRgcG7wVM7TJlEeIarhUmLS+\n"
                                  "GMJ0kwdWOgjW9nksuhA/rTBrAL270n/HEftJRArWRzbhB9ehetB2/UvYhUb7ty6A\n"
                                  "zzGJ3uL88ZlkqdBOTltecuNpFKf/4st0KSS8kbTO6kx3vTeszNKc6Wh8zZXk96K2\n"
                                  "jx/BDEKhaT8MvE5MFxu86RGYJ7500erLdzWCMjzEMkpkM3oL1j8KZ3AEQdz6XjMK\n"
                                  "vfnfy2DxAgMBAAECggEAPY1VhFYGFhibfEpvmpJO/f+kjw5us9smjhzi5WpXXZHT\n"
                                  "oBf+AWRWhLvF9eFlNSJu83w1IzngBzJ+qxzA7wkqwglOOP6k2U7jJd1SM/DL3Gbk\n"
                                  "01+K6X/07ifHuTmkuEbPyKNl/2WILmlMSx61jYL+Ij02o9xreGEBB30fpAI12jQB\n"
                                  "ga8m8REsedsth3Gvpg1coeRZwjycMofTlVwILKGrscW6C2kBmuhnxIz93FYnBhFw\n"
                                  "zgIHT2KB+DrmQdlE0viitw1cGkVbW0HH+lJ4dvy7RwiUsbI8AOz7yyrXdc2nNxHm\n"
                                  "+NYL2kex2GFiq6nlwrlnjnXt7lEj2qawsIIT3IQ1KwKBgQDZAGZ2Ibr8WIrAA0P5\n"
                                  "hBnNDiDdIBqxG6DGYsT1oeFjNMHsN/VW7XLBad40z/lnRti8tcVaBSBCRFXswurF\n"
                                  "d6xxm4pvFkItTJKDLV+BW1SSLJ/HYFrN2YPB81tl9tX2HhmW0wQyratQ5ucz+6Tx\n"
                                  "y4LoA3kybwV6qeqqMelWaM5XHwKBgQDsEvP5h0/90qejioMBJjYTDu/nsX8yhSdJ\n"
                                  "/5rAlKcVDQsMKGFUzId45kcsMMf0AnEosGwx3kLUdoqqVLnGglhueHvRn+BXG1la\n"
                                  "sCx3NSi3b/6phWuOnjXzVVVhACNFXHCJuu7vcmLDwkdikNt45W2EH8vQYMfAP2og\n"
                                  "WQo5oi2V7wKBgQCtDYyomK2toE7GYdRLn/WTebjrnzaqFwZYL1wzJy2/F8uuvdGB\n"
                                  "yUrCw9LY+yJCIlWl6K/B4mSfdC+x6J+hapay4v+7J10PEwmkYwLO/i6rg7rIHSdN\n"
                                  "EjHo8lHpNrfa1pZBmXa3k5gTpJCs+/nGei2jKWH1vmP4NplVsQgMSPiEsQKBgQC+\n"
                                  "wHXJC5AUHZH9cF94n0KUVb597YtE7BiaD2Ig+DylottpYHt9BKL2isO5rlTzEsIS\n"
                                  "ybMy/E/t0zcqeLl/8DS6Vrpd4JxqZhvmTnIvhJG431Lb8YW+QJKBY1NQxMa7Nf1t\n"
                                  "HNISQtARM7twpnHglynN189dOcZNzi/XoXrEpQnGmwKBgQDWxkpyVKY1eUscF0kG\n"
                                  "Kq2npLAeRLLigsovArzj3NjzPNBmTiNQJbKU7tby9kWpuI0B/VUPhQvau6MgOn4h\n"
                                  "7pIx5OGfaFbZeh8Tj7Ta11MA/D0Y7yEp8t2F/JO6vshj2iqsYV6jNliyxEsr0ys5\n"
                                  "t72Jw+CDOKaOb0U67z7ToYCZ2w==\n"
                                  "-----END PRIVATE KEY-----";

    BIO* bio = BIO_new_mem_buf(private_key_pem, -1);
    RSA* rsa_key = PEM_read_bio_RSAPrivateKey(bio, NULL, NULL, NULL);
    BIO_free(bio);

    if (!rsa_key) {
        fprintf(stderr, "Error loading RSA private key.\n");
        return 1;
    }

    // 提取公钥
    RSA* rsa_pub_key = RSAPublicKey_dup(rsa_key);

    // 输出公钥
    BIO* pub_key_bio = BIO_new(BIO_s_mem());
    PEM_write_bio_RSAPublicKey(pub_key_bio, rsa_pub_key);
    BUF_MEM* pub_key_mem;
    BIO_get_mem_ptr(pub_key_bio, &pub_key_mem);
    printf("Public Key:\n%s\n", pub_key_mem->data);

    // 释放资源
    RSA_free(rsa_key);
    RSA_free(rsa_pub_key);
    BIO_free(pub_key_bio);

    return 0;
}
