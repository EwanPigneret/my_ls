#include "my_ls.h"

/**
 * @summary detect which flag was used
 * @param char* flags - String where the flags are stored
 * @result The value of the flags converted into an int
 */

int detect_flag(char* flags) {
    if (!strcmp(flags, "-a")) {  // flag -a
        return 1;
    }
    else if (!strcmp(flags, "-t")) {  // flag -t
        return 2;
    }
    else if (!strcmp(flags, "-at") || !strcmp(flags, "-ta")) {  // flag -at
        return 3;
    }
    else if (!strcmp(flags, "")) {
        return 0;
    }
    else {  // the flag used isn't valid
        printf("Error, flag invalid : %s\n", flags);
        return -1;
    }
}