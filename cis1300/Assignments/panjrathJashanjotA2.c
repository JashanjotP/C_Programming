
/************************panjrathJashanjotA2.c**************
Student Name: Jashanjot Panjrath                   Email Id: jpanjrat@uoguelph.ca
Due Date: November 4th                             Course Name: CIS 1300

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
gcc -std=c99 -Wall panjrathJashanjotA2.c main.c

Running: ./a.out

OR

gcc -std=c99 -Wall panjrathJashanjotA2.c main.c -o assn2

Running the Program: ./assn2
*********************************************************/

/*This program does different problem solving questions involving.
For example checking if it is a base pair, dna sequence, and etc. 
The program gives different output based on what it is called for*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define SIZE 100
#define NUMPROTEINS 64
bool isBasePair (char neu1, char neu2);
bool isItaDnaSequence (char strand1 [SIZE], char strand2 [SIZE]);
void reverse (char aStrand [SIZE]);
void complementIt (char aStrand [SIZE]);
bool isItPalindrome (char aStrand [SIZE]);
bool isStrandDnaPalindrome (char aStrand [SIZE]);
int howMany (char aStrand [SIZE], char neu);
void dnaToMrna (char aSeq [SIZE], char mRNA [SIZE]);
void translateDnaToMrnaProteins (char aSeq [SIZE]);

char getCode (char protein [3]);
int main(){

char str1 [SIZE];
strcpy(str1,"CGTAGGCAT");
//char str2 [SIZE] = "CGTAGGCAT";
translateDnaToMrnaProteins(str1);
//translateDnaToMrnaProteins(str2);
}

bool isBasePair (char neu1, char neu2){ //this function is a bool and takes two nucleodites and returns true if they are base pairs
  
   if( (neu1 =='A' && neu2 == 'T') || (neu1 =='T' && neu2 == 'A')){ //checks if either one is A and the other is T
      return true;
    }

   else if( (neu1 =='G' && neu2 == 'C') || (neu1 =='C' && neu2 == 'G')){ //Same thing above for C and G
      return true;
    }

   else{
      return false;
    }

}

bool isItaDnaSequence (char strand1 [SIZE], char strand2 [SIZE]){ //This function is a bool and returns true if two strands dna follows same format as above


    int check;

    int length = strlen(strand1);
    
    for(int i=0; i<length; i++ ){ //This loop runs through the whole dna if all the neu have a base pair in the other strand, the check becomes 1
         
         if(strand1[i] =='G' && strand2[i]=='C'){
            check=1;
         } 
         else if(strand1[i]=='C'&& strand2[i]=='G'){
            check=1;
         }
         else if(strand1[i]=='A'&& strand2[i]=='T'){
            check=1;
         }
         else if(strand1[i]=='T'&& strand2[i]=='A'){
            check=1;
         }
         else{
            check=0;
            
         }
       

    }
    if(check==1){ //If the check is 1 then it returns true 
        return true;
    }

    return false;  
              
    }

void reverse (char aStrand [SIZE]){//This function is a void and it just reverses a strand
    
    char reversed[SIZE];

    strcpy(reversed, aStrand);  //Makes a new dna strand same as the given parameter

    int length = strlen(aStrand);

    int k= length -1;
    for(int i=0; i<length; i++){ //This loop makes the first character equal to the last character and keeps on going
            
         aStrand[i]=  reversed[k];
          k--;
         }

}

void complementIt (char aStrand [SIZE]){ //This function is a void it make a C into G, A into T, and vice versa in a strand

    int length = strlen(aStrand);

    for(int i=0; i<length; i++){ //The loop runs for the whole strand, wherever it sees a C it turn into a G, A into T and vice versa
        if(aStrand[i]== 'C'){
            aStrand[i] = 'G';
        }
        else if(aStrand[i]== 'G'){
            aStrand[i] = 'C';
        }
        else if(aStrand[i]== 'A'){
            aStrand[i] = 'T';
        }
        else if(aStrand[i]== 'T'){
            aStrand[i] = 'A';
        }
    }  
}

bool isItPalindrome (char aStrand [SIZE]){ //This function takes a strand and check if it is a palindrom
   
   char reversed [SIZE];

   strcpy(reversed, aStrand); //Makes a new same strand called reversed

   reverse(reversed); //Reverses the strand using the function that was previously defined

   int result= strcmp(aStrand, reversed); //This is comes the reversed strand with the origal

   if(result == 0){ //Returns true if result is zero
      return true;
   }
   else{
      return false;
   }
}

bool isStrandDnaPalindrome (char aStrand [SIZE]){//This function is bool and returns true if the stand is a dnastrand Palindrome

    char complement [SIZE];
    char reversed [SIZE];

    strcpy(complement, aStrand); //Makes two strands same as the parameter
    strcpy(reversed, aStrand);

    complementIt(complement); //Complements one strand using the complementIt function
    reverse(reversed); //Reverses one using the reverse function

    int result = strcmp(reversed, complement); //Compares the complement and the reversed strand using strcmp

    if(result == 0){ //If the result is zero then return true
        return true;
    }
    else{
        return false;
    }
}

int howMany (char aStrand [SIZE], char neu){ //This function is a int and returns how many nucleodites are in a dna strand

    int length = strlen(aStrand);

    int totalNeu = 0; 

    for(int i=0; i<length; i++){  //This loop runs throught the entire and anytime it sees that nucleodite it adds 1
        if(aStrand[i] == neu){
            totalNeu++;
        }
    }

    return totalNeu; //Returns the total
}

void dnaToMrna (char aSeq [SIZE], char mRNA [SIZE]){ //This function is a void and converts the dna of aSeq and makes the mRNA and puts it into mRNA
    
   

    complementIt(aSeq); //Takes the complement of aSeq using complementit function
    strcpy(mRNA, aSeq); //Copies the complement into the mRNA 

    int length = strlen(mRNA);
    for(int i=0; i<length; i++){
        
        if(mRNA[i] == 'T'){ //Wherever it see the T it replaces it with a U
            mRNA [i] = 'U';
        }
        
    }  
}

void translateDnaToMrnaProteins (char aSeq [SIZE]){
    
    printf("DNA: %s\n", aSeq); //Prints the DNA
  
  
    char mRNA [SIZE]; //A new Mrna strand
    
    dnaToMrna(aSeq,mRNA); //convert to mrna using the function

    printf("mRNA: %s, which translates to: \n",mRNA);
    char protein [3];

    int mrnaLength = strlen(mRNA);

    char result;

    for(int i=0; i+3<=mrnaLength;i=i+1){ //This loop breaks the mrna into 3 peices and finds its amino acid, if it only has 2 neu it stops
         
        for(int j=0; j<3; j++){
           
            protein [j] = mRNA [i+j];
            result = getCode(protein);
        }
    
        i++; i++; 
        protein[3]='\0'; //Leaves a space after the third neu
        printf("%s: %c\n", protein,result ); //Prints the three neu protein and its amino acid
    }
       if(result == 'Z' ){ 
          printf("The input sequence has an incorrect base");
       }
}

char getCode (char protein [3]) {

    // array allProteins has a list of all 3-triplet amino acids required for this assignment
    
    char allProteins [NUMPROTEINS][SIZE] = {"GCA", "GCC", "GCG", "GCU", "AGA","AGG", "CGA", "CGC","CGG","CGU","GAC", "GAU","AAC","AAU","UGC","UGU","GAA","GAG","CAA","CAG", "GGA", "GGC","GGG","GGU","CAC", "CAU","AUA","AUC","AUU", "UUA", "UUG","CUA","CUC", "CUG", "CUU", "AAA", "AAG","AUG", "UUC","UUU", "CCA", "CCC", "CCG", "CCU", "AGC","AGU","UCA","UCC","UCG", "UCU","ACA","ACC","ACG", "ACU", "UGG","UAC","UAU", "GUA","GUC","GUG", "GUU"};
    
    // array allCodes stores the single-letter code of each triplet given in the above array
    
    char allCodes [NUMPROTEINS] = {'A','A','A','A','R','R','R','R','R','R','D','D','N','N','C','C','E','E','Q','Q', 'G','G','G','G','H','H','I','I','I', 'L','L','L','L','L','L','K','K','M','F','F','P','P','P','P','S','S','S','S','S','S','T','T','T','T', 'W','Y','Y','V','V','V','V'};
    
    for (int i = 0; i < NUMPROTEINS; i++) {
        
        if  (strncmp (protein, allProteins[i], 3) == 0) {
            return allCodes [i];
        }
    }
    
    return 'Z';   // to indicate an incorrect code - code that doesn't exist in array allCodes
}

