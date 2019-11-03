#include "linkedlist.h"


void addSong(struct song_node *newsong, struct song_node * library[27]);
void printLetter(struct song_node * library[27], char letter);
void printArtist(struct song_node * library[27], char artst[]);
void printLibrary(struct song_node * library[27]);
struct song_node * findSong(struct song_node * library[27], char nme[], char artst[]);
struct song_node * findArtist(struct song_node * library[27], char artst[]);
void deleteSong(struct song_node * library[27], char nme[], char artst[]);
