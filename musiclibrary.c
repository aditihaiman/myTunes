#include <stdio.h>
#include <stdlib.h>
#include "musiclibrary.h"
#include "linkedlist.h"
#include <string.h>
#include <time.h>

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

void printArtist(struct song_node * library[27], char artst[]){
    struct song_node *first = findArtist(library, artst);
    printf("%s: ", artst);
    while(first != NULL && strcmp(first->artist, artst)==0){
        printf("%s - %s | ", first->artist, first->name);
        first = first->next;
    }
    printf("\n");
}

//DONE
struct song_node * findSong(struct song_node * library[27], char nme[], char artst[]){
    struct song_node *first = library[artst[0] - 97];
    return findNode(first, nme, artst);
}

//DONE
void deleteSong(struct song_node * library[27], char nme[], char artst[]){
    struct song_node *first = library[artst[0] - 97];
    first = remove_val(first, nme, artst);
}

struct song_node * findArtist(struct song_node * library[27], char artst[]){
    struct song_node *first = library[artst[0] - 97];
    return findFirstNode(first, artst);
}

int findSize(struct song_node * library[27]){
  int size = 0;
  for (int x = 0; x < 27; x++)
    size += findLen(library[x]);
  return size;
}


void shuffle(struct song_node * library[27]){
    int size = findSize(library);
    if (size != 0){
        for (int x = 0; x < 27; x++){
            struct song_node *current = library[x];
            int length = findLen(current);
            while (length > 0){
                struct song_node *random = randomNode(current);
                printf("%s - %s | ", random->name, random->artist);
                current = remove_val(current, random->name, random->artist);
                length--;
            }
        }
    }
    printf("\n");
}


void clear(struct song_node * library[27]){
    for(int x = 0; x < 27; x++){
        library[x] = free_list(library[x]);
    }
}
