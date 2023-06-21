#include "../include/headerA3.h"

void recruitEmployee (struct employee ** headLL){
    //This function asks the user for employee data and adds it to the end of the list
    
    struct employee * ptr, *temp,*temp2 = *headLL;
    ptr = *headLL;

    temp = (struct employee *)malloc(sizeof(struct employee));//Makes a struct to store the data

    printf("\nEnter the first name of the employee: ");
    scanf("%s",temp->fname);//Asks the user for the first and last name and stores it 

    printf("Enter the last name of the employee: ");
    scanf("%s",temp->lname);

    int i=0;
    char choice = 'y';

    temp->dependents = malloc(sizeof(char *)); //Allocates the space for the dependents

    char name [MAX_LENGTH];

    printf("\n");

    while(tolower(choice) == 'y'){//The loop goes till the user doesn't wanna add more dependents
        temp->dependents = realloc(temp->dependents,sizeof(char *)*(i+1)); //Allocates enough space
        printf("Enter the name of dependent# %d: ",i+1);
        scanf("%s",name); //Asks the user for the name 
        temp->dependents[i] = malloc(sizeof(strlen(name)) + 1 ); //Allocates space for it
        strcpy(temp->dependents[i],name);//copies the name into the struct
        printf("Do you have any more dependents? ");
        scanf(" %c",&choice);//Asks if there any more dependents
        i++;
        printf("\n");
    }

    printf("You have %d dependent(s) \n",i);

    temp->numDependents = i; //Stores the total amount of dependents in the struct

    int value = 0;

    for(int i=0; i<strlen(temp->fname); i++){
        value +=  temp->fname[i]; //Adds the ASCII values for the employee id
    }

    value = value + strlen(temp->lname); //Then adds the length of the last name

    struct employee * ptr2 = NULL;


    while(temp2 != NULL){ //Checks to see if the employee id is the same then adds a random value to the id between 1 and 999
        srand(time(NULL));
        if( temp2 ->empId == value){
            value = value + (rand()% (999 - 1 + 1) )+ 1;
     
        }
        ptr2 = *headLL;
        while(ptr2 != NULL){

            srand(time(NULL));
            if( ptr2 ->empId == value){
               value = value + (rand()% (999 - 1 + 1) )+ 1;
     
            }
            ptr2 = ptr2 ->nextEmployee;
        }
        temp2 = temp2 ->nextEmployee;
    }
       

    temp->empId = value; //Stores the id into struct and prints the id

    printf("\nYour computer-generated empId is %d\n",temp->empId);

    temp-> nextEmployee = NULL; //Makes the pointer for the struct NULL

    if(*headLL == NULL){//If the list is empty then the head points to this node 
        *headLL = temp;
        return;
    }   
     while(ptr->nextEmployee != NULL){//If the list is not empty, goes to the end of the list
       ptr = ptr -> nextEmployee;
    }
    ptr ->nextEmployee = temp; //Makes that node point to this new node and adds to the new list

}
