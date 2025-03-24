#include "my_ls.h"

listnode* add_node(listnode* head, listnode* node, int (*cmp_func)(listnode*, listnode*)) {  // add a node in the middle of a linked list
    listnode* current = head;
    listnode* newnode = NULL;
    listnode* tempnode;
    while (current->next != NULL && cmp_func(current->next, node) < 1) {
        current = current->next;
    }
    if (current->next != NULL) {  // check if the function wasn't used incorrectly
            newnode = (listnode*) my_malloc("newnode", sizeof(listnode));
        newnode->name = node->name;
        tempnode = current->next;
        current->next = newnode;
        newnode->next = tempnode; 
    }
    else {  // return a error if it didn't find the node
        printf("Node not found : %s\n", node->name);
    }
    return head;
}