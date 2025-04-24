#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <unistd.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#ifndef STRUCT_LISTNODE
#define STRUCT_LISTNODE
typedef struct s_listnode
{
    char* name;
    struct stat* last_modif;
    struct s_listnode* next;
} listnode;
#endif

listnode* add_end(listnode*, char*, struct stat*);
listnode* add_head(listnode*, char*, struct stat*);
listnode* add_node(listnode*, listnode*, int (*cmp_func)(listnode*, listnode*), struct stat*);
int compare_letter(listnode*, listnode*);
int compare_modification(listnode*, listnode*);
char* concatenation_string(char*, char*, char*);
int detect_flag(char*);
listnode* init_head(char*, char*);
listnode* insert_element(listnode*, char*, char*);
int linked_list_length(listnode*);
listnode* linked_list_sort (listnode*, int (*cmp_func) (listnode*, listnode*));
int main(int, char**);
void* my_malloc(char*, size_t);
int my_strlen(char*);
void print_folder(listnode*, int);
void print_file(char*, int);
void print_linked_list(listnode*);
listnode* sort_folder(listnode*, int);
