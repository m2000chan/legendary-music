#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.c"

song_node * song_lists[26];

void initialize(){

    song_node * song_lists[26]; //Array to store each letter

}

song_node * add_song(char * title, char * singer){

    char x = singer[0];
    song_node * first_song = song_lists[x-97];//subtract value of 'a' to get letter index
    return insert_order(first_song, title, singer);
}
