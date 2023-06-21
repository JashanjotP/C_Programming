/* Name: Jashanjot Panjrath
    ID: 1222040
    email: jpanjrat@uoguelph.ca
  */

#include <stdio.h>
#include <stdlib.h>
//Prototypes
int populateArray(int ** leArr);
int processArray(int *leArr, int size);

int main(){

   int * leArr = NULL; //Declares a pointer and gives it a null value
   int size = populateArray (&leArr); //Passes as an & because of prototyple

   int howMany = processArray(leArr,size);

    printf("There are %d elements that are multiples of 5\n", howMany); // Prints out how many elements are multiples of 5

    free(leArr);
    return 0 ;
}
