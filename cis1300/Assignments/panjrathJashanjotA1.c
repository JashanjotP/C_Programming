/************************panjrathJashanjotA1.c**************

Student Name: Jashanjot Panjrath          Email Id: jpanjrat@uoguelph.ca 
Due Date: 2022-10-7                       Course Name: CIS 1300
I have exclusive control over this submission via my password.
By including this statement in this header comment, I certify that:

1) I have read and understood the University policy on academic integrity.
2) I have completed the Computing with Integrity Tutorial on Moodle; and 3) I have
achieved at least 80% in the Computing with Integrity Self Test.

I assert that this work is my own. I have appropriately acknowledged any and
all material that I have used, whether directly quoted or paraphrased.
Furthermore, I certify that this assignment was prepared by me specifically for
this course.
********************************************************/

/*********************************************************
Compiling the program
The program should be compiled using the following flags: -std=c99 -Wall

compiling:
gcc -std=c99 -Wall panjrathJashanjotA1.c

Running: ./a.out

OR

gcc -std=c99 -Wall panjrathJashanjotA1.c -o a1

Running the Program: ./a1
*********************************************************/

/*This program calculates the  individual assessment
grades and the overall grade for students registered in the course.The purpose of this
assignment is to write code that helps instructors do such calculations for a course
called ALT1300
It starts of by asking for lab marks
Then assignment marks and looks for a plagirism check using Moss
Then ask for the quiz marks
Then final exam mark, then does a survey asking if they want the lab exam weight to shift to final exam
Then ask for final exam mark
and then also does a check where it adds quiz and final exam if that is less than 25 than you get an F
Prints all the marks in a percent
Asks if the program
When stopped tells the average of the students in the course */

#include <stdio.h>

