#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
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
    struct s_listnode* next;
} listnode;
#endif

listnode* add_end(listnode*, char*);
listnode* add_head(listnode*, char*);
listnode* add_node(listnode*, listnode*, int (*cmp_func)(listnode*, listnode*));
char* binary_to_text(int);
int compare_letter(listnode*, listnode*);
int compare_modification(listnode*, listnode*);
int detect_flag(char*);
listnode* init_head(char*);
listnode* insert_element(listnode*, char*);
int linked_list_length(listnode*);
listnode* linked_list_sort (listnode*, int (*cmp_func) (listnode*, listnode*));
int main(int, char**);
void* my_malloc(char*, size_t);
int my_strlen(char*);
void print_folder(listnode*, int);
void print_file(char*, int);
void print_linked_list(listnode*);
listnode* sort_folder(listnode*, int);
