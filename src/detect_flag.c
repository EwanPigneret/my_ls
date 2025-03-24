#include "my_ls.h"

void detect_flag(char* flags, char* file) {  // detect which flag was used
    if (!strcmp(flags, "-a")) {  // flag -a
        if(file != NULL) {  // my_ls is compiled with a file
            print_folder(file, 1);
        }
        else {  // define the folder "." as the default directory
            print_folder(".", 1);
        }
    }
    else if (!strcmp(flags, "-t")) {  // flag -t
        if(file != NULL) {  // my_ls is compiled with a file
            print_folder(file, 2);
        }
        else {  // define the folder "." as the default directory
            print_folder(".", 2);
        }
    }
    else if (!strcmp(flags, "-at") || !strcmp(flags, "-ta")) {  // flag -at
        if(file != NULL) {  // my_ls is compiled with a file
            print_folder(file, 3);
        }
        else {  // define the folder "." as the default directory
            print_folder(".", 3);
        }
    }
    else {  // the flag used isn't valid
        printf("Error, flag invalid : %s\n", flags);
    }
}