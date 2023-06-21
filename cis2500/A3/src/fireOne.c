#include "../include/headerA3.h"

void fireOne (a3Emp ** headLL, int whichOne){
    //This function removes a single node from the list specified by the user


    if(*headLL == NULL){ //Checks to see if the list is empty
        printf("The list is empty\n");
        return;
    }

    a3Emp *current = *headLL; //Points a pointer to head
    a3Emp *previous = NULL; //Makes the other pointer point to NULL

    if(whichOne == 1){ //If the employee fire choosen is 1 

        *headLL = current -> nextEmployee; //Makes the head point to the next node
        printf("\nEmployee [Id:%d] fired.\n",current->empId); //Prints the employee that gets fired with their id
        for(int i=0; i<current ->numDependents; i++){
            free(current ->dependents[i]);
        }
        free(current->dependents);
        free(current); //Frees the dependent and the node
    }
    else{ //If employee fired is not 1
        for(int i=1; i<=whichOne - 2; i++){
            current = current ->nextEmployee; //Takes the pointer to that node
        }
            previous = current ->nextEmployee;  //Changing the links for the nodes
            current ->nextEmployee = previous ->nextEmployee;
            printf("\nEmployee [Id:%d] fired.\n",previous->empId); //Prints the employee that is about to be fired
            for(int i=0; i<previous->numDependents; i++){
                free(previous->dependents[i]);
            }
            free(previous->dependents);
            free(previous);//Frees the node
    }

}