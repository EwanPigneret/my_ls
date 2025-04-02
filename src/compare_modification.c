#include "my_ls.h"

/**
 * @summary Check which of 2 given files/directory as been modified first
 * @param listnode* current, listnode* next
 * Node that is compared to the nextone
 * @return -1 if current has been modified first,
 * 1 if the next one as been modified first
 */

int compare_modification(listnode* current, listnode* next)
{
    struct stat* stat_current;
    stat_current = (struct stat*)my_malloc("stat_current", sizeof(struct stat));
    struct stat* stat_next;
    stat_next = (struct stat*)my_malloc("stat_next", sizeof(struct stat));
    // check if the initialisation failed
    if (stat(current->name, stat_current) == -1)
    {
        perror("stat current");
        exit(EXIT_FAILURE);
    }
    if (stat(next->name, stat_next) == -1)
    {
        perror("stat next");
        exit(EXIT_FAILURE);
    }
    // return which one has been modified first between the 2
    if (stat_current->st_mtime < stat_next->st_mtime)
    {
        return 1;
    }
    // if they are equals sort the by alphabetical order
    else if (stat_current->st_mtime == stat_next->st_mtime)
    {
        return compare_letter(current, next);
    }
    return -1;
}