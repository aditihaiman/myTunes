#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "linkedlist.h"
#include "musiclibrary.h"

int main(){
    struct song_node *list = NULL;
    printf("TESTING LINKEDLIST\n");
    
    printf("\n===========================================================\n");
    
    printf("\nTesting empty print_list:\n\n");
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
    
    printf("\n===========================================================\n");
    
    printf("\nTesting findNode:\n\n");
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
    
    printf("\n===========================================================\n");
    
    printf("\nTesting find first node by artist:\n\n");
    printf("looking for [the beatles]:\n");
    find = findFirstNode(list, artist);
    printf("%s - %s\n", find->artist, find->name);
    printf("looking for [abba]:\n");
    strcpy(artist, "abba");
    find = findFirstNode(list, artist);
    printf("%s - %s\n", find->artist, find->name);


    printf("\n===========================================================\n");

    printf("\nTesting remove by value:\n\n");
    printf("Removing from front [queen - killer queen]: \n");
    strcpy(artist, "queen");
    strcpy(name, "killer queen");
    list = remove_val(list, name, artist);
    print_list(list);
    printf("Removing from middle [the beatles - rocky raccoon]: \n");
    strcpy(artist, "the beatles");
    strcpy(name, "rocky raccoon");
    list = remove_val(list, name, artist);
    print_list(list);
    printf("Removing from end [the beatles - penny lane]: \n");
    strcpy(artist, "the beatles");
    strcpy(name, "penny lane");
    list = remove_val(list, name, artist);
    print_list(list);
    printf("Removing all values: \n");
    strcpy(artist, "the beatles");
    strcpy(name, "hey jude");
    list = remove_val(list, name, artist);
    strcpy(artist, "abba");
    strcpy(name, "fernando");
    list = remove_val(list, name, artist);
    print_list(list);
    list = NULL;
    
    printf("\n===========================================================\n");

    printf("\nTesting insert alphabetical:\n\n");
    printf("Inserting [the beatles - hello goodbye]:\n");
    strcpy(artist, "the beatles");
    strcpy(name, "hello, goodbye");
    list = insertAlphabetical(list, name, artist);
    print_list(list);
    printf("\nInserting [the beatles - maxwells silver hammer]:\n");
    strcpy(artist, "the beatles");
    strcpy(name, "maxwells silver hammer");
    list = insertAlphabetical(list, name, artist);
    print_list(list);
    printf("\nInserting [elton john - tiny dancer]:\n");
    strcpy(artist, "elton john");
    strcpy(name, "tiny dancer");
    list = insertAlphabetical(list, name, artist);
    print_list(list);
    printf("\nInserting [queen - killer queen]:\n");
    strcpy(artist, "queen");
    strcpy(name, "killer queen");
    list = insertAlphabetical(list, name, artist);
    print_list(list);
    printf("\nInserting [the temptations - my girl]:\n");
    strcpy(artist, "the temptations");
    strcpy(name, "my girl");
    list = insertAlphabetical(list, name, artist);
    print_list(list);

    printf("\n===========================================================\n");

    printf("\nTesting random node:\n\n");
    struct song_node *randNode = NULL;
    randNode = (randomNode(list));
    printf("%s - %s\n", randNode->artist, randNode->name);

    
    printf("\n===========================================================\n");

    printf("\nTesting free_list:\n\n");
    list = free_list(list);
    print_list(list);
    
    
    printf("\n===========================================================\n");

    printf("TESTING MUSIC LIBRARY\n");
    
    printf("\n===========================================================\n");
    
    printf("\nTesting printLibrary:\n\n");

    
    struct song_node * library[27];
    for(int x = 0; x < 27; x++){
        library[x] = NULL;
    }
    struct song_node *new = createNode(name, artist);
    addSong(new, library);
    strcpy(artist, "billy joel");
    strcpy(name, "uptown girl");
    new = createNode(name, artist);
    addSong(new, library);
    strcpy(artist, "david bowie");
    strcpy(name, "starman");
    new = createNode(name, artist);
    addSong(new, library);
    strcpy(artist, "billy joel");
    strcpy(name, "vienna");
    new = createNode(name, artist);
    addSong(new, library);
    printLibrary(library);
    
    printf("\n");
    printLetter(library, 'b');
    
}
