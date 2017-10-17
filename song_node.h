typedef struct song_node{

  char * name;
  char * artist;
  struct song_node * next; //points to next song/artist
  
} song_node;
