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
    strcpy(name, "hey jude");
    list = insert_front(list, name, artist);
    strcpy(name, "rocky raccoon");
    list = insert_front(list, name, artist);
    strcpy(artist, "abba");
    strcpy(name, "fernando");
    list = insert_front(list, name, artist);
    strcpy(artist, "queen");
    strcpy(name, "killer queen");
    list = insert_front(list, name, artist);
    print_list(list);
    
    printf("===========================================================\n");
    
    printf("Testing findNode:\n");
    struct song_node *find = NULL;
    strcpy(artist, "the beatles");
    strcpy(name, "penny lane");
    find = findNode(list, name, artist);
    printf("looking for [the beatles - penny lane]:\n");
    printf("%s - %s\n", find->artist, find->name);
    printf("looking for [the beatles - hey jude]:\n");
    strcpy(name, "hey jude");
    find = findNode(list, name, artist);
    printf("%s - %s\n", find->artist, find->name);
    printf("looking for [the beatles - back in the ussr]:\n");
    strcpy(name, "back in the ussr");
    find = findNode(list, name, artist);
    
    printf("===========================================================\n");
    
    printf("Testing find first node by artist:\n");
    printf("looking for [the beatles]:\n");
    find = findFirstNode(list, artist);
    printf("%s - %s\n", find->artist, find->name);
    printf("looking for [abba]:\n");
    strcpy(artist, "abba");
    find = findFirstNode(list, artist);
    printf("%s - %s\n", find->artist, find->name);


    printf("===========================================================\n");

    printf("Testing insert alphabetical:\n");
    strcpy(artist, "the beatles");
    strcpy(name, "hello, goodbye");
    struct song_node *current = list;
    print_list(current);
    current = insertAlphabetical(current, name, artist);
    print_list(current);

    
}
