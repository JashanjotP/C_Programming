#include "../include/panjrathJashanjotA2.h" //Header file

char * readFile (char * filename){
    //This functions takes the filename as a parameter opens the file and stores the content on the heap using a pointer and returns that

    FILE *fptr;
    char *sptr = NULL;

    int charCount = 0;//Counter for the characters  in the file

    fptr = fopen(filename,"r"); //Opens the file in read mode

    char c;

    if(fptr == NULL){ //Check to see if file pointer is NULL
       return NULL;
    }

    while(!feof(fptr)){ //Loop to go till the end of file

      if(sptr == NULL){
         sptr = malloc(sizeof(char)); //Intial malloc
      }
      else{
         sptr = realloc(sptr, sizeof(char)*(charCount+1)); //Realloc keep on adding one new block each time after the intial allocation
       }

       c = fgetc(fptr); //Gets the character
       sptr[charCount] = c; //stores it in the pointer
       charCount++; //Character count goes up

     }

    sptr[charCount - 1] = '\0'; //Removes the junk value

    fclose(fptr); //Closes the file

    return sptr;
}
void dejaVu (char * aString, int * numWords, int * numSentences){
//This function takes a string and ouputs the number of words and sentences that are in the string

    *numWords = 0; //words and sentences counter
    *numSentences = 0;

    int len = strlen(aString);

    for(int i=0; i<len; i++){ //Loop that runs through the string

        if(isspace(aString[i])!= 0 || aString[i] == '\n'){ //When there is a blank space the word count goes up
            *numWords = *numWords + 1;
             if(aString[i] == aString[i + 1] ){//If there are two white spaces it should count as one word
                 *numWords = *numWords - 1;
            }
        }
        else if( aString [i] == '!' || aString [i] == '.' || aString [i] == ':' || aString [i] == ';' || aString [i] == '?'){
            //When there is a character that ends the sentence  the counter goes up
            *numSentences = *numSentences + 1;
            if(aString[i] == aString[i + 1] ){
                 *numSentences = *numSentences - 1;//If multiple of the same characters are together
            }
        }

    }

    if(aString[0] == ' '){ //If there is a white space in the start or the end
        *numWords = *numWords - 1;
    }
    if(aString[len -1] == ' '){
        *numWords = *numWords - 1;
    }

    *numWords = *numWords + 1; //The word that doesn't get counted

    printf("Number of words = %d\n",*numWords );//Displays the total words and sentences in the string
    printf("Number of sentences = %d\n",*numSentences);

}
char * goBig (char * aString){
    //This function takes a string and for each character in the string, add that many and returns a new extended string 

    int count = strlen(aString); //Stores the length of the string

    int * values;

    char * streched;

    streched = malloc(sizeof(char)); //Intial malloc for the new string

    values = malloc(sizeof(int) * count); //Malloc to stores the values of each indivial character

    for(int i=0; i<count; i++){//This loop asks the user for the values on how much they want to strech each character
        scanf("%d", &values[i]);
        while(values[i] <= 0){ //If the value is 0 or less, it keeps on asking the user 
            scanf("%d", &values[i]);
        }
    }

    int num = 0;

    for(int i=0; i<count; i++){ //Nested for loop looks at one character
       for(int j =0; j<values[i];j++){//This loop extends that character depending on the value enterd for it
          streched[num] = aString[i];//Stores that character
          num++;
          streched = realloc(streched,sizeof(char)*(num +1) );//Makes room for more
       }
    }

    streched[num] = '\0';

    return streched;

}

char ** goAway (char * aString, int * numWordsReturned){
//This function takes a string and splits it into n words and stores the words in a array of strings each word is seprated by white space  

    char **str ;
    str = malloc(sizeof(char*)); //Intial malloc for the double pointer

    char temp [10000];
    char delim []= " ";//Stops at the whitespace

    *numWordsReturned = 0;

    strcpy(temp,aString);//Temp stores the string

    char * token = strtok(temp,delim);//Each token stores the word before a white space, even if there are two

    int len = 0;

    while(token != NULL){ //This loop will make it go for the whole string
        len = strlen(token);//length of the current word
        str[*numWordsReturned] = malloc(sizeof(char)*(len+ 1)); //Malloc that much space and 1 more for the null character
        strcpy(str[*numWordsReturned] , token);//Stores that word into that element
        *numWordsReturned = *numWordsReturned + 1;
        str = realloc(str,sizeof(char*) * (*numWordsReturned + 1));//Reallocates for the next word
        token = strtok(NULL,delim);//Goes to the next word
    }

    return str;


}
char * breathless (char * aString){
//This function takes a string and removes the punctuations from it and returns it
    int length = strlen(aString);

    char words[10000];

    strcpy(words,aString);//copies aString into words

    char *noPun;
    for(int i =0; i<length; i++){//Loop runs through the whole string
        if(words[i] == '.' || words[i] == ':' || words[i] == ';' || words[i] == '?' || words[i] == '!'){//If there is a puncutation
           for(int j=i; j<length;j++){//This loop shifts the current character to the next character
              words[j] = words[j+1];
           }   
        }
    }

    noPun = words;//Makes the pointer equal to the newString and returns it

    return noPun;
    
}
void tail (char * aString, int whichWord, char * desiredSuffix) {
    /*This function takes a string ,a number for the word and a suffix, then finds the corresponding word with the number
       and breaks it into indiviual character and prints the suffix with it*/

    char temp [10000];
    char delim [] = " ";

    strcpy(temp ,aString);

    char *token = strtok(temp,delim);  //Token contains each word seperated with a space

    char *target;//Stores our word

    int word = 1;
    while(token != NULL){
        if(whichWord == word){ //If number mathches with the word number we want stoes the word into our target
            target = token;
        }
        word++;
        token = strtok(NULL,delim);
    }

    int len = strlen(target);

    for(int i=0; i<len; i++){ //This loop breaks into characters and prints the suffix
        if(isupper(target[i]) != 0 || islower(target[i]) != 0){
            printf("%c%s\n",target[i],desiredSuffix);
        }
    }

}
