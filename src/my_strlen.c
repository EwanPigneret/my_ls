#include "my_ls.h"

/**
 * @summary Return the length of a string
 * @param char* string - The string that needs to be measured
 * @return The length of the string
 */

int my_strlen (char* string) {
    int size = 1;
    while (string[size] != '\0') {
        size += 1;
    }
    return size;
}