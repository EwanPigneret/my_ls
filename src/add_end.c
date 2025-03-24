#include "my_ls.h"

listnode* add_end(listnode* head, char* name) {  // add a new node to a linked list
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