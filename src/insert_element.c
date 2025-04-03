#include "my_ls.h"

/**
 * @summary Insert a newnode at the end of the list with the given value
 * @param listnode* head, char* folder_name
 * Head of the linked list, name of the new node
 * @return Head of the modified linked list
 */

listnode* insert_element(listnode* head, char* folder_name)
{
    struct stat* stat_node = (struct stat*)my_malloc("stat_node", sizeof(struct stat));
    if (stat(concatenation_string("temp", folder_name), stat_node) == -1)
    {
        perror("stat node");
        exit(EXIT_FAILURE);
    }
    listnode* new_node = (listnode*)my_malloc("new_node", sizeof(listnode));
    new_node->name = folder_name;
    new_node->last_modif = stat_node->st_mtim.tv_nsec;
    listnode* current = head;
    // goes to the end of the linked list
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = new_node;
    current->next->next = NULL;
    return head;
}