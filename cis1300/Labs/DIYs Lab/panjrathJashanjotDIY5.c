/************************panjrathJashanjotDIYL5.c**************
Student Name: Jashanjot Panjrath                          Email: jpanjrat@uoguelph.ca
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

gcc -std=c99 -Wall panjrathJashanjotDIYL5.c

Running: ./a.out
OR
gcc -std=c99 -Wall panjrathJashanjotDIYL5.c -o DIYL5

Running the Program: ./DIYL5
*********************************************************/

#include <stdio.h>

int main(){

    FILE *fptr; //File Header

    int numLines = 0;

    char string [100];
    char age [4];
    fptr = fopen("diyL5.txt","r"); //Open the file in read mode

    if (fptr == NULL) { //If file has an error or does not exist
        printf("Could not open diyL5.txt.\n");     
    }

    else{

        while(!feof(fptr)){ //This loop runs till the end of line and with the fscanf it reads the charcters till the string

            fscanf(fptr,"%s",string); //Stores it in string
            fscanf(fptr,"%s",age);  //Reads the next one and stores in age

            printf("%s (%s) is married to ",string,age); //Prints the two variables

            fscanf(fptr,"%s",string); //Then stores the next name and age in the same variable
            fscanf(fptr,"%s",age);
            
            printf("%s (%s)\n",string ,age); //Then prints it again on the same and then goes to the next lines in the file because of the condition

            numLines++;
            
        }
    }

    printf("\nNumber of records read = %d",numLines);

    fclose(fptr); //Closes the file

    return 0;
}