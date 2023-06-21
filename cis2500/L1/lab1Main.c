#include "lab1.h"

 int main(int argc, char *argv[]){

      Employees someone[NUM_EMP];

/*      for(int i=0; i<3; i++){

         printf("Employee #%d\n", i+1);
         printf("First Name: ");
         scanf("%s",someone[i].fname);
         printf("Last name: ");
         scanf("%s",someone[i].lname);
         printf("ID Num: ");
         scanf("%d",&someone[i].id);

         for(int j=0; j<3; j++){
            printf("Dependent #%d",j+1);
            scanf("%s",someone[i].dependents[j]);
            }
      }

      int c;

      printf("How many employees ?\n");
      scanf("%d", &c);

      saveEmployees(someone,c, argv[1]);
*/
      Employees data[NUM_EMP];

      int records =loadEmployees(data,argv[1]);

     printEmployees (data, 2);
/*
      for(int i =0; i<records; i++){

          printf("\nEmployee #%d\n",i+1);
          printf("First Name: %s\n",data[i].fname);
          printf("Last Name: %s\n",data[i].lname);
          printf("ID: %d\n",data[i].id);

          for(int j=0; j<3; j++){

             printf("Dependent #%d: %s\n",j+1,data[i].dependents[j]);
           }

      }

      printf("Total number of records: %d\n",records);

      printf("Swap function below\n");

      Employees work1;
      Employees work2;

      strcpy(work1.fname,"Sehaj");
      strcpy(work1.lname,"Singh");
      work1.id = 122223;
      strcpy(work1.dependents[0], "seered");
      strcpy(work1.dependents[1], "crrcr");
      strcpy(work1.dependents[2] ,"drrrc");

      strcpy(work2.fname ,"Mehar");
      strcpy(work2.lname , "Singh");
      work2.id = 3233;
      strcpy(work2.dependents[0] , "tgtgee");
      strcpy(work2.dependents[1] ,"tgtrr");
      strcpy(work2.dependents[2] ,"ijuhy");

      swapEmployees(&work1,&work2);

      printf("After Swap:\n");

      printf("%s\n%s\n%d\n",work1.fname,work1.lname,work1.id);

      for(int i=0; i<3; i++){

          printf("%s\n",work1.dependents[i]); 
      }*/
      return 0;
 }
