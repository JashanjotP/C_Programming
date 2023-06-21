#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main ( ) 
{
    
    char *ptr;
    
    ptr = malloc ( sizeof(char)*10 );
    strcpy ( ptr, "Ritu" );
    printf ( "%s (%p)\n\n", ptr, &ptr );
    
    ptr = realloc ( ptr, sizeof(char)*20000 );
    printf ( "%s (%p)\n\n", ptr, &ptr );
    
    ptr[2]='\0';
    ptr = realloc ( ptr, sizeof(char)*3 );
    printf ( "%s (%p)\n", ptr, &ptr );

    free(ptr);
    
    return 0;
    
}
