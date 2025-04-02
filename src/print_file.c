#include "my_ls.h"

/**
 * @summary Create a linked list with the content of a directory,
 * call linked_list_sort to sort it and print it
 * @param char* directory, int flag
 * Directory that is opened to print its content
 */

void print_file(char* directory, int flag)
{
    listnode* head = (listnode*)my_malloc("head", sizeof(listnode));
    head->name = "\0";
    DIR* folder;
    struct dirent* entry;
    folder = opendir(directory);
    entry = readdir(folder);
    while (entry != NULL)
    {
        // directory name isn't null
        if (strcmp(entry->d_name, "\0"))
        {
            // code not compiled with -a
            if (flag % 2 == 0)
            {
                if (entry->d_name[0] != '.')
                {
                    head = insert_element(head, entry->d_name);
                }
            }
            // code compiled with -a
            else
            {
                head = insert_element(head, entry->d_name);
            }
        }
        entry = readdir(folder);
    }
    // code compiled with -t
    if (flag / 2)
    {
        head = linked_list_sort(head, compare_modification);
    }
    // code not compiled with -t
    else
    {
        head = linked_list_sort(head, compare_letter);
    }
    print_linked_list(head);
    closedir(folder);
}