#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "linkedlist.h"
#include "musiclibrary.h"

int main(){
    struct song_node *list = NULL;
    printf("TESTING LINKEDLIST\n");
    printf("===========================================================\n");
    printf("Testing empty print_list:\n");
    print_list(list);
    printf("Testing print_list with insert_front:\n");
    char name[100] = "penny lane";
    char artist[100] = "the beatles";
    list = insert_front(list, name, artist);
    char name1[100] = "hey jude";
    list = insert_front(list, name1, artist);
    char name2[100] = "rocky raccoon";
    list = insert_front(list, name2, artist);
    print_list(list);
    printf("===========================================================\n");
    printf("Testing findNode:\n");
    struct song_node *find = NULL;
    find = findNode(list, name, artist);
    printf("looking for [the beatles - penny lane]:\n");
    printf("%s - %s\n", find->artist, find->name);
    printf("looking for [the beatles - hey jude]:\n");
    find = findNode(list, name1, artist);
    printf("%s - %s\n", find->artist, find->name);
    printf("looking for [the beatles - back in the ussr]:\n");
    char name3[100] = "back in the ussr";
    find = findNode(list, name3, artist);
    printf("===========================================================\n");


    
}
