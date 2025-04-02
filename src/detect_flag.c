#include "my_ls.h"

/**
 * @summary Detect which flag was used
 * @param char* flags - String where the flags are stored
 * @result The value of the flags converted into an int
 */

int detect_flag(char* flags)
{
    // flag -a
    if (!strcmp(flags, "-a"))
    {
        return 1;
    }
    // flag -t
    else if (!strcmp(flags, "-t"))
    {
        return 2;
    }
    // flag -at
    else if (!strcmp(flags, "-at") || !strcmp(flags, "-ta"))
    {
        return 3;
    }
    // no flag given
    else if (!strcmp(flags, ""))
    {
        return 0;
    }
    // the flag used isn't valid
    else
    {
        printf("Error, flag invalid : %s\n", flags);
        return -1;
    }
}