#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.c"

song_node * song_lists[26];

song_node * add_song(char * title, char * singer){

    char x = singer[0];
    
    if (song_lists[x-97]){ //if the first letter of artist has data in list
        
        song_node * first_song = song_lists[x-97];//subtract value of 'a' to get letter index
        
        song_lists[x-97] = insert_order(first_song, title, singer);
        return song_lists[x-97];
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

song_node * song_search(char * title, char * singer){
    
    char x = singer[0];
    
    song_node * search_node = song_lists[x-97];
    
    song_node * returning = find_song(search_node, title, singer);
    
    if (returning == NULL){
        
        printf("\nSONG NOT FOUND\n");
        return NULL;
        
    }
    
    return returning;
}


song_node * artist_search(char * singer){
    
    char x = singer[0];
    
    song_node * search_node = song_lists[x-97];
    //printf("Searching in %c\n", x);
    //print_list(search_node);
    
    song_node * returning = find_artist(search_node, singer);
    
    if (returning == NULL){
        
        printf("\nARTIST NOT FOUND\n");
        return NULL;
        
    }
    
    return returning;
}

void print_letter(char x){
    
    print_list(song_lists[x-97]);
    
}

void print_artist(char * singer){
    
    char x = singer[0];
    
    song_node * search_node = song_lists[x-97];
    
    while (search_node -> next &&
           search_node -> artist != singer){
        
        search_node = search_node -> next;
    }
    
    while(search_node -> next &&
          search_node -> artist == singer){
        
        printf("\t%s\t | \t%s\n", search_node -> artist, search_node -> name);
        search_node = search_node -> next;
    }
    
}

void shuffle(){
    
    int length = 0;
    int i = 0;
    
    for (; i < 26; i++){
        
        length += get_length(song_lists[i]);
        
    }
    
    srand(time(NULL));
    long random = rand() % length;
    
    int j = 0;
    
    for (; j < random; j ++){
    
        
        int randy = rand() % 26;
        
        song_node * rands = random_song(song_lists[randy]);
        
        printf("\t%s\t | \t%s\n", rands -> artist, rands -> name);
    }
    
}


int main(){
    
    printf("TESTING ADDING SONGS/PRINT LIBRARY\n\n");
    
    //FOR SOME REASON THE ADD SONGS WORKS DOESN'T WORK IF THE ARTIST DOUBLE UP, BUT IS OKAY WITH A
    
    add_song("skyfall", "adele");
    add_song("hello", "adele");
    add_song("symphony 40", "mozart"); 
    add_song("ants", "apples");
    add_song("drive by", "train"); 
    add_song("what", "tree");
    add_song("barcelona", "train");
    add_song("orange orange", "chair");
    add_song("we are", "ke$ha"); 
    add_song("sk8tr boy", "lavigne");
    add_song("human", "the killers");
    add_song("mr. brightside", "the killers"); 
    
    print_library();   
    
    printf("\n============\n\n");
    
    
    printf("TESTING SONG SEARCH: Search Adele - Skyfall:\n\n");
    
    song_node * y = song_search("skyfall", "adele");
    
    print_list(y);
    
    printf("\n============\n\n");
    
    printf("TESTING ARTIST SEARCH: Search ke$ha:\n\n");
    
    y = artist_search("ke$ha");
    
    print_list(y);
    
    printf("\n============\n\n");
    
    printf("TESTING PRINT LETTER: Printing t:\n\n");
    
    print_letter('t');
    
    printf("\n============\n\n");
    
    printf("TESTING PRINT ARTIST: Printing adele:\n\n");

    print_artist("adele");
    
    printf("\nPrinting the killers\n\n");
    
    print_artist("the killers");
    
    printf("\n============\n\n");
    
    printf("TESTING SHUFFLE:\n\n");
    
    shuffle();
    
    printf("\n============\n\n");
    
    


    
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
  return 0;

}
