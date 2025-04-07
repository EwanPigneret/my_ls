#include "my_ls.h"

/**
 * @summary Initialize the head of a linked list
 * @param char* head_name - Value given to the head
 * @return The head that has beeen initialised
 */

listnode* init_head(char* head_name, char* path)
{
    struct stat* stat_head = (struct stat*)my_malloc("stat_head", sizeof(struct stat));
    listnode* head = (listnode*)my_malloc("head", sizeof(listnode));
    if (stat(concatenation_string(path, head_name), stat_head) == -1)
    {
        perror("stat head");
        exit(EXIT_FAILURE);
    }
    head->last_modif = stat_head->st_mtim.tv_nsec;
    head->name = head_name;
    head->next = NULL;
    return head;
}