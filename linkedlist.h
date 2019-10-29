struct song_node{
  char name[100];
  char artist[100];
  struct song_node *next;
};


void print_list(struct node *current);
struct node * insert_front(struct node *front, int val);
struct node * remove_val(struct node *front, int data);
struct node * free_list(struct node *current);
