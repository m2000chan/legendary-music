#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song_node.h"

void print_list (struct song_node * curr_node) {
  printf("[");
  while (curr_node) { //while there is another node after, print value then proceed to next
    printf("Artist: %s\t Song: %s\n", curr_node -> artist, curr_node -> name);
    curr_node = curr_node -> next;
  }
 printf("Artist: %s\t Song: %s, ", curr_node -> artist, curr_node -> name); //print last element
}

struct song_node * insert_front (struct song_node * exist_node, char * Title, char * Singer) {
  struct song_node *add = malloc (sizeof (struct song_node)); //allocate memory for new node
  add -> name = Singer; //initialize node
    add -> artist = Title; 
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
