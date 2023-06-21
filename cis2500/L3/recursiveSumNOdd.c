#include <stdio.h>

int recursiveSumNOdd(int n) {
    if (n == 1) {
        return 1;
    } 
    else {
        return (2 * n) - 1 + recursiveSumNOdd(n - 1); 
    }
}