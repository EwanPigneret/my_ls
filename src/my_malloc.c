#include <my_ls.h>

/** 
 * @summary Malloc a variable and check if it failed, then initialise it at zero. Return a message if it failed
 * @param char* name, size_t size - Name of the variable malloc, size of the variable 
 * @return Buffer of the variable that has been malloc
 */

void* my_malloc(char* name, size_t size) {
    void* buffer = malloc(size);
    if (buffer == NULL) {
        printf("Malloc of %s failed\n", name);
        return NULL;
    }
    memset(buffer, 0 ,size);
    return buffer;
}