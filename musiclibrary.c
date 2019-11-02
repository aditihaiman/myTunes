#include <stdio.h>
#include <stdlib.h>
#include "musiclibrary.h"
#include "linkedlist.h"

void addSong(struct song_node *newsong, struct song_node * library[27]){
    int place = newsong->artist[0] - 97;
    library[place] = insertAlphabetical(library[place], newsong->name, newsong->artist);
}

void printLetter(struct song_node * library[27], char letter){
    printf("%c list: ", letter);
    print_list(library[letter - 97]);
}

void printLibrary(struct song_node * library[27]) {
    for(int x = 0; x < 27; x++){
        if(library[x] != NULL) print_list(library[x]);
    }
}
