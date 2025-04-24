#include "my_ls.h"

/**
 * @summary Main of the function, detects the flags and directory
 * @param int argc, char** argv
 * Number of arguments, array with each arguments inside
 */

int main(int argc, char** argv)
{
    listnode* head_folders = (listnode*)my_malloc("head_folders", sizeof(listnode));
    char* flag = my_malloc("flag", sizeof(char) * 3);
    int index = 1;
    int val_flag = 0;
    //./my_ls
    if (argc == 1)
    {
        print_file(".", 0);
    }
    else
    {
        // go throught all the arguments
        while (index < argc)
        {
            // if the current arguments is a flag
            if (argv[index][0] == '-')
            {
                // checks if there are other parameters
                if ((argv[index + 1] != NULL) && (argv[index + 1][0] == '-'))
                {
                    flag = "-at";
                    index += 2;
                }
                // define flag as the current parameter
                else
                {
                    flag = argv[index];
                    index += 1;
                }
            }
            // checks if the last argument wasn't a flag
            if (index < argc)
            {
                // create a linked list with all the directory
                if (head_folders->name == NULL)
                {
                    head_folders = init_head(argv[index], "./");
                }
                else
                {
                    insert_element(head_folders, argv[index], "./");
                }
                index += 1;
            }
        }
        if (head_folders->name != NULL)
        {
            print_folder(head_folders, detect_flag(flag));
        }
        // if no directory were found
        else
        {
            val_flag = detect_flag(flag);
            print_file(".", val_flag);
        }
    }
}
