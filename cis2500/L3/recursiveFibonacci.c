#include <stdio.h>

int recursiveFibonacci(int n){
    if(n <= 1){
        return n;
    }
    else{
        return(recursiveFibonacci(n-1) + recursiveFibonacci(n-2));
    }
}
