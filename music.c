#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.c"

song_node * song_lists[26];

<<<<<<< HEAD
song_node * add_song(char * title, char * singer){

    char x = singer[0];
    
    if (song_lists[x-97]){ //if the first letter of artist has data in list
        
        song_node * first_song = song_lists[x-97];//subtract value of 'a' to get letter index
        
        return insert_order(first_song, title, singer);
        
    }
    else{
        
        song_node * first_song = create_link(title, singer);
        
        song_lists[x-97] = first_song;
        
        return first_song;
    }
   
}

void print_library(){
    
    int i = 0;
    
    for (; i < 26; i++){
    
        if (song_lists[i]){
            
            printf("%c:\n", i + 97);
            
        }
        
        print_list(song_lists[i]);
        
    }
    
}

song_node * song_search(char * Title, char * Singer){
    
    
}


int main(){
    
    add_song("skyfall", "adele");
    add_song("symphony 40", "mozart");
    add_song("ants", "apples");
    
    print_library();    
    /*
    
  printf("\n\nLINKED LIST TESTS\n\n\n");

  printf("CREATING FIRST SONG:\n");
  song_node * y = create_link("skyfall", "adele");
  print_list(y);
  printf("\n============\n");
  //y = insert_front(y, "Symphony 40", "Mozart");
  //print_list(y);
  printf("\n============\n");
    

  printf("TESTING INSERT ORDER:\n");
  y = insert_order(y, "symphony 40.5", "bozart");
  y = insert_order(y, "piece", "aa");
  print_list(y);
  printf("\n============\n");
  y = insert_order(y, "human", "the killers");
  print_list(y);
  printf("\n============\n");
  y = insert_order(y, "mr. brightside", "the killers");
  print_list(y);
  printf("\n============\n");
  y = insert_order(y, "uptown girl", "billy joel");
  print_list(y);
  printf("\n============\n");
  y = insert_order(y, "waka waka", "shakira");
  print_list(y);
  printf("\n============\n");

  printf("TESTING SONG SEARCH:\n");
  song_node *song_search = find_song(y, "uptown girl", "billy joel");
  print_list(song_search); //prints list starting from Billy Joel
  printf("\n============\n");

  printf("TESTING ARTIST SEARCH:\n");
  song_node *artist_search = find_artist(y, "adele");
  print_list(artist_search); //prints list starting from Adele
  printf("\n============\n");

  printf("TESTING GET LENGTH:\n");
  printf("%d\n============\n", get_length(y));

  printf("TESTING RANDOM SONG SELECT:\n");
  song_node *random = random_song(y);
  print_list(random);
  printf("\n============\n");

  printf("TESTING REMOVE NODE:\n");
  remove_node(y, "uptown girl", "billy joel");
  print_list(y);
  printf("\n============\n\n\n");

  printf("MUSIC LIBRARY TESTS\n\n\n");
  add_song("ich lass für dich das licht an", "revolverheld");

<<<<<<< HEAD
    */
=======
  print_letter("i");

>>>>>>> 090c5bc59bf862529eb5a3ae41c8c99999b1f0c6
  return 0;

}
