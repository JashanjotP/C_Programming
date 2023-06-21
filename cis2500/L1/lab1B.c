#include "lab1.h"

void printEmployees(Employees worker[NUM_EMP], int c){


      for(int i=0; i<c; i++){

          printf("Employee #%d\n",i+1);
          printf("First Name: %s\n",worker[i].fname);
          printf("Last Name: %s\n",worker[i].lname);
          printf("ID: %d",worker[i].id);

          for(int j=0; j<3; j++){

              printf("Dependent #%d: %s",j+1,worker[i].dependents[j]);

          }

     }

}

void swapEmployees (Employees *worker1,Employees *worker2){

     Employees temp;

     temp = *worker1;
     *worker1 = *worker2;
     *worker2 = temp;

}
