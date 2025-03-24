#include "my_ls.h"

listnode* add_head(listnode* head, char* name) {  // add a new head to a linked list
    listnode* newhead = NULL;
    newhead = (listnode*) my_malloc("newnode", sizeof(listnode));
    newhead->name = name;
    newhead->next = head;
    head = newhead;
    return head;
}