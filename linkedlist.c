#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


void print_list(struct song_node *current) {
        printf("[");
        while(current != NULL) {
            printf("%s: %s", current->artist, current->name);
            current = current->next;
            if(current!=NULL) printf(",");
        }
        printf("]\n");
}

struct song_node * createNode(char[] newname, char[] newartist){
    struct song_node *new = (struct song_node*)malloc(sizeof(struct song_node));
    new->name = newname;
    new->artist = newartist;
    new->next = NULL;
    return new;
}

struct song_node * insert_front(struct song_node *front, char[] newname, char[] newartist){
    struct song_node *new = createNode(newname, newartist);
    new->next = front;
    return new;
}

struct song_node * remove_val(struct song_node *front, int data){
    struct song_node *current = front;
    struct song_node *prev = current;
    while(current != NULL){
        if(current->i == data){
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
        printf("freeing: %d\n", current->i);
        prev = current;
        current = current->next;
        free(prev);
        prev = NULL;
    }
    return prev;
}


struct song_node * findNode(char[] nme, char[] artst){
    
}

struct song_node * findFirstNode(char[] artst){
    
}

struct song_node * randomNode(){
    
}

struct song_node * insertAlphabetical(struct song_node *front, char[] newname, char[] newartist){
    
}

