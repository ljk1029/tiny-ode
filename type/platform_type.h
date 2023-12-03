#pragma once
#include <sys/types.h>

#define IS_OS_64 0
#define NUM_MAX  0xffffffff

#ifndef bool
#define bool unsigned char
#endif

#ifndef u8
#define u8 unsigned char
#endif

#ifndef u16
#define u16 unsigned short
#endif

#ifndef u32
#define u32 unsigned int
#endif

#ifndef u64 
#define u64 unsigned long long
#endif

#ifndef ul
#define ul unsigned long
#endif


#ifndef int8_t
#define int8_t signed char
#endif

#ifndef int16_t
#define int16_t signed short
#endif

#ifndef int32_t
#define int32_t signed int
#endif


#ifndef true
#define true 1
#endif

#ifndef false
#define false 0
#endif

#if IS_OS_64
    #ifndef size_t
    #define size_t unsigned long 
    #endif
    #ifndef ssize_t
    #define ssize_t signed long
    #endif
#else
    #ifndef size_t
    #define size_t unsigned int 
    #endif
    #ifndef ssize_t
    #define ssize_t signed int
    #endif
#endif

#define MAX(a,b)  ((a)>(b) ? (a):(b))
#define MIN(a,b)  ((a)>(b) ? (b):(a))