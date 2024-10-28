#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <math.h>

// 辗转相除法求最大公约数
uint64_t gcd(uint64_t a, uint64_t b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

// 求模反元素
uint64_t mod_inverse(uint64_t e, uint64_t phi_n) {
    int64_t d = 0;
    int64_t x1 = 0;
    int64_t x2 = 1;
    int64_t y1 = 1;
    int64_t temp_phi = phi_n;

    while (e > 0) {
        int64_t temp1 = temp_phi / e;
        int64_t temp2 = temp_phi - temp1 * e;
        temp_phi = e;
        e = temp2;

        int64_t x = x2 - temp1 * x1;
        int64_t y = d - temp1 * y1;

        x2 = x1;
        x1 = x;
        d = y1;
        y1 = y;
    }

    if (temp_phi == 1) {
        return (d + phi_n) % phi_n;
    }
    return 0; // 不存在模反元素
}

// 加密
uint64_t encrypt(uint64_t plaintext, uint64_t e, uint64_t n) {
    uint64_t ciphertext = 1;
    for (int i = 0; i < e; ++i) {
        ciphertext = (ciphertext * plaintext) % n;
    }
    return ciphertext;
}

// 解密
uint64_t decrypt(uint64_t ciphertext, uint64_t d, uint64_t n) {
    uint64_t plaintext = 1;
    for (int i = 0; i < d; ++i) {
        plaintext = (plaintext * ciphertext) % n;
    }
    return plaintext;
}

int main() {
    // RSA 参数
    uint64_t p = 61;
    uint64_t q = 53;
    uint64_t n = p * q;
    uint64_t phi_n = (p - 1) * (q - 1);

    // 选择公钥和私钥
    uint64_t e = 17;
    uint64_t d = mod_inverse(e, phi_n);

    printf("RSA parameters: p=%lu, q=%lu, n=%lu, phi(n)=%lu, e=%lu, d=%lu\n", p, q, n, phi_n, e, d);

    // 加密解密示例
    uint64_t plaintext = 123;
    uint64_t ciphertext = encrypt(plaintext, e, n);
    uint64_t decrypted_text = decrypt(ciphertext, d, n);

    printf("Plaintext: %lu\n", plaintext);
    printf("Ciphertext: %lu\n", ciphertext);
    printf("Decrypted Text: %lu\n", decrypted_text);

    return 0;
}
