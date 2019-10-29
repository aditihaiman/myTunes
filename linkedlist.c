#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"


void print_list(struct node *current) {
        printf("[");
        while(current != NULL) {
            printf("%d", current->i);
            current = current->next;
            if(current!=NULL) printf(",");
        }
        printf("]\n");
}

struct node * insert_front(struct node *front, int val){
    struct node *new;
    new = (struct node*)malloc(sizeof(struct node));
    new->i = val;
    new->next = front;
    return new;
}

struct node * remove_val(struct node *front, int data){
    struct node *current = front;
    struct node *prev = current;
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

struct node * free_list(struct node *current) {
    struct node* prev;
    while(current != NULL) {
        printf("freeing: %d\n", current->i);
        prev = current;
        current = current->next;
        free(prev);
        prev = NULL;
    }
    return prev;
}
