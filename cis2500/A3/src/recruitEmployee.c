#include "../include/headerA3.h"

void recruitEmployee(struct employee **headLL)
{
    int i;

    struct employee *temp = *headLL;

    // define a node
    struct employee *newEmp;

    // allocate memory for the new employee
    newEmp = (struct employee *)malloc(sizeof(struct employee));

    // get the information of the employee
    printf("Enter the first name of the employee: ");
    scanf("%s", newEmp->fname);
    printf("Enter the last name of the employee: ");
    scanf("%s", newEmp->lname);
    printf("\n");

    newEmp->dependents = malloc(sizeof(char*));

    //keep track of number of dependents
    int numDependents = 0;
    //name of the dependents
    char dependent[MAX_LENGTH];

    char ans = 'y';

    while (tolower(ans) == 'y')
    {
        // User enters the name of the dependent
        printf("Enter name of dependent# %d: ", (numDependents + 1));
        scanf("%s", dependent);

        // allocate memory using malloc
        newEmp->dependents[numDependents] = malloc(strlen(dependent) + 1);
        strcpy(newEmp->dependents[numDependents], dependent);

        // Increments as we add dependents
        numDependents++;

        // allocate more memory
        newEmp->dependents = realloc(newEmp->dependents, (numDependents + 1) * sizeof(char*));

        // Set the next element to NULL to ensure proper termination
        newEmp->dependents[numDependents] = NULL;

        // User answers yes or no, if the answer is y or Y the while loop goes again
        printf("Do you have any more dependents? ");
        scanf(" %c", &ans);
        printf("\n");
    }

    // shrink the size of the dependents array to the exact number of dependents
    newEmp->dependents = realloc(newEmp->dependents, numDependents * sizeof(char*));

    // if the answer is not y or Y
    newEmp->numDependents = numDependents;
    printf("You have %d dependents.\n", numDependents);

    //Id using the ascii value
     int id = 0;

     for(i = 0; i<strlen(newEmp->fname); i++){
       id = id + newEmp->fname[i];
     }

     id = id + strlen(newEmp->lname);

     newEmp->nextEmployee = NULL;


    // Check if empId already exists in the linked list
    int empId = id;
    struct employee *emp;
    emp = *headLL;

    while (emp != NULL)
    {
        if (emp->empId == empId)
        {
            empId = empId + (rand() % 999) + 1;
            emp = *headLL;
        }
        else
        {
            emp = emp->nextEmployee;
        }
    }
    newEmp->empId = empId;

    // Print empId
    printf("Your computer-generated empId is %d.\n", empId);
    printf("\n");


    // Add the new employee to the end of the linked list
    if (*headLL == NULL)
    {
        *headLL = newEmp;
    }
    else
    {
        while (temp->nextEmployee != NULL)
        {
            temp = temp->nextEmployee;
        }
        temp->nextEmployee = newEmp;
    }

}
