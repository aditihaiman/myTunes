#include <stdio.h>
#include <stdlib.h>
#include "musiclibrary.h"
#include "linkedlist.h"

void addSong(struct song_node *newsong, struct song_node * library[27]){
    int place = newsong->artist[0] - 97;
    library[place] = insertAlphabetical(library[place], newsong->name, newsong->artist);
}

