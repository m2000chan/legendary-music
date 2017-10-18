#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.c"

song_node * Alpha[26];

void initialize(){
    
    song_node * Alpha[26]; //Array to store each letter
    
}

song_node * add_song(char * Title, char * Singer){
    
    char x = Singer[0];
    song_node * p = Alpha[x-97];
    return insert_order(p, Title, Singer);
}

