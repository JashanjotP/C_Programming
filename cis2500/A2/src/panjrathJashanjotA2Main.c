#include "../include/panjrathJashanjotA2.h" //Header file

int main(int argc, char * argv[]){

    // variables used
  /*  char *content;
    char *go;
    char *go2;
    int numWords;
    int numSentences;
    char *breath;
    char *breath2;
    char **sptr;
    char **sptr2;
    char **sptr3;
    char **sptr4;
    int a;

    printf("Function 1\n");

    content = readFile(argv[1]); //Reads the content from the file given from the command line

    printf("%s\n",content); //Displays the content


    printf("\nFunction 2\n");

    
    dejaVu(content, &numWords, &numSentences); 
    //Reads how many words and sentencesin the string
    printf("\n");
    char *words = "    My,   name is   Name.... .    ,edhedued     dyeeddeh.      ";//Another test case
    printf("%s\n",words);
    dejaVu(words, &numWords, &numSentences);


    printf("\nFunction 3\n");

    char * words2 = "hello!";
    char * words3 = "2as .;?:!";
    
    go = goBig(words2); //Stores the strings that gets extended in go and prints it
    printf("%s\n",go);
    free(go);

    go2 = goBig(words3);//Another test case
    printf("%s\n",go2);
    free(go2);


    printf("\nFunction 4\n");

    sptr = goAway("Oh , it was red!",&a); //Stores the sepreated words into sptr

    for(int i=0; i<a; i++){
        printf("%s\n",sptr[i]); //prints the string

    }
 
    printf("Words: %d\n",a);
    //More test cases below
    sptr2 = goAway("Oh, it was red!",&a);

    for(int i=0; i<a; i++){
        printf("%s\n",sptr2[i]);
        
    }

 
    printf("Words: %d\n",a);

    sptr3 = goAway(" Oh,    it   was     red!",&a);

    for(int i=0; i<a; i++){
        printf("%s\n",sptr3[i]);
    }
  
 
    printf("Words: %d\n",a);

     sptr4 = goAway("The red readymade dress was made for you! It was going to be ready tomorrow. What was the colour of the dress? Oh, it was red!",&a);

    for(int i=0; i<a; i++){
        printf("%s\n",sptr4[i]);
        
    }
 
    printf("Words: %d\n",a);


    printf("\nFunction 5\n");

    breath = breathless("What was the colour of the dress? Oh, it was red!");//Stores the string no punctutation in breath
    printf("%s\n",breath);//Prints it

    //Another test case
    breath2 = breathless("Contemplating: life'!s m!eaning, I w:ond!er: is the;r;e more ou!t there?");
    printf("%s\n",breath2);

    printf("\nFunction 6\n");    

    //Finds the word from the sentence and for each character puts the suffix
    tail("Now     is    the     winter    of    our      discontent    Made   glorious summer by this Sun of York.", 15,"otter");
    printf("\n");
    tail("Now      is         the  winter       of our discontent Made glorious summer by this Sun of York.", 1,"otter");
    printf("\n");
    tail("Now         is    the        winter of our      discontent       Made         glorious summer by this Sun of York.", 8,"otter");*/

    char* value = breathless("What was the colour of the dress? Oh, it was red!");

    int v = strlen(value);

    printf("%s\n",value);

    printf("%d\n",v);

    return 0;
}
