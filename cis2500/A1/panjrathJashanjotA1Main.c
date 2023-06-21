#include "givenA1.h"//Header file

int main(int argc, char *argv[]){//argc and argv for command line
//All the variable used declared below
    struct courseStruct courseInfo[NUMBER_COURSES]; 
    struct profStruct profInfo [NUMBER_PROFS];

    char profsNCourses [NUMBER_PROFS][MAX_STR];
    char taughtBy [NUMBER_PROFS][MAX_STR];

    char cNameFoundfun5 [MAX_STR];
    char cNamefun6 [MAX_STR];

    int courseNumfun5;
    int courseNumfun6;
    int courseNumfun7;
    int choice;
    int n;
    int fun2;
    int fun3;
    int fun4;
    int fun5;
    int fun6;
    int fun7;
    float fun8;

    fun2 = readCourse(argv[1],courseInfo);//Calls the second function, populates the struct and stores the return value in fun2

    //If statements to see if the struct is being populated
    if(fun2 == 1){
      printf("The course Struct has sucessfully been populated\n\n");
    }
    else if(fun2 == -1){
      printf("The file does not exist or has more or less than 20 lines");
    }

    fun3 = readProfAndCoursesTaught(argv[2],profInfo,courseInfo);//Calls the third function, populates the struct and stores the return value in fun3

    //If statements below to see if the struct has been populated
    if(fun3 == 1){
      printf("\nThe professor struct has been sucessfuly populated\n\n");
    }

    else if(fun3 == -1){
      printf("The file does not exist\n ");
    }

   //do while loop to run unless the choice entered is not 4,5,6,7, or 8
   do {
        //Menu for the tasks
        printf ("\nHere is the menu: \n\n");
        printf("Choice 4: Displays the Professors that teach atleast n courses\n");
        printf("Choice 5: Takes a course code and stores the name in a string if it exists\n");
        printf("Choice 6: Takes a course name and looks for its code and stores it if it exists\n");
        printf("Choice 7: Takes a course code and tells the name of professors teaching that course\n");
        printf("Choice 8: This tells us the average number of courses taught by the professors\n");
        printf("Enter any choice except 4,5,6,7,and 8 to exit the program\n");
        printf("\nEnter your choice: ");
        scanf ("%d", &choice);

        switch(choice) {//switch statement depending on the choice entered

            case 4://Choice 4

               printf("Enter n number of courses that each professor teaches at least: ");
               scanf("%d",&n);//Asks for the n-value

               if (n >= 0){
                  fun4 =nCourses(n,profInfo,profsNCourses);//Calls the function and stores the return in fun4

                  printf("Professors that teach atleast %d courses = %d\n",n,fun4);//Prints the no of professors that teach atleast n-courses
               }

               else{//If the value entered is not >=0
                  printf("Invalid number of n courses entered\n");
               }

               break;
            case 5://Choice 5

               printf("\nEnter the course number: ");//Ask for the Course Number
               scanf("%d",&courseNumfun5);

               fun5 = getCourseName(courseNumfun5,cNameFoundfun5,courseInfo);//Calls the function and stores the return in fun 5

               //If statement shows the Course Name if found from code
               if(fun5 == 1){
                  printf("\nThe course name was found succesfully and it is %s\n",cNameFoundfun5);

               }//If it cannot it prints cannot be found
               else if(fun5 == 0){
                  printf("\nThe course name could not be found in the file\n");
               }

               break;
            case 6://Choice 6

               getchar();
               printf("Enter the Course Name: ");
               fgets(cNamefun6,MAX_STR,stdin);//Takes the input for the Course Name

               int k = 0;//Removes the \n because we are using fgets
               k = strlen(cNamefun6);
               cNamefun6[k-1] = '\0';

               fun6 = getCourseNum(cNamefun6,&courseNumfun6,courseInfo);//Calls the function and stores the return in fun6

               //If statements to display the Course Code if the name exits
               if(fun6 == 1){
                  printf("\nA course code has been found for %s which is %d\n",cNamefun6,courseNumfun6);
               }
               else if(fun6 == 0){
                  printf("\nNo course code could be found for %s in the file",cNamefun6);
               }

               break;
            case 7://Choice 7

               printf("\nEnter the course code for the profs that you want to look for: ");
               scanf("%d",&courseNumfun7);//Asks for the Course Code

               fun7 = profsTeachingCourse(courseNumfun7,profInfo,taughtBy);//Calls the functions and stores the return in fun7

               if(fun7 == 0){//If statement if no one teaches that course or it does not exist

                  printf("\nThe course does not exist or no prof teaches it\n");

               }

               else{//Other shows how many profs teach that course code
                  printf("\nThe prof(s) teaching %d is = %d\n",courseNumfun7,fun7);
               }

               break;
            case 8://Choice 8

               fun8 = avgNumCourses(profInfo);//Calls the function and stores the return in the float

               printf("The average number of courses taught by professors = %.1lf\n",fun8);//Prints the average number of courses taught by the profs

               break;

            default:

               printf("\nExiting the program\n"); 

        }

    }while (choice == 4 || choice == 5 || choice == 6 || choice == 7 || choice == 8); 

    return 0 ;
}
//End of main
