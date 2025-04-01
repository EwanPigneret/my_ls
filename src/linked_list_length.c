#include <my_ls.h>

/**
 * @summary Return the length of a linked list
 * @param listnode* head - Head of the linked list
 * @result Length of the linked list
 */

int linked_list_length(listnode* head) {
    listnode* current = head;
    int length = 0;
    while (current != NULL) {
        length += 1;
        current = current->next;
    }
    return length;
}