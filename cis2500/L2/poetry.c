#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

    FILE *fptr;
    fptr = fopen(argv[1],"r");

    char **sptr;
    int * iptr;

    char c;
    int linesCounter = 0;
    int linesWordCounter = 0;
    int wordsCounter = 0;
    int charCounter = 0;

    sptr = malloc(sizeof(char *)* 1);
    sptr[0] = malloc(sizeof(char)* 1);
    iptr = malloc(sizeof(int)* 1);

    while(!feof(fptr)){

        c = fgetc(fptr);
        sptr[linesCounter][charCounter] = c;

        if(c == ' '){
            wordsCounter++;
            linesWordCounter++;
        }

        charCounter++;
        sptr[linesCounter] = realloc(sptr[linesCounter],sizeof(char)*(charCounter+1));
        
        if(c == '\n'|| c=='.'){
            
            linesWordCounter++;
            wordsCounter++;
            iptr[linesCounter] = linesWordCounter;
            iptr = realloc(iptr,sizeof(int)*(linesCounter + 1));
            linesCounter++;
            sptr = realloc(sptr,sizeof(char*) * (linesCounter +1 ));
            charCounter = 0;
            sptr[linesCounter] = malloc(sizeof(char)*1);
            linesWordCounter =0;

        }
        
        
    }

    

    for (int i=0; i<linesCounter; i++){
        free(sptr[i]);
    }
    free(sptr);


    char lineName[25];
    char wordName[25];

    strcpy(lineName,"lines");
    strcpy(wordName,"words");

    if(linesCounter == 1){
        strcpy(lineName,"line");
    }
    if(wordsCounter == 1){
        strcpy(wordName,"word");
    }

    printf("There are %d %s on %d %s\n",wordsCounter,wordName,linesCounter,lineName);
    for(int i=0; i<linesCounter; i++){
        printf("%d  ",iptr[i]);
    }

    printf("\n");
    free(iptr);
    return 0;
}
