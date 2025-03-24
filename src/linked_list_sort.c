#include "my_ls.h"

listnode* linked_list_sort(listnode* head, int (*cmp_func)(listnode*, listnode*)) {
    listnode* current = head->next;
    listnode* new_head = NULL;
    listnode* new_current = new_head;
    new_head = init_head(current->name);  // initialise the first element of the list
    new_current = new_head;
    current = current->next;
    while (current != NULL) {
        if (cmp_func(current, new_head) == -1) { // the element is smaller than the head
            new_head = add_head(new_head, current->name);
            new_current = new_head;
        }
        else {
            if (current != NULL) {  // the element added wasn't the last one of the unsorted list
                while (new_current->next != NULL && cmp_func(new_current->next, current) != 1) {  // stop at the last element or before an inferior element
                    new_current = new_current->next;
                }
                if (new_current->next == NULL) {  // the element should be at the end of the list
                    new_head = add_end(new_head, current->name);
                }
                else {  // the element should be added in the middle of the list
                    new_head = add_node(new_head, current, cmp_func);
                }
            }
            
        }
        new_current = new_head;
        current = current->next;
    }
    return new_head;
}