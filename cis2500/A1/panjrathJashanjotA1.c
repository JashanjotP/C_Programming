#include "givenA1.h" //Including the header file has all the prototypes and the #defined and #includes

FILE *openFileForReading(char fileName [MAX_STR]){//Task 1
//This functions takes a filename and opens it in read mode either returns null if file cannot or returns the a file pointer
    FILE *fptr;

    fptr = fopen(fileName,"r"); //Opens the file in read mode

    if(fptr == NULL){ //If the file is null returns that
        return NULL;
    }

    else{
        return fptr; //Otherwise returns the file pointer
    }
}

int readCourse (char filename [MAX_STR], struct courseStruct courseInfo [NUMBER_COURSES]){//Task 2
/*This function takes a filename from the command line and it takes data from these file and populate the courseInfo struct

It returns 1 if populating the struct was succesful, returns -1 if passing  NULL to the file pointer, or if there are more or less
than 2 times NUMBER_COURSES amount of lines in the file
*/
    FILE *fptr;
    FILE *fptr2;

    fptr = openFileForReading(filename); //Two different file pointer one for counting the lines the other for populating
    fptr2 = openFileForReading(filename);

    int count = 0; //counter variable
    char tempstore[100*MAX_STR]; //Temperoary Variable to store the data

    while(fgets(tempstore,MAX_STR,fptr2)!= NULL){//Runs till the end of file

       count++; //Counts every time a newline happens
    }

    if(fptr == NULL){ //Checks if the file is NULL of doesn't have enough lines then returns -1
        return -1;
    }
    else if(count != 2*NUMBER_COURSES){
        return -1;
    }
    else{//If it doesn't then populates the struct
        for(int i=0; i<NUMBER_COURSES; i++){//First loop to take in the course names and store it in courseInfo.courseName
            fgets(courseInfo[i].courseName,MAX_STR,fptr);
            int j = 0;
            j = strlen(courseInfo[i].courseName); //Using fgets stores the new line so we get the lenght of the string then remove it using \0
            courseInfo[i].courseName[j-1] = '\0';  
        }
        for(int i=0; i<NUMBER_COURSES; i++){//Then it stores the courseID using fscanf in courseInfo.courseID
            fscanf(fptr,"%d",&courseInfo[i].courseID);
        }
     
        return 1;
    }
    
    fclose(fptr);//Closes the file
}

int readProfAndCoursesTaught (char filename [MAX_STR],struct profStruct profInfo [NUMBER_PROFS],struct courseStruct courseInfo [NUMBER_COURSES]){//Task 3
/*
This function populates the profStruct from the file using the command line arguement, stores the prof name, and course code that they teach
*/
    FILE *fptr;

    fptr = openFileForReading(filename); 

    if(fptr == NULL){
        return -1;
    }
    else{

        char courseTaught [NUMBER_PROFS] [NUMBER_COURSES];//Stores the yes or no values for each prof

        for(int i=0; i<NUMBER_PROFS; i++){
            fscanf(fptr,"%s",profInfo[i].profName); //Stores the prof name in the struct
        }

        for(int j=0; j<NUMBER_PROFS; j++){
            fscanf(fptr,"%s",courseTaught[j]); //Stores the yes or no value in the string array
        }

         int count = 0;//Counter variable for index

         for(int i=0; i<NUMBER_PROFS; i++){
            count =0;
            for(int j=0; j<NUMBER_COURSES; j++){

                if(tolower(courseTaught[i][j]) == 'y'){//If it is a y it stores the course code for that prof if they teach the course
                    profInfo[i].coursesTaught[count++] = courseInfo[j].courseID;
                }
                else if(tolower(courseTaught[i][j]) == 'n'){//If it is a n then it stores -1 in the array
                    profInfo[i].coursesTaught[count++] = -1;
                }
            }
           
        }
        return 1; //Returns 1 if sucessful
    }

    fclose(fptr);//Closes the file

}

