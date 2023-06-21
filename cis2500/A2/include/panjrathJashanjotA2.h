/*
Student Name: Jashanjot Panjrath
Student ID: 1222040
Due Date: March 6, 2023
Course: CIS*2500

I have exclusive control over this submission via my password.
By including this header comment, I certify that:
1) I have read and understood the policy on academic integrity.
2) I have completed Moodle's module on academic integrity.
3) I have achieved at least 80% on the academic integrity quiz

I assert that this work is my own. I have appropriate acknowledged
any and all material that I have used, be it directly quoted or
paraphrased. Furthermore, I certify that this assignment was written
by me in its entirety.
*/

//All the libraries used
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Function Prototypes
char * readFile (char * filename);//Function 1

void dejaVu (char * aString, int * numWords, int * numSentences);//Function 2

char * goBig (char * aString);//Function 3

char ** goAway (char * aString, int * numWordsReturned);//Function 4

char * breathless (char * aString);//Function 5

void tail (char * aString, int whichWord, char * desiredSuffix);//Function 6
