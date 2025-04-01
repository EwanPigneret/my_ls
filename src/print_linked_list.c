#include "my_ls.h"

/**
 * @summary print a linked list 
 * @param listnode* head - Head of linked list that is printed
 */

void print_linked_list(listnode* head) {
    listnode* current = head;
    while (current != NULL) {
        if (strcmp(current->name, "")) {
            printf("%s\n", current->name);
        }
        current = current->next;
    }
}   