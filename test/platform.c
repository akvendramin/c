#include "platform.h"

int main(int argument_count, char **argument_list)
{
    uint error = 0;
    char b[512];
    char *a = "Hello, world!\n";
    platform_write_console(&error, a, 15);
    platform_get_error_message(&error, b, sizeof(b));

    return 0;
}