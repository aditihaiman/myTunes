#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "linkedlist.h"
#include "musiclibrary.h"

int main(){
    struct song_node *list = NULL;
    printf("===========================================================\n");
    printf("TESTING LINKEDLIST\n");
    printf("===========================================================\n");
    printf("Testing empty print_list:\n");
    print_list(list);
    printf("Testing print_list:\n");
    char name[100] = "penny lane";
    char artist[100] = "the beatles";
    list = insert_front(list, name, artist);
    char name1[100] = "hey jude";
    list = insert_front(list, name1, artist);
    print_list(list);
    
    
}
