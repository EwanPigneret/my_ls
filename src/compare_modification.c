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
    // return which one has been modified first between the 2
    if (current->last_modif->st_mtime < next->last_modif->st_mtime)
    {
        return 1;
    }
    // if they are equals sort the by nanoseconds and if also equeals sort by alphabetical order
    else if (current->last_modif->st_mtime == next->last_modif->st_mtime)
    {
        if (current->last_modif->st_mtim.tv_nsec < next->last_modif->st_mtim.tv_nsec)
        {
            return 1;
        }
        else if (current->last_modif->st_mtim.tv_nsec == next->last_modif->st_mtim.tv_nsec)
        {
            return compare_letter(current, next);
        }
    }
    return -1;
}
