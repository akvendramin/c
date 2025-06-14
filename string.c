#include "string.h"

STRING_API void string_get_error_message(uint *error, void *buffer, uptr buffer_size)
{
    uint i = 0;
    char *string = 0;
    uptr length = 0;
    u8 *destination = buffer;

    if(!error)
    {
        return;
    }

    switch(*error)
    {
        case STRING_ERROR_BUFFER_OVERFLOW:
        {
            string = "STRING_ERROR_BUFFER_OVERFLOW";
        } break;

        default:
        {
            string = "STRING_ERROR_SUCCESS";
        } break;
    }

    length = string_length(error, string);

    for(i = 0; (i < buffer_size) && (i < length); i++)
    {
        *destination++ = string[i];
    }

    if(buffer_size < (length + 1))
    {
        *--destination = '\0';
    }
    else
    {
        *destination = '\0';
    }
}

STRING_API uptr string_length(uint *error, char *string)
{
    uptr result = 0;

    if(!error)
    {
        return result;
    }

    while(*string++ != '\0')
    {

        if(result == MAX_U64)
        {
            *error = STRING_ERROR_BUFFER_OVERFLOW;
            return result;
        }

        result++;
    }

    return result;
}