#include "lab1.h"

 void saveEmployees (Employees arr[NUM_EMP], int c, char fName [SIZE]){

    FILE *fptr;

    fptr = fopen(fName,"w");

    if (fptr == NULL) {
        printf("Could not open the file\n");
    }

    else{

          for(int i=0;i<c;i++){
          fprintf(fptr,"%s %s %d ",arr[i].fname,arr[i].lname, arr[i].id);

               for(int j=0; j<3; j++){
                  fprintf(fptr,"%s ",arr[i].dependents[j]);

               }
          }

     }

    fclose(fptr);
 }

 int loadEmployees (Employees arr[NUM_EMP], char fname[SIZE]){

     FILE *fptr;

     int i = 0;

     fptr = fopen(fname,"r");

     if (fptr == NULL){
         printf("Could not open the file\n");
     }

     else{

         while(fscanf(fptr, "%s %s %d %s %s %s \n",arr[i].fname,arr[i].lname,&arr[i].id,arr[i].dependents[0],arr[i].dependents[1],arr[i].dependents[2]) != EOF){
                    i++;

         }
     }

     return i;

     fclose(fptr);
}
