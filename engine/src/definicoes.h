#pragma once

//tipos int sem sinal
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

//tipos int com sinal
typedef signed char i8;
typedef signed short i16;
typedef signed int i32;
typedef signed long long i64;

//tipos de ponto flutuante
typedef float f32;
typedef double f64;

//tipos booleanos
typedef int b32;
typedef char b8;

//define static assertions
#if defined(__clang__) || defined(__gcc__)
#define STATIC_ASSERT _Static_assert
#else
#define STATIC_ASSERT static_assert
#endif

STATIC_ASSERT(sizeof(u8) == 1, "tipo u8 deve possuir apenas 1 byte");
STATIC_ASSERT(sizeof(u16) == 2, "tipo u16 deve possuir apenas 2 bytes");
STATIC_ASSERT(sizeof(u32) == 4, "tipo u32 deve possuir apenas 4 bytes");
STATIC_ASSERT(sizeof(u64) == 8, "tipo u64 deve possuir apenas 8 bytes");

STATIC_ASSERT(sizeof(i8) == 1, "tipo i8 deve possuir apenas 1 byte");
STATIC_ASSERT(sizeof(i16) == 2, "tipo i16 deve possuir apenas 2 bytes");
STATIC_ASSERT(sizeof(i32) == 4, "tipo i32 deve possuir apenas 4 bytes");
STATIC_ASSERT(sizeof(i64) == 8, "tipo i64 deve possuir apenas 8 bytes");

STATIC_ASSERT(sizeof(f32) == 4, "tipo f32 deve possuir apenas 4 bytes");
STATIC_ASSERT(sizeof(f64) == 8, "tipo f64 deve possuir apenas 8 bytes");

STATIC_ASSERT(sizeof(b8) == 1, "tipo b8 deve possuir apenas 1 byte");
STATIC_ASSERT(sizeof(b32) == 4, "tipo b32 deve possuir apenas 4 bytes");

#define TRUE 1
#define FALSE 0

// deteccao de plataforma
#if defined(WIN32) || defined(_WIN32) || defined(__WIN32__) 
#define PLATAFORMA_WINDOWS 1
#ifndef _WIN64
#error "64-bit e necessário no windows!"
#endif
#elif defined(__linux__) || defined(__gnu_linux__)
// Linux OS
#define PLATAFORMA_LINUX 1
#if defined(__ANDROID__)
#define PLATAFORMA_ANDROID 1
#endif
#elif defined(__unix__)
// pega qualquer plataforma nao definida acima.
#define PLATAFORMA_UNIX 1
#elif defined(_POSIX_VERSION)
// Posix
#define PLATAFORMA_POSIX 1
#elif __APPLE__
// plataformas Apple 
#define PLATAFORMA_APPLE 1
#include <TargetConditionals.h>
#if TARGET_IPHONE_SIMULATOR
// simulador iOS 
#define PLATAFORMA_IOS 1
#define PLATAFORMA_IOS_SIMULATOR 1
#elif TARGET_OS_IPHONE
#define PLATAFORMA_IOS 1
// dispositivos iOS 
#elif TARGET_OS_MAC
// outros tipos de mac
#else
#error "plataforma apple desconhecida!"
#endif
#else
#error "plataforma desconhecida!!"
#endif
#ifdef KEXPORT
// Exports
#ifdef _MSC_VER
#define KAPI __declspec(dllexport)
#else
#define KAPI __attribute__((visibility("default")))
#endif
#else
// Imports
#ifdef _MSC_VER
#define KAPI __declspec(dllimport)
#else
#define KAPI
#endif
#endif