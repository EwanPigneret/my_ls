#include "my_ls.h"

listnode* print_folder(char* directory, int flag) {  // create a linked list with all the next folders and files from a directory
    listnode* head = (listnode*) my_malloc("head", sizeof(listnode));
    DIR* folder = opendir(directory);
    struct dirent* entry = readdir(folder);
    while (entry != NULL) {
        if (strcmp(entry->d_name, "")) {  // directory name isn't null
            if (flag % 2 == 0) {  // code not compiled with -a
                if (entry->d_name[0] != '.') {
                    head = insert_element(head, entry->d_name);
                }
            } 
            else {  //  code compiled with -a
                head = insert_element(head, entry->d_name);
            }
        }
        entry = readdir(folder);
    }
    if (flag / 2 == 1) {  // code compiled with -t
        head = linked_list_sort(head, compare_modification);
    }
    else {  // code not compiled with -t
        head = linked_list_sort(head, compare_letter);
    }
    print_linked_list(head);
    closedir(folder);
    return head;
}