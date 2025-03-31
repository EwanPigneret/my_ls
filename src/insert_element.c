#include "my_ls.h"

/**
 * @summary Insert a newnode at the end of the list with the given value
 * @param listnode* head, char* folder_name - Head of the linked list, name of the new node
 * @return Head of the modified linked list
 */

listnode* insert_element(listnode* head, char* folder_name) {
    listnode* new_node = (listnode*) my_malloc("new_node", sizeof(listnode));
    new_node->name = folder_name;
    listnode* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    current->next->next = NULL;
    return head;
}
