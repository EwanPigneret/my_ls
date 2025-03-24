#include <my_ls.h>

void* my_malloc(char* name, size_t size) {  // malloc and bzero a variable, return a message if the malloc failed
    void* buffer = malloc(size);
    if (buffer == NULL) {
        printf("Malloc of %s failed\n", name);
        return;
    } 
    bzero(buffer, size);
    return buffer;
}