/************************panjrathJashanjotDIYL5.c**************
Student Name: Jashanjot Panjrath                               Email: jpanjrat@uoguelph.ca
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

gcc -std=c99 -Wall panjrathJashanjotDIYL4.c

Running: ./a.out

OR
gcc -std=c99 -Wall panjrathJashabjotDIYL4.c -o DIYL4

Running the Program: ./DIYL4
*********************************************************/

#include <stdio.h>

void printProvince(int);     

int main(){
    
    int i;
    float population [13];
    float totalPopulation = 0; 

    for( i=0; i<13; i++){ //Loop to run for all 13 provinces
        
        printf("[%d.] ",i+1); 
        printProvince(i); //Function call and prints the name first then ask for population and stores in array
        scanf("%f",&population[i]);
        totalPopulation = totalPopulation + population[i]; //Keeps on adding population from each input entered
    }
    
    for(i=0; i<50; i++){
        printf("*");
    }

    printf("\n");

    float averagePopulation = totalPopulation / 13; //Calculates the average

    float highest = population[0]; //The highest number is set to the first element
    int locationHighest; //For finding index of the highest

    for(int k =0; k<13;k++){ //Runs throught the whole array of population

        if(highest < population[k]){ //Compares with all of them and if some other element is the highest that becomes the new highest
            highest = population[k];
            locationHighest = k; //Then whatever is the new highest stores its index
        }
    }

    float lowest = population[0]; //It is the same type method for finding the highest number and index
    int locationLowest;

    for(int j =0; j<13;j++){

        if(lowest > population[j]){ //Instead it runs and check which one is lower and that becomes the new lowest 
            lowest = population[j];
            locationLowest = j; //Same with the index
        }
    }
   
    //All the required output with its values
    printf("Average Population in Canada = %.2f million\n",averagePopulation);
    printProvince(locationHighest);
    printf("has the highest population\n");
    printf("Highest Population = %.2f million\n",highest);
    printProvince(locationLowest);
    printf("has the lowest population\n");
    printf("Lowest Population = %.2f million\n",lowest);

    for(i=0; i<50; i++){
        printf("*");
    }
    return 0;
}

void printProvince(int name){  //This function prints the province or territory name depending on the number entered

    if(name == 0){
        printf("Alberta: ");
    }
    else if(name == 1){
        printf("British Columbia: ");
    }
    else if(name == 2){
        printf("Manitoba: ");
    }
    else if(name == 3){
        printf("New Brunswick: ");
    }
    else if(name == 4){
        printf("Newfoundland: ");
    }
    else if(name == 5){
        printf("Northwest Territory: ");
    }
    else if(name == 6){
        printf("Nova Scotia: ");
    }
    else if(name == 7){
        printf("Nunavut: ");
    }
    else if(name == 8){
        printf("Ontario: ");
    }
    else if(name == 9){
        printf("Prince Edward Island: ");
    }
    else if(name == 10){
        printf("Quebec: ");
    }
    else if(name == 11){
        printf("Saskatchewan: ");
    }
    else if(name == 12){
        printf("Yukon: ");
    }
}