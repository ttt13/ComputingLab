#include <stdlib.h> 
#include <stdio.h>
#include <string.h>
#include "list.h"

/* list_t* list_create( void )
{
  list_t* l = malloc( sizeof(list_t) );
  if( l )
    {
      l->head = NULL;
      l->tail = NULL;
    }
  return l;
}

element_t* element_create( int i )
{
  element_t* el = malloc( sizeof(element_t) );
  if( el )
    {
      el->val = i;
      el->next = NULL;
    }
  return el;
}

int list_append( list_t* list, int i )
{
  element_t* el = element_create( i );
  
  if( list->head == NULL )
    list->head = el;
  
  if( list->tail )
    list->tail->next = el;
  
  list->tail = el;

  return 0;
}

void list_print( list_t* list )
{
  printf( "{" );
  
  for( element_t* el = list->head;
       el;
       el = el->next )
    printf( " %d", el->val );

  printf( " }\n" );
}*/

void merge(int arr[], int left, int mid, int right)
{
    int i; 
    int j; 
    int mergeIndex;
    int length1 = mid - left + 1;
    int length2 =  right - mid;
    int low[length1]; 
    int high[length2];
 
    for (i = 0; i < length1; i++){
        low[i] = arr[left + i];
    }

    for (j = 0; j < length2; j++){
        high[j] = arr[mid + 1+ j];
    }
 
    int counter = 0; 
    int counter2 = 0; 
    mergeIndex = left; 
    while (counter < length1 && counter2 < length2){

        if (low[counter] <= high[counter2]){
            arr[mergeIndex] = low[counter];
            counter++;
        }
        else{
            arr[mergeIndex] = high[counter2];
            counter2++;
        }
        mergeIndex++;
    }

    while (counter < length1){
        arr[mergeIndex] = low[counter];
        counter++;
        mergeIndex++;
    }

    while (counter2 < length2){
        arr[mergeIndex] = high[counter2];
        counter2++;
        mergeIndex++;
    }
}
 
void mergeSort(int arr[], int left, int right)
{
	int count = 0;
    if (left < right)
    {
        int mid = left+(right-left)/2;
 
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
 
        merge(arr, left, mid, right);
        count++;
    }
}

int listLen(list_t* list)
{
	element_t* el = list->head;
	int counter = 0;
	element_t* temp = el;

	while( temp != NULL){
		counter++;
		temp = temp->next;
	}

	return counter;
} 

void list_sort(list_t* list)
{
	int counter = 0;
	int length;
	length = listLen(list);
	int tempArray[length];
	element_t* traverse = list->head;
	int counter2 = 0;

	while(traverse != NULL){
		tempArray[counter] = traverse->val;
		counter++;
		traverse = traverse->next;
	}

	/*for (int i = 0; i < length; i++){
		printf("%d\n", tempArray[i]);
	}*/

	mergeSort(tempArray, 0, length-1);

	/*for (int i = 0; i < length; i++){
		printf("%d\n", tempArray[i]);
	}*/
	element_t* sortTrav = list->head;

	while(sortTrav != NULL){
		sortTrav->val = tempArray[counter2];
		counter2++;
		sortTrav = sortTrav->next;
	}
}

/*int main( void )
{
	//int length = 0;
	list_t* list = list_create();
	for (int i = 10; i > 0; i--){
		list_append(list, i);
	}
	list_print(list);

	//length = listLen(list);
	//printf("length = %d\n", length);
	list_sort(list);
	list_print(list);
	return 0;

}*/