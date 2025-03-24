#include "my_ls.h"

listnode* insert_element(listnode* head, char* folder_name) {  // insert a newnode at the end of the list with the given value
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