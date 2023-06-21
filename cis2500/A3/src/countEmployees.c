#include "../include/headerA3.h"

int countEmployees (a3Emp * headLL){
    //The function returns how many employees are in the current linked list

    if(headLL == NULL){ //Checks to see if the list is empty
        return 0;
    }

    a3Emp * ptr;

    ptr = headLL; //Makes the struct pointer point to the head

    int count = 0;
    
    while(ptr!=NULL){ //Traverses through each node in the list and adds an employee each time
        count++;
        ptr = ptr -> nextEmployee;
    }
    return count; //Retruns the amount of employees
}