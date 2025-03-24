#include "my_ls.h"

listnode* init_head(char * head_name) {  // initialize the head of a list with a value
    listnode* head = NULL;
    head = (listnode*) my_malloc("head", sizeof(listnode));
    head->name = head_name;
    head->next = NULL;
    return head;
}