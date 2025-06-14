#ifndef STRING_LIBRARY_H
#define STRING_LIBRARY_H

#define PLATFORM_NO_API
#include "platform.h"

#define STRING_API

typedef enum
{
    STRING_ERROR_SUCCESS = 0,
    STRING_ERROR_BUFFER_OVERFLOW = 2,
} string_error;

STRING_API uptr string_length(uint *error, char *string);
STRING_API void string_get_error_message(uint *error, void *buffer, uptr buffer_size);

#endif