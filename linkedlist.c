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

struct song_node * remove_val(struct song_node *list, char nme[], char artst[]){
    struct song_node *current = list;
    struct song_node *prev = current;
    while(current != NULL){
        if(strcmp(artst, current->artist) == 0 && strcmp(nme, current->name) == 0){
            if(current == list){
                list = list->next;
                free(current);
                return list;
            }
            prev->next = current->next;
            free(current);
            current = NULL;
            return list;
        }
        prev = current;
        current = current->next;
    }
    return list;
}

struct song_node * free_list(struct song_node *current) {
    struct song_node* prev = current;
    while(current != NULL) {
        printf("freeing: %s\n", current->name);
        prev = current;
        current = current->next;
        free(prev);
        prev = NULL;
    }
    free(prev);
    prev = NULL;
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
            if (strcmp(list->artist, artst) == 0) return list;
            list = list->next;
        }
        printf("node not found\n");
        return NULL;
}

int findLen(struct song_node *list){
    struct song_node *current = list;
    int x = 0;
    while (current != NULL){
        x++;
        current = current->next;
    }
    return x;
}

//why does each random print out the same number for all three tests on a run?
struct song_node * randomNode(struct song_node *list){
    if(list==NULL) {
        printf("list is empty\n");
        return NULL;
    }
    int len = findLen(list);
    int random = rand() % len;
    //printf("printing element %d of list:\n", random);
    while (random > 0){
        list = list->next;
        random--;
    }
    return list;
}



struct song_node * insertAlphabetical(struct song_node *list, char newname[], char newartist[]){
    if (list == NULL) return insert_front(list, newname, newartist);
    struct song_node *current = list;
    struct song_node *prev = list;
    while(current != NULL && (strcmp(newartist, current->artist)) > 0){
        prev = current;
        current = current->next;
    }
    if(current != NULL && (strcmp(newartist, current->artist) == 0)) {
        while (current != NULL && (strcmp(newname, current->name) > 0)){
            prev = current;
            current = current->next;
        }
    }
    if (current == list) return insert_front(current, newname, newartist);
    current = insert_front(current, newname, newartist);
    prev->next = current;
    return list;
}

