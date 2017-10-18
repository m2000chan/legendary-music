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

struct song_node * insert_front (struct song_node * exist_node, char * title, char * singer) {
  struct song_node *add = malloc (sizeof (struct song_node)); //allocate memory for new node
  add -> name = title; //initialize node
  add -> artist = singer;
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

struct song_node * create_link(char * title, char * singer){ //in order to initialize first element
  struct song_node * end = malloc(sizeof(struct song_node));
  end -> name = title;
    end -> artist = singer;
  end -> next = NULL;
  return end;
}

struct song_node * insert_order(song_node * first, char * title, char * singer) {
  struct song_node *exist_node = first;
  struct song_node *add = malloc (sizeof( struct song_node));
  struct song_node *temp = malloc (sizeof( struct song_node));
  add -> name = title;
  add -> artist = singer;
  while (exist_node &&
         (strcmp(singer, exist_node -> artist) < 0 ||
	       strcmp(title, exist_node -> name) < 0)) {//while artist/song smaller
    temp = exist_node;
    exist_node = exist_node -> next;
  }
  temp -> next = add;
  add -> next = exist_node;
  // print_list(add);
  if (add -> next == first) {//if add was inserted in front
    //printf("IT'S A SECRET!");
    return add;
  }
  return first;//return pointer to beginning of list
}

int main(){
    song_node * y = create_link("Skyfall", "Adele");
    print_list(y);
    printf("\n");
    y = insert_front(y, "Symphony 40", "Mozart");
    print_list(y);
    printf("\n");
    y = insert_order(y, "Symphony 40.5", "Aaozart");
    print_list(y);
    printf("\n");

    y = insert_order(y, "Uptown Girl", "Billy Joel");
    print_list(y);
    printf("\n");
    y = insert_order(y, "Waka Waka", "Shakira");
    print_list(y);
    printf("\n");
    print_list(y);

    return 0;

}
