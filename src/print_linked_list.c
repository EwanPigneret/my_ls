#include "my_ls.h"

void print_linked_list(listnode* head) { // print a linked list 
    listnode* current = head;
    while (current != NULL) {
        if (strcmp(current->name, "")) {
            printf("%s\n", current->name);
        }
        current = current->next;
    }
}   