int nCourses (int n,struct profStruct profInfo [NUMBER_PROFS],char profsNCourses [NUMBER_PROFS][MAX_STR]){//Task 4
/*
This function stores the profs that teach n or more courses in an array and returns the number of the profs
*/
    int nCounter = 0;//The count the amount of courses 
    int count = 0;//Counter for the array

    for(int i=0; i<NUMBER_PROFS; i++){//This loop looks at the prof
        nCounter = 0;
        strcpy(profsNCourses[i],""); //Makes the element of the profsNcourses blank
        for(int j=0; j<NUMBER_COURSES; j++){//This loop looks at their courses
            if(profInfo[i].coursesTaught[j] != -1){//If the prof teaches a course the value shouldn't be -1
                nCounter++;
            }
        }

        if(nCounter >= n){//If the prof teaches more than or equal to the n value
            strcpy(profsNCourses[count],profInfo[i].profName);//Stores the prof name in the array
            count++;
        }

    }

    return count;//After the loop it returns the number of profs
}
int getCourseName (int courseNum,char cNameFound [50],struct courseStruct courseInfo [NUMBER_COURSES]){//Task 5
/*
This function takes the course code and see if any course in the courseStruct has the same code
If it does it returns 1 and stores the name in cNameFound
else returns 0
*/

    for(int i=0; i<NUMBER_COURSES; i++){ //Loop runs through the whole struct
        if(courseNum == courseInfo[i].courseID){//If the courseNum is same as one of the struct code
            strcpy(cNameFound,courseInfo[i].courseName); //Stores the names in cNameFound
            return 1;
        }
    }

    return 0;
}

int getCourseNum (char cName [50],int * cNumFound,struct courseStruct courseInfo [NUMBER_COURSES]){//Task 6
/*
This function takes the name of a course and sees if the code exists if it does, the course code is store in int pointer
and returns 1
If it does not it returns 0
*/
    for(int i=0; i<NUMBER_COURSES; i++){
        if((strcmp(cName,courseInfo[i].courseName)) == 0){//If the course Name are the same
            *cNumFound = courseInfo[i].courseID;//It stores the course code in the pointer
            return 1;
        }
    }
    return 0;
}

int profsTeachingCourse (int courseNum,struct profStruct profInfo [NUMBER_PROFS],char taughtBy [NUMBER_PROFS][MAX_STR]){//Task 7
/*
This function takes a course Name and sees what profs teach it and stores it in an array and then return amount of the profs
that teach it
*/
    int count = 0;//Counter for the index of the array

    for(int i=0; i<NUMBER_PROFS; i++){
        strcpy(taughtBy[i],"");//Makes the values blank
        for(int j=0; j<NUMBER_COURSES; j++){
            if(courseNum == profInfo[i].coursesTaught[j]){//If the course code is the same as the course taught by the prof
                strcpy(taughtBy[count],profInfo[i].profName);//Stores the name of the prof in the array
                count++;
            }
        }
    }
    return count;//Returns the number of profs that teach the course 
}
float avgNumCourses (struct profStruct profInfo [NUMBER_PROFS]){//Task 8
//This function tells us the average number of courses taught by a professor and returns the float as a rounded integer

    //Counters for the prof and the amount of courses
    float countCourses = 0;
    float countProf = 0;

    float ave;

    for(int i=0; i<NUMBER_PROFS; i++){
        countProf++;
        for(int j=0; j<NUMBER_COURSES; j++){
            if(profInfo[i].coursesTaught[j]!= -1){//If the course struct doesn't have -1 it adds to the course counter
                countCourses++;
            }
        }
    }

    ave =countCourses/countProf;//Finds the average using the counters

    float returning = ave + 1;//adds 1 because we are rounding up

    return (int)returning ;//Casts the float being returned as int because anything after decimal would be ignored
}
//End of function definitions
