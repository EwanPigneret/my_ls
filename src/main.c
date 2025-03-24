#include "my_ls.h"

int main (int argc, char** argv) {
    int index = 1;
    char* flag = NULL;
    if (argc == 1) {  //./my_ls
        print_folder(".", 0);
    }
    else { 
        while (index < argc) {  // go throught all the arguments
            if (argv[index][0] == '-') {  // if the current arguments is a flag
                if (argv[index + 1] != NULL) {  // checks if there are other parameters 
                    if (argv[index + 1][0] == '-') {  // if the next one is a flag too
                        my_malloc("flag", sizeof(char) * 3);
                        flag = "-at";
                        index += 2;
                    }
                    else {  // define flag as the current parameter
                        flag = my_malloc("flag", sizeof(char) * my_strlen(argv[index]));
                        flag = argv[index];
                        index += 1;
                    }
                }
                else {  // define flag as the current parameter
                    flag = my_malloc("flag", sizeof(char) * my_strlen(argv[index]));
                    flag = argv[index];
                    index += 1;
                }
            }
            if (flag != NULL) {  // if a flag is given
                detect_flag(flag, argv[index]);
            }
            else {  // execute the rest of the code with the current fil
                print_folder(argv[index], 0);
            }
            index += 1;
        }
    }
}