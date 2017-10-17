#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song_node.h"

void print_list (struct song_node * curr_node) {
  //printf("[");
  while (curr_node) { //while there is another node after, print value then proceed to next
    printf("Artist: %s\t Song: %s\n", curr_node -> artist, curr_node -> name);
    curr_node = curr_node -> next;
  }
}

struct song_node * insert_front (struct song_node * exist_node, char * Title, char * Singer) {
  struct song_node *add = malloc (sizeof (struct song_node)); //allocate memory for new node
  add -> name = Title; //initialize node
    add -> artist = Singer; 
  add -> next = exist_node;
  return add;
}


struct song_node * free_list(struct song_node * start){
  struct song_node * temp;

  while (start -> next) {
    temp = start;
    start = temp -> next;
    free (temp);
  }
  free(start); //free last node
  return NULL;
}

struct song_node * create_link(char * Title, char * Singer){ //in order to initialize first element
  struct song_node * end = malloc(sizeof(struct song_node));
  end -> name = Title;
    end -> artist = Singer;
  end -> next = NULL;
  return end;
}

struct song_node * insert_order(song_node * exist_node, char * Title, char * Singer) {
  struct song_node *add = malloc (sizeof( struct song_node));
    struct song_node *temp = malloc (sizeof( struct song_node));
  add -> name = Title;
  add -> artist = Singer;
  while (strcmp(Singer, exist_node -> artist) < 0 ||
	 strcmp(Title, exist_node -> name) < 0) {//while artist/song smaller
    temp = exist_node;
    exist_node = exist_node -> next;
  }
  temp -> next = add;
  add -> next = exist_node;
    return add;
}

int main(){
    song_node * y = create_link("Skyfall", "Adele");
    print_list(y);
    printf("\n");
    y = insert_front(y, "Symphony 40", "Mozart");
    print_list(y);
    printf("\n");
    y = insert_order(y, "Uptown Girl", "Billy Joel");
    y = insert_order(y, "asdf", "Casdf");
    y = insert_order(y, "sd", "Asdf");
    print_list(y);
    
    return 0;
    
}