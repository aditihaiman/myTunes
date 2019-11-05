#include <stdio.h>
#include <stdlib.h>
#include "musiclibrary.h"
#include "linkedlist.h"
#include <string.h>
#include <time.h>

void addSong(struct song_node *newsong, struct song_node * library[27]){
    int place;
    if (newsong->artist[0] < 97 || newsong->artist[0] > 122) place = 26;
    else place = newsong->artist[0] - 97;
    printf("%d\n", place);
    library[place] = insertAlphabetical(library[place], newsong->name, newsong->artist);
}

void printLetter(struct song_node * library[27], char letter){
    int place;
    if (letter < 97 || letter > 122) place = 26;
    else place = letter - 97;
    printf("%c list: ", letter);
    print_list(library[place]);
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
    struct song_node *first;
    if (artst[0] < 97 || artst[0] > 122) first = library[26];
    else first = library[artst[0] - 97];
    return findNode(first, nme, artst);
}

//DONE
void deleteSong(struct song_node * library[27], char nme[], char artst[]){
    struct song_node *first;
    if (artst[0] < 97 || artst[0] > 122) first = library[26];
    else first = library[artst[0] - 97];
    first = remove_val(first, nme, artst);
}

struct song_node * findArtist(struct song_node * library[27], char artst[]){
    struct song_node *first;
    if (artst[0] < 97 || artst[0] > 122) first = library[26];
    else first = library[artst[0] - 97];
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
            struct song_node *current = library[rand()%27];
            int length = findLen(current);
            while (length > 0){
                struct song_node *random = randomNode(current);
                printf("%s - %s | ", random->name, random->artist);
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
