#include "my_ls.h"

int my_strlen (char* string) {  // return the length of a string
    int size = 1;
    while (string[size] != '\0') {
        size += 1;
    }
    return size;
}