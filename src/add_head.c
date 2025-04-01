#include "my_ls.h"

/**
 * @summary Add a new head to a linked list
 * @param listnode* head, char* name - Head of the linked list, name of the new node
 * @return The head of the modified list
 */

listnode* add_head(listnode* head, char* name) {
    listnode* newhead = NULL;
    newhead = (listnode*) my_malloc("newnode", sizeof(listnode));
    newhead->name = name;
    newhead->next = head;
    head = newhead;
    return head;
}
