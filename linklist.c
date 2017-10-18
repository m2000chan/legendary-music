#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "song_node.h"
#include <time.h>

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
         (strcmp(singer, exist_node -> artist) > 0 ||
          (strcmp(singer, exist_node -> artist) == 0 &&
	       strcmp(title, exist_node -> name) > 0))) {//while artist/song smaller
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

song_node * find_artist(song_node * exist_node, char * singer) {
  while (exist_node && strcmp(singer, exist_node -> artist) != 0) {
    exist_node = exist_node -> next;
  }
  return exist_node;
}

int get_length(song_node * exist_node){
  int count = 0;
  while(exist_node){
    exist_node = exist_node -> next;
    count++;
  }
  return count;
}

song_node * random_song(song_node * exist_node){
  int length = get_length(exist_node);
  srand(time(NULL));
  long random = rand() % (length + 1);
  while (random > 1){
    exist_node = exist_node -> next;
    random--;
  }
  return exist_node;
}

song_node * remove_node(song_node * exist_node, char * title, char * singer) {
  song_node *temp = malloc (sizeof( song_node));
  while (exist_node &&
         (strcmp(singer, exist_node -> artist) != 0 &&
	       strcmp(title, exist_node -> name) != 0)) {//while artist/song smaller
    temp = exist_node;
    exist_node = exist_node -> next;
  }
  if (exist_node){
    temp -> next = exist_node -> next;
  }
  return NULL;
}









int main(){
    song_node * y = create_link("skyfall", "adele");
    print_list(y);
    printf("\n");
    //y = insert_front(y, "Symphony 40", "Mozart");
    //print_list(y);
    printf("\n");
    y = insert_order(y, "symphony 40.5", "bozart");
    y = insert_order(y, "piece", "aa");
    print_list(y);
    printf("\n");
    y = insert_order(y, "song", "aa");
    print_list(y);
    printf("\n");
    y = insert_order(y, "aaaaa", "aa");
    print_list(y);
    printf("\n");

    y = insert_order(y, "uptown girl", "billy joel");
    print_list(y);
    printf("\n");
    y = insert_order(y, "waka waka", "shakira");
    print_list(y);
    printf("\n");

    song_node *song_search = find_song(y, "uptown girl", "billy joel");
    print_list(song_search); //prints list starting from Billy Joel
    printf("\n");

    song_node *artist_search = find_artist(y, "adele");
    print_list(artist_search); //prints list starting from Adele
    printf("\n");
    printf("%d\n", get_length(y));


    song_node *random = random_song(y);
    print_list(random);
    printf("\n");

    remove_node(y, "uptown girl", "billy joel");
    print_list(y);


    return 0;

}
