/* Name: Jashanjot Panjrath
    ID: 1222040
    email: jpanjrat@uoguelph.ca
  */


#include <stdio.h>
#include <stdlib.h>

int populateArray(int ** leArr){

    int size;
    printf("Enter the size for the array: "); //Asks the user for the size of the array
    scanf("%d",&size);

    *leArr = malloc(sizeof(int *) * size); //Allocates that much space required

    printf("Enter the elements for the array\n");
    for(int i=0; i<size; i++){ //Asks the user for the elements of the array
       scanf("%d",&(*leArr)[i]);
    }
    return size; //Returns the size of the array
}

int processArray(int *leArr, int size){

  printf("All the elements in the array seperated by a space: \n");
  for(int i=0; i<size; i++){ //Prints all the elements in the array
     printf("%d ",leArr[i]);
  }
  printf("\n");

  int count = 0;

  printf("Elements in the array that are multiples of 5: \n");

  for(int i=0; i<size; i++){ //Prints the elements that are multiples of 5 and adds to the counter
     if(leArr[i] % 5  == 0){
        printf("%d ",leArr[i]);
        count ++;
     }
  }
  printf("\n");

  return count; //Returns the no of elements that are multiples of 5
}
