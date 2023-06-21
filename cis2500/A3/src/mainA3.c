#include"../include/headerA3.h"

int main(){

   struct employee *head = NULL;//Head of the linked list
    
   //All the variables used
   int choice = 0;
   int position;
   int id;
   char name [100];
   int positionName;
   int positionId;
   int countEmp;
   int nEmp;
   int countFor8;
   char choice10;

   loadEmpData(&head, "proFile.txt");//Loads the data from the file

   while(choice != 10){//Loop goes until the choice is 10

      //Prints the menu for all function
      
      printf("1. Add a new employee \n");
      printf("2. Print data of all employees \n");
      printf("3. Print data of the nth employee \n");
      printf("4. Search for employee based on empId \n");
      printf("5. Search for employee based on full name \n");
      printf("6. Count the total number of employees \n");
      printf("7. Sort the employees based on their empId \n");
      printf("8. Remove the nth employee in the current LL \n");
      printf("9. Remove all employees in the current LL \n");
      printf("10. Exit \n\n");

      printf("Choose a menu option: "); //The user chooses the option
      scanf("%d",&choice);

      if(choice == 1){//If the user chooses 1 it calls the recruitEmployee function 
         recruitEmployee(&head);
         printf("\n"); 
      }
      else if(choice == 2){//If the user chooses 2 it calls the printAll function
         printAll(head);
         printf("\n");
      }
      else if(choice == 3){ //If the user chooses 3 it asks the user for a position and then calls the printOne function
         printf("\nEnter a position: ");
         scanf("%d",&position);
         printf("\n");
         printOne(head,position);
         printf("\n");
      }
      else if(choice == 4){ //If the user chooses 4 it asks the user for their employee ID  and then prints the employee data based on the position
         printf("\nEnter an employee ID: "); 
         scanf("%d",&id);
         positionId = lookOnId(head,id);
         printf("\n");
         if(positionId == -1){
            printf("The position does not exist or the list is empty\n");
         }  
         else{
            printOne(head,positionId);
         }
         printf("\n");
      }
      else if(choice == 5){ //If the user chooses 5 it asks for the full name of the employee and prints the data for the employee
         getchar();
         printf("\nEnter the full name of the employee: ");
         scanf(" %[^\n]%*c",name);
         positionName = lookOnFullName(head,name);
         printf("\n");

         if(positionName == -1){
            printf("The position does not exist or the list is empty\n");
         }
         else{
            printOne(head,positionName);
         }
         printf("\n");
      }
      else if(choice == 6){//This will print how many employees are in the list
         countEmp = countEmployees(head);
         printf("\nTotal number of employees = %d\n\n",countEmp);

      }
      else if(choice == 7){//Calls the sort function
         sortEmployeesId(head);
      }
      else if(choice == 8){//Prints how many employees are in the list

         countFor8 = countEmployees(head);
         printf("\nCurrently there are %d employees\n\n",countFor8);
         printf("Which employee would you like to fire? Enter a value between 1 and %d employees: ",countFor8);//Asks which employee they wanna fire
         scanf("%d",&nEmp);
         if(nEmp > 0 && nEmp <= countFor8){//If the value is within the range it removes that node, prints the total employees left
            fireOne(&head,nEmp);
            countFor8 = countEmployees(head);
            printf("\nThere are now %d employees\n\n",countFor8);
         }
         else{
            printf("Invalid input");
         }


      }
      else if(choice == 9){

         printf("Are you sure you want to fire everyone: ");//Asks if they want to remove the whole list
         scanf(" %c",&choice10);
         if(tolower(choice10) == 'y'){//Removes the whole list if the anser is y
            fireAll(&head);
            printf("\nAll fired. Linked list is now empty.\n\n");
         }

      }
      else if(choice == 10 ){//Frees the list if the choice is 10 because it will give memory leaks
         fireAll(&head);
      }
      else{
         printf("Invalid choice, enter again\n\n");
      }
   }

   return 0;
}