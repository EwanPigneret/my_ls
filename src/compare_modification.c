#include "my_ls.h"

/**
 * @summary Check which of 2 given files/directory as been modified first
 * @param listnode* current, listnode* next - Node that is compared to the next one
 * @return -1 if current has been modified first, 1 if the next one as been modified first
 */

int compare_modification(listnode* current, listnode* next) {
    struct stat* stat_current;
    stat_current = (struct stat*) my_malloc("stat_current", sizeof(struct stat));
    struct stat* stat_next;
    stat_next = (struct stat*) my_malloc("stat_next", sizeof(struct stat));
    printf("file : %s\n", current->name);
    printf("next file : %s\n", current->next->name);
    if (stat(current->name, stat_current) == -1) {  // check if the initialisation failed
        printf("Test : %s\n", current->name);
        perror("stat current");
        exit(EXIT_FAILURE);
    }
    if (stat(next->name, stat_next) == -1) {  // check if the initialisation failed
        printf("Test : %s\n", current->next->name);
        perror("stat next");
        exit(EXIT_FAILURE);
    }
    if (stat_current->st_mtime < stat_next->st_mtime) {  // return which one has been modified first between the 2
        return 1;
    }
    else if (stat_current->st_mtime == stat_next->st_mtime) {
        return compare_letter(current, next);
    }
    return -1;
}
