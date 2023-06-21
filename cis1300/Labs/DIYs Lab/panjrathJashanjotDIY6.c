/************************panjrathJashanjotDIYL6.c**************
Student Name: Jashanjot Panjrath                     Email: jpanjrat@uoguelph.ca
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

gcc -std=c99 -Wall panjrathJashanjotDIYL6.c

Running: ./a.out

OR
gcc -std=c99 -Wall panjrathJashanjotDIYL6.c -o DIYL6

Running the Program: ./DIYL6
*********************************************************/

#include <stdio.h>

void printPattern1 (int n); //Function Prototypes
void printPattern2 (int n);

int main(){

    int value1;
    int value2;

    printf("Enter a int value between 1 and 10: ");
    scanf("%d", &value1);  //Asks for the value between 1 and 10 and stores in value 1

    printPattern1(value1); //Calls the function

    printf("\nEnter a int value between 1 and 10: "); //Same thing above for these lines
    scanf("%d", &value2);
    
    printPattern2(value2);

    return 0;
}

void printPattern1 (int n){ 

  if(n>0 && n<11){ //Validation if else statement

    if(n == 1){ //It recurses the function until it becomes one and prints the star
        printf("*\n");
    }

    else{   //The the number goes up by 1 and then prints that many stars until it reaches the n star value

        printPattern1(n-1); //Recursiveness
  
        for(int i=0; i<n; i++){
            printf("*");
        }
        printf("\n"); //New line after every n amount of star is printed
    }

  }

  else{

    printf("Invalid Input");
  }
}


void printPattern2 (int n){

  if(n>0 && n<11){ //Validation if else statement

     if(n==1){ //When n becomes 1 it prints 1 star and stops
        printf("*");
     }
     else{

         for(int i=0; i<n; i++){ //Prints the n amount of stars
            printf("*");
         }

         printf("\n"); //New line
         printPattern2(n-1); //Recurses again by subtracting 1 from the n value
     }

  }
  else{      
     printf("Invalid Input");
  }
}
