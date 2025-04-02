#include "my_ls.h"

/**
 * @summary Add a new node to a certain place in a linked list.
 * The place is determined by the function of comparison given as a parameter
 * @param listnode* head, char* name, int (*cmp_func)(listnode*, listnode*)
 * Head of the linked list, name of the new node, function of comparison
 * @return The head of the modified list
 */

listnode* add_node(listnode* head, listnode* node, int (*cmp_func)(listnode*, listnode*))
{
    listnode* current = head;
    listnode* newnode = NULL;
    listnode* tempnode;
    while (current->next != NULL && cmp_func(current->next, node) < 1)
    {
        current = current->next;
    }
    // check if the function wasn't used incorrectly
    if (current->next != NULL)
    {
        newnode = (listnode*)my_malloc("newnode", sizeof(listnode));
        newnode->name = node->name;
        tempnode = current->next;
        current->next = newnode;
        newnode->next = tempnode;
    }
    // return a error if it didn't find the node
    else
    {
        printf("Node not found : %s\n", node->name);
    }
    return head;
}