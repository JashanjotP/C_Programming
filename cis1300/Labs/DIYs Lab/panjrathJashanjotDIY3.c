/************************panjrathJashanjotDIYL3.c**************
Student Name: Jashanjot Panjrath                       Email: jpanjrat@uoguelph.ca
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

gcc -std=c99 -Wall panjrathJashanjotDIYL3.c

Running: ./a.out

OR
gcc -std=c99 -Wall panjrathJashanjotDIYL3.c -o DIYL3

Running the Program: ./DIYL3
*********************************************************/

#include <stdio.h>
#include<string.h>

#define SIZE 100

int myGoodness (char [SIZE]); 

int main(){

    int count;  
    int totalCount =0;
    char goodness [SIZE];
    
    for(int i=0; i<5; i++){ //Loop to take 5 Strings

        printf("Enter String # %d: ",i+1); //Asks for string with its number and storing it in goodness
        
        scanf("%s",goodness);
        count = myGoodness(goodness); //calls the function and stores the return value in count

        printf("Goodness of %s = %d \n",goodness,count); //Prints the desired output
        printf("\n");

        totalCount = totalCount + count; //Keeps on counting the total goodness for each string and adds
    }

    printf("Total goodness today = %d", totalCount);

    return 0;
}

int myGoodness (char good[SIZE]){
    
    int len = strlen(good);

    int check;

    int count =0;
    for(int i=0; i<len; i++){  //Run a loop to see if there is any char in the string except 0 and 1
        if(good[i] != '0' && good[i]!= '1'){
            check =1;
        }
    }
    if(check ==1){  //If there is anything except 0 and 1 the goodness becomes 0
        return 0;
    }
    else{  //If it is not it counts how many 1s are in that string and then returns it
        for(int i=0; i<len; i++){
            if(good[i] == '1'){
                count++;
            }
        }
    }
    return count;
}
