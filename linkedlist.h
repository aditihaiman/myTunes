struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};


void print_list(struct song_node *current);
struct song_node * insert_front(struct song_node *front, char newname[], char newartist[]);
struct song_node * remove_val(struct song_node *front, int data);
struct song_node * free_list(struct song_node *current);
struct song_node * findNode(struct song_node *list, char nme[], char artst[]);
struct song_node * findFirstNode(char artst[]);
struct song_node * randomNode();
struct song_node * createNode(char newname[], char newartist[]);
struct song_node * insertAlphabetical(struct song_node *front, char newname[], char newartist[]);
