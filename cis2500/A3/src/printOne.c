#include"../include/headerA3.h"

void printOne (struct employee * headLL, int whichOne){
    //This function prints out the employee details for a specific employee mentioned by the user
    if(headLL == NULL){ //Checks to see if the list is empty
        printf("The list is empty");
        return;
    }

    struct employee * ptr;
    ptr = headLL;

    int num=0;
    while(ptr != NULL){ //Traverses throught
        num++;

        if(num == whichOne){ //When the position matches it prints the employee details

        printf("Employee id: %d\n",ptr->empId);
        printf("First Name: %s\n",ptr->fname);
        printf("Last Name: %s\n",ptr->lname);
        printf("Dependents[%d]: ",ptr->numDependents);

        for(int i=0; i<ptr->numDependents; i++){
            printf("%s ",ptr->dependents[i]);
            }
        }
        ptr = ptr ->nextEmployee;
    
    }
    printf("\n");
}