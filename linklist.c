#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *next;
};


void print_list (struct node * curr_node) {
  printf("[");
  while (curr_node -> next) { //while there is another node after, print value then proceed to next
    printf("%d, ", curr_node -> value);
    curr_node = curr_node -> next;
  }
  printf("%d]\n", curr_node -> value); //print last element
}

struct node * insert_front (struct node * exist_node, int val) {
  struct node *add = malloc (sizeof (struct node)); //allocate memory for new node
  add -> value = val; //initialize node
  add -> next = exist_node;
  return add;
}


struct node * free_list(struct node * start){
  struct node * temp;

  while (start -> next) {
    temp = start;
    start = temp -> next;
    free (temp);
  }
  free(start); //free last node
  return NULL;
}

struct node * create_link(val){ //in order to initialize first element
  struct node * end = malloc(sizeof(struct node));
  end -> value = val;
  end -> next = NULL;
  return end;
}



int main() {

  struct node * first = create_link(15);
  //print_list(&first);

  struct node * zero = insert_front (first, 10);

  printf("\nMy Linked List:\n");
  print_list(zero); //should be [10, 15]

  printf("\nInserted 5 at the front:\n");
  struct node * negative = insert_front(zero, 5);
  print_list(negative); //should be [5, 10, 15]


  printf("\nAfter free list, the start pointer points to NULL: %s\n", free_list(negative)? "False":"True");



  return 0;
}
