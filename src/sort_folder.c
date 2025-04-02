#include "my_ls.h"

/**
 * @summary Sort a linked list, the sort is intendified using the flag
 * @param listnode* head, int flag
 * Head of the linked list, converted value ofthe flags
 * @return The head of the modified list
 */

listnode* sort_folder(listnode* head_folder, int flag)
{
    if (linked_list_length(head_folder) > 1)
    {
        if (flag / 2)
        {
            head_folder = linked_list_sort(head_folder, compare_modification);
        }
        else
        {
            head_folder = linked_list_sort(head_folder, compare_letter);
        }
    }
    return head_folder;
}