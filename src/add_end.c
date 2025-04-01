#include "my_ls.h"

/**
 * @summary Add a new node to the end of a linked list
 * @param listnode* head, char* name - Head of the linked list, name of the new node
 * @return The head of the modified list
 */

listnode* add_end(listnode* head, char* name) {
    listnode* current = head;
    listnode* newnode = NULL;
    while (current->next != NULL) {
        current = current->next;
    }
    newnode = (listnode*) my_malloc("newnode", sizeof(listnode));
    newnode->name = name;
    current->next = newnode;
    newnode->next = NULL;
    return head;
}