#include <my_ls.h>

/**
 * @summary Return the length of a linked list
 * @param listnode* head - Head of the linked list
 * @result Length of the linked list
 */

int linked_list_length(listnode* head)
{
    int length = 0;
    listnode* current = head;
    while (current != NULL)
    {
        length += 1;
        current = current->next;
    }
    return length;
}