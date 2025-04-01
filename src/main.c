#include "my_ls.h"

/**
 * @summary 
 * @param
 * @return
 */

int main (int argc, char** argv) {
    listnode* head_folders = (listnode*) my_malloc("head_folders", sizeof(listnode));
    char* flag = my_malloc("flag", sizeof(char) * 3);
    int index = 1;
    int val_flag = 0;
    if (argc == 1) {  //./my_ls
        print_file(".", 0);
    }
    else { 
        while (index < argc) {  // go throught all the arguments
            if (argv[index][0] == '-') {  // if the current arguments is a flag
                if (argv[index + 1] != NULL && argv[index + 1][0] == '-') {  // checks if there are other parameters 
                    flag = "-at";
                    index += 2;
                }
                else {  // define flag as the current parameter
                    flag = argv[index];
                    index += 1;
                }
            }
            if (index < argc) {
                if (head_folders->name == NULL) {
                    head_folders = init_head(argv[index]);
                }
                else {
                    insert_element(head_folders, argv[index]);
                }
                index += 1;
            }
        }
        if (head_folders->name != NULL) {
            print_folder(head_folders, detect_flag(flag));
        }
        else {
            val_flag = detect_flag(flag);
            print_file(".", val_flag);
        }
    }
}
