#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song_node{

  char name[256];
  char artist[256];
  struct song_node * next; //points to next song/artist
  
} song_node;

