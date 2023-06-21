#include "../include/headerA3.h"

int lookOnId (struct employee * headLL, int whichEmpId){
    //This function searches for an employees based on their employee id and returns the position

    if(headLL == NULL){ //Checks to see if the list is empty
        return -1;
    }

    struct employee * ptr;
    ptr = headLL;

    int position = 0;

    while(ptr!=NULL){
        position++;
        if(whichEmpId == ptr->empId){ //Checks to see when the employee ids are the same
            return position;//Returns the position
        }

        ptr = ptr->nextEmployee;
    }
    return -1; //Returns -1 if the position cannot be found
}