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

//NOT DONE
struct song_node * findSong(struct song_node * library[27], char nme[], char artst[]){
  for (int x = 0; x < 27; x++){
    printf("A\n");
    struct song_node * current = library[x];
    if (current->artist == artst && current->name == nme){
      printf("B\n");
      printf("song found!");
      return current;
    }
  }
  printf("song not found");
  return NULL;
}

//NOT DONE
struct song_node * deleteSong(struct song_node * library[27], char nme[], char artst[]){
  int next = 0;
  for (int x = 0; x < 27; x++){
    next = x+1;
    struct song_node * currentNode = library[x];
    if (currentNode->artist == artst && currentNode->name == nme){
      int current = x;
      while (current < 27){
	library[next++] = library[current++];
      }
      free(currentNode);
      printLibrary(library);
      return NULL;
    }
  }
  printf("song not found");
  return NULL;
}
