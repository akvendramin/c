#include "platform.h"
#include "../string.h"

int main(int argument_count, char **argument_list)
{
    uint error = 0;
    char *s = "Hello!\0";
    char buffer[5];

    string_length(&error, s);
    string_get_error_message(&error, buffer, sizeof(buffer));

    return 0;
}