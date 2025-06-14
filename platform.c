#include "platform.h"

#ifdef __linux__
    #define LINUX
    #include <unistd.h>
    #include <errno.h>
    #include <string.h>
#else
    #error
#endif

PLATFORM_API void platform_get_error_message(uint *error, void *buffer, uptr buffer_size)
{
#ifdef LINUX
    uptr i  = 0;    
    char *string = 0;
    size_t length = 0;
    u8 *destination = 0;

    string = strerror(errno);
    length = strlen(string);
    destination = buffer;

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
#else
    #error
#endif
}

PLATFORM_API void platform_write_console(uint *error, void *buffer, uptr buffer_size)
{
    if(!error)
    {
        return;
    }

#ifdef LINUX
    write(STDOUT_FILENO, buffer, buffer_size);
#else
    #error
#endif
}