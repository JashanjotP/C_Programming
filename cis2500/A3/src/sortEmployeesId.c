#include "../include/headerA3.h"

void sortEmployeesId (struct employee * headLL){
    //This function sorts the list based on the employee id and prints it without changing the actual list
    
    if(headLL == NULL){ //Checks to see if the list is empty
        printf("The list is empty so it cannot be sorted\n");
        return;
    }

    struct employee * ptr = headLL; //Points to the list

    int total = countEmployees(headLL); //Stores the total amount of employees in the list

    int empId [total]; //Makes an array that stores the employee id for each node

    int element = 0;  //Element counter

    while(ptr != NULL){ //Traverses through the list and stores the employee id from nodes into the array
        
        empId[element] = ptr->empId;
        element++;
        ptr = ptr->nextEmployee;
    }

    int temp;

    for(int i=0; i < total - 1; i++){ //Bubble sort algorithm
        for(int j=0; j< total - i - 1; j++){
            if(empId[j] > empId[j+1]){
                temp = empId[j];
                empId[j] = empId[j+1];
                empId[j+1] = temp;
            }
        }
    }

    int pos;

    for(int i=0; i<total; i++){//Prints out the node
        pos = lookOnId(headLL,empId[i]);
        printOne(headLL,pos);
        printf("\n");
    }

}