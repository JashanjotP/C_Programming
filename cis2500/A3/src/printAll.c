#include"../include/headerA3.h"

void printAll (struct employee * headLL){

    //This function prints out all the nodes in a linked list i
    if(headLL == NULL){
        printf("The list is empty");
        return;
    }

    struct employee * ptr;
    ptr = headLL;

    int num=0;
    while(ptr != NULL){ //Traverses through the list
    
//Prints out the employee detail for each employee
        printf("\nEmployee # %d:\n",num + 1);
        printf("Employee id: %d\n",ptr->empId);
        printf("First Name: %s\n",ptr->fname);
        printf("Last Name: %s\n",ptr->lname);
        printf("Dependents[%d]: ",ptr->numDependents);
        for(int i=0; i<ptr->numDependents; i++){
            printf("%s ",ptr->dependents[i]);
        }
        ptr = ptr->nextEmployee;
        num++;
        printf("\n");
    }

    printf("\nCurrently, there are %d employees\n",num); //prints out how many employees are in the list
}