int main(){

     int count = 0;    

     int studentNum = 1; //Variables made for the number of students and the average of the course

     double totalMark= 0;                    

     printf("Welcome to ALT1300 admin page \n");
     printf("\n");

     char ans;         //This starts the loop
     ans = 'y';

  while(ans == 'y'){         //while loop keeps on going until the answer to last question is n

     printf("Student# %d:\n", studentNum); //Prints on what number of student we are on

     printf("\n");

     double l1mark, l2mark, l3mark, l4mark, l5mark, labAverage;

     printf("Enter 5 lab marks, each separated by a space: " );
     scanf(" %lf %lf %lf %lf %lf",&l1mark, &l2mark, &l3mark, &l4mark, &l5mark);  //Asks the user for 5 lab marks

     labAverage = ( l1mark + l2mark + l3mark + l4mark + l5mark)/5;

     double percent = labAverage / 100;
     double labGrade = percent * 20;   //Logic to convert the marks into one grade out of 20 and print it

     printf("Overall lab grade (20) = %.2lf / 20.0\n ", labGrade);

     printf("\n");

     double A1mark, A2mark, A3mark, A1percent, A2percent, A3percent;

     int moss1 , moss2, moss3;

     printf("Enter 3 assignment marks, each separated by a space: ");  //Asks the user for 3 assignment grades
     scanf(" %lf %lf %lf", &A1mark, &A2mark, &A3mark);

     printf("Enter MOSS result for A1: ");
     scanf("%d", &moss1);
     
     printf("Enter MOSS result for A2: ");  //Check1 If any moss result is 0 the mark for that assignment is 0
     scanf("%d", &moss2);

     printf("Enter MOSS result for A3: ");
     scanf("%d", &moss3);

     if(moss1 == 0){   //if statement based on the moss check

            A1mark = 0;

      }

     if(moss2 == 0){

            A2mark = 0;

      }

     if(moss3 == 0){

            A3mark = 0;

      }

     A1percent = (A1mark / 100)* 5;
     A2percent = (A2mark / 100)* 7;   
     A3percent = (A3mark / 100)* 8;

     double aGrade = A1percent + A2percent + A3percent;   //Logic to convert the marks into grade and prints the result

     printf("Overall assignment grade (20) = %.2lf / 20.0 \n", aGrade);

     printf("\n");

     double q1Mark , q2Mark, q3Mark, q4Mark, qAverage;

     printf("Enter 4 quiz marks, each seprated by a space: ");   //Asks the user for 4 quiz marks
     scanf(" %lf %lf %lf %lf", &q1Mark, &q2Mark, &q3Mark, &q4Mark);

     qAverage = (q1Mark + q2Mark + q3Mark + q4Mark)/4;

     double qPercent = qAverage / 100;
     double qGrade = qPercent * 20;  //Logic to convert the mark into grade and print them

     printf("Overall quiz grade (20) = %.2lf / 20.0\n",qGrade);
     
     printf("\n");

     double labeMark, finalePercent, labeGrade;

     printf("Enter final lab exam mark: ");
     scanf("%lf" , &labeMark);     //Asks for lab exam mark

     char survey;

     printf("Enter the survey response ('y' or 'n'): "); //Check 3 Asks for survey answer
     scanf(" %c",&survey);

     if(survey == 'y'){      //if statement based on the survey answer 

             printf("Your lab exam is worth 0, and final exam is worth 40\n");
             finalePercent = 40;
             labeGrade = 0;
     }

     if(survey == 'n') {

              printf("Your lab exam is worth 10, and final exam is worth 30\n");
              finalePercent = 30;
              labeGrade = labeMark / 10;
      }

      double finalexamMark, finalexamGrade, finalexamD;

      printf("\n");

      printf("Enter final exam mark: ");    //Asks for the final exam mark
      scanf("%lf", &finalexamMark);

      finalexamD = finalexamMark / 100;
      finalexamGrade = finalexamD * finalePercent;   //Logic to convert the mark into grade and print it based on survey response

      printf("Overall final exam grade (%.2lf) = %.2lf / %.2lf \n", finalePercent, finalexamGrade, finalePercent);

      printf("\n");

      double finalexamGrade2 = finalexamD * 30;
      double quizExam = qGrade + finalexamGrade2; //Check 4 logic to figure out grade when quiz and final exam mark added

      if(quizExam < 25){  //if statement based on check 4 print according to quiz and exam work

             printf("Quizzes + Final Exam = %.2lf + %.2lf = %.2lf (<25) \n", qGrade, finalexamGrade2, quizExam);

      }

      if(quizExam >= 25){

             printf("Quizzes + Final Exam = %.2lf + %.2lf = %.2lf (>=25) \n", qGrade, finalexamGrade2, quizExam);

      }

      printf("\n");

      printf("Overall course marks (%%) \n"); //Starts printing the all the overall course marks
      printf("********************\n");

      if(labeGrade == 0){  //if statement based on the survey if labexam grade included or not

      printf("Labs = %.2lf\n", labGrade);
      printf("Assignments = %.2lf\n", aGrade);
      printf("Quizzes = %.2lf\n", qGrade);
      printf("Final Exam = %.2lf\n", finalexamGrade);

      }
      
      if(labeGrade != 0){

      printf("Labs = %.2lf\n" , labGrade);
      printf("Assignments = %.2lf\n", aGrade);
      printf("Quizzes = %.2lf\n", qGrade);
      printf("Lab Exam = %.2lf\n", labeGrade);
      printf("Final Exam = %.2lf\n", finalexamGrade);

      }

      printf("********************\n");
      printf("\n");

      double overallMarks = labGrade + aGrade + qGrade + labeGrade + finalexamGrade; //Prints the overall Percent

            if(moss1==0 && moss2==0 && moss3==0){ //Check2 If all moss scores = 0 flags for plagiarism automatic fail

               printf("Yours assignments were flagged for plagiarism\n");
               overallMarks = 0;

            }


      printf("Your overall course marks = %.2lf%%\n", overallMarks);

      char overallGrade;

           if(quizExam < 25){  //if statement based on check4 if quiz and final exam less than 25 automatic

                 overallGrade = 'F';

            }

           else{  //The other grades based on what the overall mark is after the checks are done

                    if(overallMarks <= 100 && overallMarks >= 80){

                             overallGrade = 'A';

                    }

                    if(overallMarks < 80 && overallMarks >= 70){

                             overallGrade = 'B';
                    }

                    if(overallMarks < 70 && overallMarks >= 60){

                             overallGrade = 'C';

                    }

                    if(overallMarks < 60 && overallMarks >= 50){

                             overallGrade = 'D';

                    }

                    if(overallMarks < 50){

                             overallGrade = 'F';

                    }

          }

           printf("Overall Grade = %c\n",overallGrade); //Prints the overall grade

           printf("\n");


       printf("Would you like to continue ('y' to continue, 'n' to exit): ");
       scanf(" %c", &ans);  //Asks if the user wants to continue

       studentNum++; //Keeps on adding the number of student evertime the loop runs

       totalMark = totalMark + overallMarks; //Adds all the total mark till the loop runs

       count++; //Counter for the denominator for the average

   }

//When the loop ends

    double totalAverage;
    totalAverage = totalMark / count; //Logic for calculating average

    printf("\n");

    printf("Average course mark of %d students = %.2lf%%", count, totalAverage); //Prints the course average with total students
    
    printf("\n");

return 0;  //Program ends
}
