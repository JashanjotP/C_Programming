/************************panjrathJashanjotDIYL2.c**************
Student Name: Jashanjot Panjrath          Email: jpanjrat@uoguelph.ca
Course Name: CIS 1300

I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:

1) I have read and understood the University policy on academic integrity. 2) I
have completed the Computing with Integrity Tutorial on Moodle; and 3) I have
achieved at least 80% in the Computing with Integrity Self Test.

I assert that this work is my own. I have appropriately acknowledged any and
all material that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for
this course.
********************************************************/

/*********************************************************
Compiling the program

compiling:
gcc -std=c99 -Wall panjrathJashanjotDIYL2.c

Running:
 ./a.out
OR

gcc -std=c99 -Wall panjrathJashanjotDIYL2.c -o diyL2

Running the Program: ./diyL2
*********************************************************/

/* This program prints out the multiplication table from 1 to 9, the user is asked what numbers multiplication he would like to see,
if 0 is entered then it prints all the multiplication from 1 to 9, otherwise it prints that specific number. In the end it asks the 
user if they want to keep on going, if they answer n the program stops
*/
#include <stdio.h>

int main(){

    int choice;
    char ans = 'y'; //This is intialized to start the while loop

  while(ans == 'y'){  //While loop made to run until the user says no
  
    printf("Enter 0 to see all the multiplication from 1 - 9 OR \n");
    printf("\n");
   
    printf("Enter a number between 1-9 to see its multiplication table\n");
    printf("Enter a choice: ");  //Asks for what type of multiplication that they would like to be printed
    scanf("%d", &choice);

    if(choice == 0 ){  //If it is 0 then prints the multiplication from 1 to 9

         printf("----------Printing Multiplication Tables 1 - 9----------\n");
        for(int i=0; i<80;i++){
          printf("*");
        }

        

         printf("\n\tOne    Two    Three    Four    Five    Six     Seven   Eight    Nine\n\n"); //this shows what the number is being multiplied by

         int num =0;
         printf("One \t");//Variable corsopends with what its being added to 
         for(int k=0; k<9; k++){
           num++;
           printf("%2d\t", num); //Its adds that number nine times and the increment goes up one time and then prints it each time
         }
          printf("\n");

           int num2 =0;

          printf("Two \t");
          for(int k=0; k<9; k++){
           num2 = num2 + 2;
           printf("%2d\t", num2); 
         }
          printf("\n");


           int num3 =0;

          printf("Three \t");
          for(int k=0; k<9; k++){
           num3 = num3 + 3;
           printf("%2d\t", num3); 
         }
          printf("\n");

          int num4 =0;

          printf("Four \t");
          for(int k=0; k<9; k++){
           num4 = num4 + 4;
           printf("%2d\t", num4); 
         }
          printf("\n");

          int num5 =0;

          printf("Five \t");
          for(int k=0; k<9; k++){
           num5 = num5 + 5;
           printf("%2d\t", num5); 
         }
          printf("\n");

           int num6 =0;

          printf("Six \t");
          for(int k=0; k<9; k++){
           num6 = num6 + 6;
           printf("%2d\t", num6); 
         }
          printf("\n");

           int num7 =0;

          printf("Seven \t");
          for(int k=0; k<9; k++){
           num7 = num7 + 7;
           printf("%2d\t", num7); 
         }
          printf("\n");

          int num8 =0;

          printf("Eight \t");
          for(int k=0; k<9; k++){
           num8 = num8 + 8;
           printf("%2d\t", num8); 
         }
          printf("\n");

          int num9 =0;

          printf("Nine \t");
          for(int k=0; k<9; k++){
           num9 = num9 + 9;
           printf("%2d\t", num9); 
         }
          printf("\n");



         printf("\n");
         for(int i=0; i<80;i++){
          printf("*");
        }
       
    }
    else{  //If a specific number is chosen it prints the multiplication for that

        if (choice!=0){

            printf("Printing multiplication table for %d ", choice);
                 for(int i = choice; i < choice + 1; i++){

             for(int j =1; j<10; j++){
                printf("%d x %d = %d\n",i,j ,i*j);
             }
             printf("\n");
             
         }
        }
    }
    printf("Do you wish to continue? Enter y for yes: \n");
    scanf(" %c", &ans); //Asks if they still want to continue

  }

  return 0; //Program ends
}