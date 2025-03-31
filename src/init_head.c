#include "my_ls.h"

/**
 * @summary Initialize the head of a linked list
 * @param char* head_name - Value given to the head
 * @return The head that has beeen initialised
 */

listnode* init_head(char* head_name) {
    listnode* head = NULL;
    head = (listnode*) my_malloc("head", sizeof(listnode));
    head->name = head_name;
    head->next = NULL;
    return head;
}
