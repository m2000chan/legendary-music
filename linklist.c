#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song_node.h"

void print_list (song_node * curr_node) {
  //printf("[");
  while (curr_node) { //while there is another node after, print value then proceed to next
    printf("Artist: %s\t Song: %s\n", curr_node -> artist, curr_node -> name);
    curr_node = curr_node -> next;
  }
}

song_node * insert_front (song_node * exist_node, char * title, char * singer) {
  song_node *add = malloc (sizeof (song_node)); //allocate memory for new node
  add -> name = title; //initialize node
  add -> artist = singer;
  add -> next = exist_node;
  return add;
}


song_node * free_list(song_node * start){
  song_node * temp;

  while (start -> next) {
    temp = start;
    start = temp -> next;
    free (temp);
  }
  free(start); //free last node
  return NULL;
}

song_node * create_link(char * title, char * singer){ //in order to initialize first element
  song_node * end = malloc(sizeof(song_node));
  end -> name = title;
    end -> artist = singer;
  end -> next = NULL;
  return end;
}

song_node * insert_order(song_node * first, char * title, char * singer) {
  song_node *exist_node = first;
  song_node *add = malloc (sizeof( song_node));
  song_node *temp = malloc (sizeof( song_node));
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
  return first;//otherwise, return pointer to beginning of list
}

song_node * find_song(song_node * exist_node, char * title, char * singer) {
  while (exist_node &&
         (strcmp(singer, exist_node -> artist) < 0 ||
	       strcmp(title, exist_node -> name) < 0)) {
           exist_node = exist_node -> next;
         }
  return exist_node;//should be NULL if didn't find
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

    song_node *song_search = find_song(y, "Uptown Girl", "Billy Joel");
    print_list(song_search);
    printf("\n");


    return 0;

}
