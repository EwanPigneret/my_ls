#include "my_ls.h"

/**
 *
 *
 *
 */

char* concatenation_string(char* string1, char* string2)
{
    int index = 0;
    int jndex = 0;
    char* result = my_malloc("result", sizeof(char) * my_strlen(string1) + my_strlen(string2));
    while (string1[index] != '\0')
    {
        result[index] = string1[index];
        index += 1;
    }
    while (string2[jndex] != '\0')
    {
        result[index] = string2[jndex];
        index += 1;
        jndex += 1;
    }
    return result;
}