#include "my_ls.h"

/**
 * @summary concatain two strings
 * @param char* string1, char* string2, char* result
 * First half of the final string, Second half of the final string,
 * result of the fusion of the two strings
 * @result The fusioned strings
 */

char* concatenation_string(char* string1, char* string2, char* result)
{
    result = my_malloc("result", sizeof(char) * (my_strlen(string1) + my_strlen(string2)) + 1);
    int index = 0;
    int jndex = 0;
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
    result[index] = '\0';
    return result;
}
