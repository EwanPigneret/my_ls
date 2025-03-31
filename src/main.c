#include "my_ls.h"

/**
 * @summary
 * @param
 * @return
 */

int main (int argc, char** argv) {
    int index = 1;
    int nb_files = 0;
    char* flag = my_malloc("flag", sizeof(char) * 3);
    if (argc == 1) {  //./my_ls
        print_folder(".", 0);
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
            if (argv[index + 1] != NULL && nb_files == 0) {
                printf("%s : \n", argv[index]);
            }
            if (nb_files > 0) {
                printf("%s : \n", argv[index]);
            }
            if (strcmp(flag, "\0")) {  // if a flag is given
                detect_flag(flag, argv[index]);
                nb_files += 1;
            }
            else {  // execute the rest of the code with the current file
                print_folder(argv[index], 0);
                nb_files += 1;
            }
            index += 1;
        }
    }
}
