/************************panjrathJashanjotDIYL1.c**************
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
gcc -std=c99 -Wall panjrathJashanjotDIYL1.c

Running:
 ./a.out
OR

gcc -std=c99 -Wall panjrathJashanjotDIYL1.c -o diyL1

Running the Program: ./diyL1
*********************************************************/
/*This program is a pretty simple of rock, paper, and scissors , it asks the user
for their choice then, it shows them their and the computers choices and tells them if they won
or not. It also shows if they tie with the computer*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    printf("This program allows you to play Rock, Paper, scissors \n");
    printf("\n");

    int playerChoice;  //Declares the players choice

    printf("Possible choices: 3=Rock, 2=scissor, 1=Paper \n");
    printf("Whats your choice (number)? ");
    scanf("%d", &playerChoice); //Takes the input for their choice

    printf("\n");

    int x;
    srand (time (NULL));
    x = (rand () % 3) + 1;  //Does the random number logic for the computer

    if(playerChoice == x){  //Conditonal statement printing the rsults based on what the user and the person choose

        if(x == 1){
            printf("We both picked paper\n");
        }

        if(x == 2){
            printf("We both picked Scissors\n");
        }

        if(x == 3){
            printf("We both picked Rock\n");
        }
        printf("\n");
        printf("Its a tie");
    }
    else{
        if(playerChoice == 1){

            if(x ==2){
                printf("Your choice is Paper. My choice is Scissors. \n");
                printf("\n");
                printf("I win!!");
            }
            if(x ==1){
                printf("Your choice is Paper. My choice is Rock. \n");
                printf("\n");
                printf("You win!!");
            }
        }
    
         if(playerChoice == 2){

            if(x ==1){
                printf("Your choice is Scissors. My choice is Paper. \n");
                printf("\n");
                printf("You win!!");
            }
            if(x ==3){
                printf("Your choice is Scissors. My choice is Rock. \n");
                printf("\n");
                printf("I win!");
            }
        }
        
         if(playerChoice == 3){

            if(x ==2){
                printf("Your choice is Rock. My choice is Scissors. \n");
                printf("\n");
                printf("You win!!");
            }
            if(x ==1){
                printf("Your choice is Rock. My choice is Paper. \n");
                printf("\n");
                printf("I win!");
            }
        }
    
    }

    return 0; //Program ends
}