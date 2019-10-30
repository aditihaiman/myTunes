#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "string.h"
#include "linkedlist.h"


void print_list(struct song_node *current) { //DONE
        printf("[");
        while(current != NULL) {
            printf("%s - %s", current->artist, current->name);
            current = current->next;
            if(current!=NULL) printf(", ");
        }
        printf("]\n");
}

struct song_node * createNode(char newname[], char newartist[]){ //DONE
    struct song_node *new = (struct song_node*)malloc(sizeof(struct song_node));
    for(int x = 0; x < strlen(newname); x++){
        new->name[x] = newname[x];
    }
    for(int x = 0; x < strlen(newartist); x++){
        new->artist[x] = newartist[x];
    }
    new->next = NULL;
    return new;
}

struct song_node * insert_front(struct song_node *front, char newname[], char newartist[]){ //DONE
    struct song_node *new = createNode(newname, newartist);
    new->next = front;
    return new;
}

struct song_node * remove_val(struct song_node *front, int data){
    struct song_node *current = front;
    struct song_node *prev = current;
    while(current != NULL){
        if(current->name == data){
            if(current == front) front = front->next;
            else prev->next = current->next;
            free(current);
            current = NULL;
            return front;
        }
        prev = current;
        current = current->next;
    }
    return front;
}

struct song_node * free_list(struct song_node *current) {
    struct song_node* prev;
    while(current != NULL) {
        printf("freeing: %d\n", current->name);
        prev = current;
        current = current->next;
        free(prev);
        prev = NULL;
    }
    return prev;
}


struct song_node * findNode(struct song_node *list, char nme[], char artst[]){ //DONE
    while(list != NULL) {
        if ((strcmp(list->name, nme) == 0) &&  (strcmp(list->artist, artst) == 0)) return list;
        list = list->next;
    }
    printf("node not found\n");
    return NULL;
}

struct song_node * findFirstNode(struct song_node *list, char artst[]){
    while(list != NULL) {
            if (strcmp(list->name, nme) == 0) return list;
            list = list->next;
        }
        printf("node not found\n");
        return NULL;
}

int findLen(struct song_node *list){
  int x = 0;
  while (list != NULL){
    x++;
    list = list->next;
  }
  return x;
}

struct song_node * randomNode(struct song_node *list){
  srand(time(NULL));
  int len = findLen(list);
  int rand = rand() % lenArtist;
  while (rand >= 0){
    list = list->next;
    rand--;
  }
  printf("printing element %d of list:\n", rand);
  return list;
}



struct song_node * insertAlphabetical(struct song_node *list, char newname[], char newartist[]){
  while (list != NULL){
    if (strcmp(newartist, list->artist) == 0){
      while (strcmp(newname, list->name) > 0)
	list = list->next;
      
    while (strcmp(newartist, list->artist) > 0)
      list = list->next;
      
 insert_front(list, newname, newartist);
}

