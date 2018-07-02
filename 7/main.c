#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include <string.h>
#include <assert.h>
int main( int argc, char* argv[] )
{
//Testing for list_create.
  int* getIt = malloc(20);
  memset(getIt, 20,20);
  free(getIt);
  list_t* list = list_create();
  if (list == NULL){ //This shouldn't be NULL.
    printf("List is null. Failed.\n");
    return 1;
  }
  if (list->head != NULL){ //This is initially supposed to be NULL.
    printf("List->head not null. Failed.\n");
    return 1;
  }
  if (list->tail != NULL){ //This is also supposed to be NULL.
    printf("List->tail not null. Failed.\n");
    return 1;
  }
  int* getItAgain = malloc(456);
  memset(getItAgain, 456, 456);
  free(getItAgain);
  element_t* el = element_create(15);
  if (el->next != NULL){
    printf("el is not NULL.\n");
    return 1;
  }
  list_prepend(list, 1);
  if (list->tail == NULL){
    printf("Noooo! it's not supposed to be null!\n");
    return 1;
  }
  if (list->head == NULL){
    printf("list head is null\n");
    return 1;
  }
  int* moreSpace = malloc(567);
  memset(moreSpace, 567, 567);
  free(moreSpace);
  list_t* listTwo = list_create();
  list_append(listTwo, 2);
  if (list->head == NULL || list->tail == NULL){
    printf("One of the two is null.\n");
    return 1;
  }
  list_t* listThree = list_create();
  for( int i=0; i<5; i++ ){
    list_append( listThree, i );
  }
  int* more = malloc(500);
  memset(more, 500, 500);
  free(more);
  element_t* ele2 = list_index(listThree, 0);
  if (ele2->val != 0){
    printf("Indexing did not work.\n");
    return 1;
  }
  list_destroy(listThree);
  list_t* listFour = list_create();
  list_append(listFour, 5);
  element_t* ele3 = list_index(listFour, 0);
  if(listFour->head == NULL){
    printf("Error!\n");
    return 1;
  }
  if(ele3->next != NULL){
    printf("Indexing didn't work t6.\n");
    return 1;
  }
  int index = 0;
 printf( "value at index %d is %d\n", index, ele3->val );
  list_print(listFour);
list_t* listFive = list_create();
//list_append(listFive, 4);
//list_append(listFive, 3);
//list_destroy(listFive);
list_print(listFive);

list_t* listSix = list_create();
list_append(listSix, 2);
list_append(listSix, 3);
listSix->head = NULL;
element_t* testOne = list_index(listSix, 1);
if(testOne == NULL){
  printf("It's null.\n");
}
/*
//Testing for list_append/element_create.
  //element_t* el;
  for( int i=0; i<5; i++ ){
    list_append( list, i );
    if (list->tail == NULL){
      printf("List->tail null. Failed. \n");
      return 1;
    }
    if (list->head == NULL){
      printf("List->head null (Nothing appended). Failed.\n");
    }
  
  } // End of 'for' loop.
//Testing for list_prepend()
  for( int i=-1; i>-5; i-- ){
    list_prepend( list, i );
    if (list->tail == NULL){
      printf("List->tail null. Failed. \n");
      return 1;
    }
    if (list->head == NULL){
      printf("List->head null (Nothing appended). Failed.\n");
    }
  } // End of for loop
  
  list_print( list );
//Testing for list_index()  
  int index = 2;
  element_t* el = list_index( list, index );
  if( el == NULL ){
      printf( "index %d not found\n", index );
      return 1; // fail
    }
    if(list->head == NULL){
      printf("list->head NULL. Failed.\n");
      return 1;
    }
    if (el->next == NULL){
      printf("el->next == NULL. Failed.\n");
      return 1;
    }
  
  printf( "value at index %d is %d\n", index, el->val );
  
  if( el->val != -2 ) 
    return 1;
  
  list_destroy( list ); */
  return 0; // tests pass
}