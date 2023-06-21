/************************panjrathJashanjotA3.c**************
Student Name: Jashanjot Panjrath           Email Id: jpanjrat@uoguelph.ca
Due Date: November 30, 2022                Course Name: CIS 1300

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

The program should be compiled using the following flags: -std=c99 -Wall

compiling:

gcc -std=c99 -Wall panjrathJashanjotA3.c panjrathJashanjotA3Main.c
Running: ./a.out

OR

gcc -std=c99 -Wall panjrathJashanjotA3.c panjrathJashanjotA3Main.c -o assn3
Running the Program: ./assn3
*********************************************************/
#include "givenA3.h"

void readFromFile (char fName [30], int country [COUNTRIES][MEDALCAT], char countryNames [COUNTRIES][MAX_LENGTH_CNAME]){
//This function opens the file and stores the data in two different arrays
    FILE *fptr;

    fptr = fopen(fName,"r"); //Opens the file and reads it and taking the file name from the command line arguement

    if (fptr == NULL) { //If file has an error or does not exist
        printf("Could not open the file\n");     
    }

    else{

         //This loop runs till the end of the file and stores the country name in the countryName array
            int i=0;

            while(!feof(fptr)){
               fscanf(fptr,"%s",countryNames[i]);

               for(int j=0; j<MEDALCAT;j++){ //Then it also has a nested loop to store the integers in a 2D array
                   fscanf(fptr,"%d",&country[i][j]);
            }
            i++;
            }
        }

        fclose(fptr); //closes the file
}

void findTotalPerCountry (int country [COUNTRIES] [MEDALCAT],int totalAllCountries [COUNTRIES]){
//This functions finds the total medals won by each country
   

    for(int i=0; i<COUNTRIES; i++){ //Nested for loop the outer one runs through all countries

          totalAllCountries[i] =0;//Every new one starts at zero
        

        for(int j=0; j<MEDALCAT; j++){//Inner loop goes from gold to BronzeMedal
            totalAllCountries[i] = totalAllCountries[i] + country[i][j];//Every time it adds all the medals
        }

    }

}

int findTotalPerMedal (int country [COUNTRIES][MEDALCAT],int totalAllMedals [MEDALCAT], int *whichMedal){
//This function find the total gold, silver and Bronze won by everybody it return the highest of them all and also its index using a pointer
    for(int i=0; i<MEDALCAT; i++){

        totalAllMedals[i] =0; //The logic is preety much same as the above just the outer loop goes till the medals
        

        for(int j=0; j<COUNTRIES; j++){//The inner loop for all countries because this one needs to be done first
            totalAllMedals[i] = totalAllMedals[i] + country[j][i];
        }
       
    }
    
    int highest = 0;

    for(int i=0; i<MEDALCAT;i++){//After the array is populated the loop runs through the whole

        if(totalAllMedals[i]>highest){//Whenever something is bigger it becomes the biggest and the pointer stores its index
            highest = totalAllMedals[i];
            *whichMedal = i;
        }
    }
    
    return highest; //Then it returns the highest medal category

}
void hHistogram (char countryNames [COUNTRIES][MAX_LENGTH_CNAME], int totalMedals[COUNTRIES]){
//This function prints a histogram based on how many medals a country has won
    int starTotal;
//It prints half the amount of stars of the total but prints just one more if it is not even
    for(int i=0; i<COUNTRIES; i++){//Runs through the whole array
        starTotal = 0;

        printf("%-10s: ",countryNames[i]);//Prints the country name first

        starTotal = (totalMedals[i]/2)+(totalMedals[i] % 2);//Then it divides by 2 and also takes modulus 2 and adds it

        for(int j=0; j<starTotal; j++){
            printf("*");//It prints that many amount of stars
        }
        printf(" (%d)",totalMedals[i]);//Also prints how many medals they have won beside the stars
        printf("\n");

    }
}

int searchCountry (char countryName [MAX_LENGTH_CNAME],char countryNames [COUNTRIES][MAX_LENGTH_CNAME],int totalAllCountries [COUNTRIES]){
//This function searches for the country entered and returns the total medals won by it 
    for(int i=0; i<COUNTRIES; i++){//This run through the whole array
        if(strcmp(countryName,countryNames[i])==0){//When the country entered matches anywhere in the array 
            return totalAllCountries[i];//Returns the total medals won by that country
        }        
    }
    return -1;//If this doesn't it returns-1
}
    
