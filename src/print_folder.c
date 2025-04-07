#include <my_ls.h>

/**
 * @summary Sort a linked list containing all the folders and
 * call print_file to print their content
 * @param listnode* head_folder, int flag
 * Head of the linked list with the folders, converted value of the flags
 */

void print_folder(listnode* head_folder, int flag, char* path)
{
    // sort the folder by the appropriate order
    head_folder = sort_folder(head_folder, flag, path);
    listnode* current = head_folder;
    int nb_files = 0;
    // if there's more than one directory
    if (linked_list_length(head_folder) > 1)
    {
        while (current != NULL)
        {
            // if it's not the first directory printed
            if (nb_files > 0)
            {
                printf("\n");
            }
            printf("%s:\n", current->name);
            print_file(current->name, flag);
            nb_files += 1;
            current = current->next;
        }
    }
    else
    {
        while (current != NULL)
        {
            print_file(current->name, flag);
            current = current->next;
        }
    }
}