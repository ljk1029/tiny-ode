#ifndef HEADER_COMMON_H
# define HEADER_COMMON_H

# include <stddef.h>
//#include <openssl/crypto.h>
void OPENSSL_cleanse(void *ptr, size_t len);

#endif