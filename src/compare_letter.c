#include "my_ls.h"

/**
 * @summary Return if two files/directory are in alphabetical order
 * @param listnode* current, listnode* next - Node that is compared to the next one
 * @return -1 if current < next, 1 if current > next
 */

int compare_letter(listnode* current, listnode* next) {  
    int index = 0;
    while (current->name[index] != '\0' && next->name[index] != '\0' && current->name[index] == next->name[index]) {  // go throught the 2 strings until it's the end of one of them or the two letters aren't the same
        index += 1;
    }
    if (current->name[index] != '\0' && current->name[index] != '\0') {  // if the two linked list aren't the same until the end of one of them
        if (current->name[index] < next->name[index]) {  // compare the letter where the loop stopped and returns which one is the smallest
            return -1;
        }
        else {
            return 1;
        }
    }
    else if (current->name[index] == '\0') {  // if the two linked list are the same until the end of one of them, returns which one is the smallest
        return -1;
    }
    else {
        return 1;
    }
}