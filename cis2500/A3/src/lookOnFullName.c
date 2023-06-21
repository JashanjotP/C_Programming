#include "../include/headerA3.h"

int lookOnFullName (struct employee * headLL, char whichName [100]){
    //This function searches employee based on their name and returns their position

    if(headLL == NULL){
        return -1;
    } //Checks to see if the list is empty

    struct employee * ptr;

    ptr = headLL;

    int position = 0;

    char *firstName = strtok(whichName," ");//Using strtok to break whichName into firstName and lastName
    char *lastName = strtok(NULL," ");

    while(ptr != NULL){ //Traverses through the list
        position++;
        if(strcmp(firstName,ptr->fname) == 0){ //If the first and last name are the same it returns the position
            if(strcmp(lastName,ptr->lname) == 0){
                return position;
            }
        }
        ptr = ptr->nextEmployee;
    }

    firstName = NULL; //Makes firstName and lastName point to NULL
    lastName = NULL;

    return -1; //Returns -1 if the position is not found
}