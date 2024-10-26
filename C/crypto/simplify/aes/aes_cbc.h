#ifndef HEADER_AES_CBC_H
#define HEADER_AES_CBC_H


#ifdef  __cplusplus
extern "C" {
#endif

// aes128cbc加密
unsigned long AES128_CBC_Encrypt(unsigned char* input_buff, unsigned long InputLen, unsigned char* p_key, unsigned char* iv, unsigned char* output_buff);
// aes128cbc解密
unsigned long AES128_CBC_Decrypt(unsigned char* input_buff, unsigned long InputLen, unsigned char* p_key, unsigned char* iv, unsigned char* output_buff);
# ifdef  __cplusplus
}
# endif
# endif

