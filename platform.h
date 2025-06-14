#ifndef PLATFORM_LIBRARY_H
#define PLATFORM_LIBRARY_H

typedef char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;
typedef s32 sint;
typedef u32 uint;
typedef u32 bool;
typedef long long s64;
typedef unsigned long long u64;
typedef s64 sptr;
typedef u64 uptr;
typedef float f32;
typedef double f64;

#ifdef DEBUG
    #define ASSERT(expression) do { if(!(expression)) { *(int *)0 = 0; } } while(0)
#else
    #define ASSERT(expression)
#endif

#define ARRAY_COUNT(array) sizeof(array) / sizeof((array)[0])
#define KILOBYTES(value) ((value) * (s64)1024)
#define MEGABYTES(value) (KILOBYTES(value) * (s64)1024)
#define GIGABYTES(value) (MEGABYTES(value) * (s64)1024)
#define TERABYTES(value) (GIGABYTES(value) * (s64)1024)

#define PLATFORM_API

PLATFORM_API void platform_get_error_message(uint *error, void *buffer, uptr buffer_size);
PLATFORM_API void platform_write_console(uint *error, void *buffer, uptr buffer_size);

#endif