void rankTopThreeByTotal (int totalMedals[COUNTRIES], char countryNames [COUNTRIES][MAX_LENGTH_CNAME]){
//This function ranks the top three countries based on their total medals won and prints them
    int first =0;//All the variables to be used
    int firstIndex;
    int second =0;
    int secondIndex;
    int third =0;
    int thirdIndex;

    for(int i=0; i<COUNTRIES; i++){//It is kind of similar to finding the highest number but we added a few more things

        if(totalMedals[i]>first){//We find the highest medal and store its index
            first = totalMedals[i];
            firstIndex = i;
        }
        
        else if(totalMedals[i]>second && first > second){//We do the same thing but this time the number should be smaller than the biggest number
            second = totalMedals[i];
            secondIndex = i;
        }
        else if(totalMedals[i]>third && first > third && second>third){/*Same thing above but it should be smaller than 
the biggest and the second biggest*/
            third = totalMedals[i];
            thirdIndex = i;
        }
        
    }
    printf("%s (%d) \n",countryNames[firstIndex],first);//Then it prints those values and their respected countries
    printf("%s (%d) \n",countryNames[secondIndex],second);
    printf("%s (%d) \n",countryNames[thirdIndex],third);
    
}

void rankTopThreeByMedal (int country [COUNTRIES][MEDALCAT],char countryNames [COUNTRIES][MAX_LENGTH_CNAME]){
//Similiar function but it prints the top three based on the gold medals won
    int first =0;
    int firstIndex;
    int second =0;
    int secondIndex;
    int third =0;
    int thirdIndex;

    for(int i=0; i<COUNTRIES; i++){

        if(country[i][0]>first){//Same type of loop and logic but this time it is a 2D so the 2nd value stays zero because gold medals are represented
            first = country[i][0];
            firstIndex = i;
        }
        
        else if(country[i][0]>second && first > second){
            second = country[i][0];
            secondIndex = i;
        }
        else if(country[i][0]>third && first > third && second>third){
            third = country[i][0];
            thirdIndex = i;
        }
        
    }
    printf("%s (%d) \n",countryNames[firstIndex],first);
    printf("%s (%d) \n",countryNames[secondIndex],second);//Prints those values
    printf("%s (%d) \n",countryNames[thirdIndex],third);

}

int findAllWithNoXMedals (int country [COUNTRIES] [MEDALCAT], int indexMedal, int indexOfCountries [COUNTRIES]){
//This function check whcih countries have no gold, silver or bronze medals and stores the index of those countries and return the total countries
    int countryCounter = 0;
    
    for(int i=0; i<COUNTRIES; i++){

        if(indexMedal == 1){//When is it gold
            if(country[i][0] == 0){//Checks when no gold medals exist
                indexOfCountries[countryCounter] = i;//Stores the index in the array
                countryCounter++;
            }
        }
        if(indexMedal == 2){ //Does the same for Silver and Bronze
            if(country[i][1] == 0){
                indexOfCountries[countryCounter] = i;
                countryCounter++;
            }
        }
        if(indexMedal == 3){
            if(country[i][2] == 0){
                indexOfCountries[countryCounter] = i;
                countryCounter++;
            }
        }
    }

    return countryCounter;//Then returns how many total countries dont have that type of medal
}

int findAllWithOnlyXMedals (int country [COUNTRIES][MEDALCAT],int indexMedal, int indexOfCountries [COUNTRIES]){
//This function checks when it only has one type of medal stores its index and returns how may countries have it
    int countryCounter2 = 0;

    for(int i=0; i<COUNTRIES; i++){

        if(indexMedal == 1){
            if((country[i][0]!=0)&&(country[i][1] == 0)&&(country[i][2] == 0)){//Same logic as above but it checks when silver and Bronze have zero
                indexOfCountries[countryCounter2] = i;
                countryCounter2++;
            }
        }
        if(indexMedal == 2){
            if((country[i][1] != 0)&&(country[i][0] == 0)&&(country[i][2] == 0)){//Checks when gold and Bronze have zero
                indexOfCountries[countryCounter2] = i;
                countryCounter2++;
            }
        }
        if(indexMedal == 3){
            if((country[i][2] != 0)&&(country[i][0] == 0)&&(country[i][1]==0)){//Same thing when gold and silver is zero
                indexOfCountries[countryCounter2] = i;
                countryCounter2++;
            }
        }
    }

    return countryCounter2;//return the total countries that have only that type of medal
}

int findCountryIndexWithMinOrMaxLength (int minOrMax, char countryNames [COUNTRIES][MAX_LENGTH_CNAME]){
//This function checks which country depending on the user has the shortest or the longest name depending on the user
    int length;
    int max =0;
    int maxIndex=0;
    int min = MAX_LENGTH_CNAME;
    int minIndex=0;

     if(minOrMax == 1){//When min is choosen it makes the biggest possible size the min then whatever is the smaller length becomes the min
        for(int i=0; i<COUNTRIES; i++){

            length = strlen(countryNames[i]);
            if (length < min){
                min = length;
                minIndex = i;//Stores its index
            }
            
        }

        return minIndex;
    }

    else if(minOrMax == 2){//To find max

        for(int i=0; i<COUNTRIES; i++){//Makes 0 the max and whatever length is bigger that becomes the max
            length = strlen(countryNames[i]);
            if (length > max){
                max = length;
                maxIndex = i;//Stores the index
            }
            
        }

        return maxIndex;//Returns it after the loop
    }
return 0;//Return statement so it doesn't throw a warning
}
