#include "my_ls.h"

/**
 * @summary Sort a linked list with a comparison function
 * @param listnode* head, int (*cmp_func)(listnode*, listnode*)
 * Head of the linked list, function of comparison
 * @result Returns the modified linked list
 */

listnode* linked_list_sort(listnode* head, int (*cmp_func)(listnode*, listnode*))
{
    listnode* current = head;
    // checks for error
    if (current->name[0] == 0)
    {
        current = current->next;
    }
    listnode* new_head = (listnode*)my_malloc("head", sizeof(listnode));
    new_head->name = current->name;
    new_head->last_modif = current->last_modif;
    listnode* new_current = new_head;
    // initialise the first element of the list
    current = current->next;
    while (current != NULL)
    {
        // the element is smaller than the head
        if (cmp_func(current, new_head) == -1)
        {
            new_head = add_head(new_head, current->name, current->last_modif);
            new_current = new_head;
        }
        else
        {
            // the element added wasn't the last one of the unsorted list
            if (current != NULL)
            {
                // stop at the last element or before an inferior element
                while (new_current->next != NULL && cmp_func(new_current->next, current) != 1)
                {
                    new_current = new_current->next;
                }
                // the element should be at the end of the list
                if (new_current->next == NULL)
                {
                    new_head = add_end(new_head, current->name, current->last_modif);
                }
                // the element should be added in the middle of the list
                else
                {
                    new_head = add_node(new_head, current, cmp_func, current->last_modif);
                }
            }
        }
        new_current = new_head;
        current = current->next;
    }
    return new_head;
}
