#include "my_ls.h"

/**
 * @summary Return if two files/directory are in alphabetical order
 * @param listnode* current, listnode* next
 * Node that is compared to the next one
 * @return -1 if current < next, 1 if current > next
 */

int compare_letter(listnode* current, listnode* next)
{
    int index = 0;
    // go throught the 2 strings until two letters are differents
    while (current->name[index] != '\0' && next->name[index] != '\0' && current->name[index] == next->name[index])
    {
        index += 1;
    }
    // if the two linked list aren't the same until the end of one of them
    if (current->name[index] != '\0' && current->name[index] != '\0')
    {
        // compare the two letters and returns which one is the smallest
        if (current->name[index] < next->name[index])
        {
            return -1;
        }
        else
        {
            return 1;
        }
    }
    // if the two linked list are similar until the end of one of them,
    // returns which one is the smallest
    else if (current->name[index] == '\0')
    {
        return -1;
    }
    else
    {
        return 1;
    }
}