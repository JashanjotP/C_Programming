#include "../include/headerA3.h"

void fireAll (a3Emp ** headLL){
    //This function removes all the nodes from the list

    if(*headLL == NULL){ //Checks if the list is empty
        printf("\nThe list is empty\n");
        return;
    }
    a3Emp *temp;

   while ( *headLL != NULL ) { //Traverses through the list
       temp = *headLL; //Makes temp point to head
       *headLL = temp->nextEmployee; //Head goes to the next node
       for(int i=0; i<temp->numDependents; i++){
           free(temp->dependents[i]);  //Frees this because it is mallocd
       }
       free(temp->dependents);
       free (temp); //Then frees the node that head as pointing to
    }

    *headLL = NULL; //Makes the head point to NULL

}