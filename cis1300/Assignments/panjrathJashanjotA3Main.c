/************************panjrathJashanjotA3Main.c**************
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

int main (int argc, char * argv[]) {

   //All variables that are used
    
    int country [COUNTRIES][MEDALCAT];
    
    char countryNames [COUNTRIES][MAX_LENGTH_CNAME];

    int totalAllCountries [COUNTRIES];

    int totalAllMedals [MEDALCAT];
    
    int choice;

    int whichMedal;

    int value;

    int maximum;

    char countryName [MAX_LENGTH_CNAME];

    int indexMedal;

    int indexOfCountries [COUNTRIES];

    int medalCase8;

    int medalCase9;

    int minOrMax;

    int valueFun10;
   
    do {//Menu choices
        printf ("\nHere is the menu \n\n");
        printf ("1. Display all country names read from file and the total number of medals won by each\n");
        printf ("2. Function 2 - Find total number of medals won by each country\n");
        printf ("3. Function 3 - Finds total number of medals in each category (Gold, Silver, Bronze)\n");
        printf ("4. Function 4 - Display horizontal histogram\n");
        printf ("5. Function 5 - Search for a country and return the total number of medals won by it\n");
        printf ("6. Function 6 - Rank and display top three countries in order of total medals won\n");
        printf ("7. Function 7 - Rank and display top three countries in order of total gold medals won\n");
        printf ("8. Function 8 - Find and display all countries that won no X medals, given X as either Gold, Silver or Bronze\n");
        printf ("9. Function 9 - Find and display all countries that won ONLY X medals, given X as either Gold, Silver or Bronze\n");
        printf ("10.Function 10- Find and display name of the country that has minimum or maximum length among all countries read in option 1\n"); 
        printf ("11.Exit\n");
        
        printf ("\nEnter your choice: ");//Asks for the choice
        scanf ("%d", &choice);
        
        
        switch (choice) {
            case 1://When 1 is pressed it reads the file using the function
              
                readFromFile(argv[1],country,countryNames);

                printf("Country:      Gold:  Silver:   Bronze:\n");
                
                for(int i=0; i<COUNTRIES;i++){
                    printf("%s:   \t",countryNames[i]); //This nested loop prints the country names and the medals

                    for(int j=0; j<MEDALCAT; j++){
                        printf("%d    \t",country[i][j]);
                    }
                    
                    printf("\n");
                }

            break;

            case 2://When 2 is pressed it find the total medal per country
                 
                 findTotalPerCountry (country, totalAllCountries);

                 printf("In findTotalPerCountry\n");

                 printf("Country: \n");

                  for(int i=0; i<COUNTRIES;i++){//Displays the country name and how many medals they have won in total
                    printf("%s:  \t",countryNames[i]);
                    printf("%d\t\n",totalAllCountries[i]);
                  }

                
            break;

            case 3://When 3 is pressed it find the total gold, silver and bronze

               maximum = findTotalPerMedal (country ,totalAllMedals , &whichMedal);//Stores the highest medal in maximum


               printf("In findTotalPerMedal\n");

               printf("Gold = %d\n",totalAllMedals[0]);//Prints out the total per medal
               printf("Silver = %d\n",totalAllMedals[1]);
               printf("Bronze = %d\n",totalAllMedals[2]);

               printf("Maximum Medal = %d in category (",maximum);//Prints the maximum

               if(whichMedal == 0){//Depending on the index prints that type of medal
                printf("Gold)\n");
               }
               else if(whichMedal ==1){
                printf("Silver)\n");
               }
               else if(whichMedal ==2){
                printf("Bronze)\n");
               }

                   
            break;

            case 4://When 4 is entered prints the histogram

               printf("Printing Histogram\n");

               printf("In hHistogram\n");

               hHistogram(countryNames,totalAllCountries);

                break;

               case 5://When 5 is entered it asks for the country they are looking for and gives the total medals

               printf("Searching for which country: ");
               scanf("%s",countryName);

               printf("In searchCountry \n");

               value =searchCountry(countryName,countryNames,totalAllCountries);//Stores the total medals in value

               if(value == -1){//If value is -1 then the country does not exist
                  printf("Country name cannot be found in the database\n");                  
               }

               else{
                  printf("Found it - %s has a total of %d medals\n",countryName,value);
               }

                break;

            case 6://When 6 is entered it ranks the top three countries based on the total medals

                printf("Ranks top three based on the total number of medals\n");

                rankTopThreeByTotal(totalAllCountries, countryNames);


                break;

            case 7://When 7 is entered it prints the top three countries based on the gold medals

                printf("Rank top three based on Gold medals\n");

                rankTopThreeByMedal(country, countryNames);

                break;

            case 8://Asks for which medal they are looking for and prints the countries that dont't have that type of medal

                printf("Which medal do you want to look (1 for Gold, 2 for Silver, 3 for Bronze): ");
                scanf("%d", &indexMedal);

                medalCase8 = findAllWithNoXMedals(country,indexMedal,indexOfCountries);//Stores how many countries don't have that type of medal

                printf("Number of countries with no ");

                if(indexMedal == 1){//Depending on what is asked for that gets printed
                printf("Gold medals = ");
               }
               else if(indexMedal == 2){
                printf("Silver medals = ");
               }
               else if(indexMedal ==3){
                printf("Bronze medals = ");
               }
               printf("%d\n",medalCase8);

               for(int j=0; j<medalCase8; j++){//The print for the arrays goes till the medalCase8 and prints the countries
                  printf("%s\n",countryNames[indexOfCountries[j]]);
               }

               break;

             case 9://This asks for the type of medals and prints the countries that only have that type

                printf("Which medal do you want to look (1 for Gold, 2 for Silver, 3 for Bronze): ");
                scanf("%d", &indexMedal);

                medalCase9 = findAllWithOnlyXMedals(country,indexMedal,indexOfCountries);//Stores the value in medalCase9

                printf("Number of countries with ONLY ");

                if(indexMedal == 1){//Type of medal based on the input
                printf("Gold medals = ");
               }
               else if(indexMedal == 2){
                printf("Silver medals = ");
               }
               else if(indexMedal ==3){
                printf("Bronze medals = ");
               }
               printf("%d\n",medalCase9);

               for(int j=0; j<medalCase9; j++){//Pritns the stored indexes upto medalCase9
                  printf("%s\n",countryNames[indexOfCountries[j]]);
               }

                break;

             case 10://When 10 is entered it asks if the user wants find the country with a min or max length

                printf("Do you want min(enter 1) or max(enter 2): ");
                scanf("%d",&minOrMax);

                valueFun10 = findCountryIndexWithMinOrMaxLength(minOrMax,countryNames);//Stores the index of that country in ValueFun10

                if(minOrMax == 1){//depending on what the user entered prints that country
                    printf("The country name with Minimum Length = %s\n",countryNames[valueFun10]);
                }
                else if(minOrMax == 2){
                    printf("The country name with Maximum Length = %s\n",countryNames[valueFun10]);
                }

                break;
            case 11:

            break;
            
            default: printf ("That is an invalid choice\n");//Any choice other than 1 to 11
                
        }
        
    } while (choice != 11);
    
    
   return 0;
}

//End of main
