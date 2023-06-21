#include <stdio.h>

int iterativeFibonacci(int n){

    int fib[n];

    if(n==1 || n==2){
        return 1;
    }

    fib[0]=0;
    fib[1]=1;
    
    for(int i=2; i<=n; i++){
        fib[i] = fib[i-1]+fib[i-2];
    }

    return fib[n];
}

