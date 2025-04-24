#include "my_ls.h"

/**
 * @summary Insert a newnode at the end of the list with the given value
 * @param listnode* head, char* elem_name
 * Head of the linked list, name of the new node
 * @return Head of the modified linked list
 */

listnode* insert_element(listnode* head, char* elem_name, char* path)
{
    struct stat* stat_node = (struct stat*)my_malloc("stat_node", sizeof(struct stat));
    listnode* new_node = (listnode*)my_malloc("new_node", sizeof(listnode));
    new_node->name = elem_name;
    if (elem_name[0] != '/')
    {	    
        elem_name = concatenation_string(path, elem_name, elem_name);
    }
    if (stat(elem_name, stat_node) == -1)
    {
        perror("stat node");
        exit(EXIT_FAILURE);
    }
    new_node->last_modif = stat_node;
    listnode* current = head;
    // gestion of an error
    if (!strcmp(head->name, ""))
    {
        head = new_node;
        return head;
    }
    // goes to the end of the linked list
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
    current->next->next = NULL;
    return head;
}
