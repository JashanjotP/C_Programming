#include <stdio.h>
#include <time.h>

int iterativeFibonacci(int n);
int recursiveFibonacci(int n);
int iterativeSumNOdd(int n);
int recursiveSumNOdd(int n);

int main(){

   double time_elapsed  = 0.0;
   double time_elapsed2 = 0.0;
   double time_elapsed3 = 0.0;
   double time_elapsed4 = 0.0;

   clock_t begin, end;
   clock_t begin2, end2;
   clock_t begin3, end3;
   clock_t begin4, end4;

   int n;

   printf("Enter the input value: ");
   scanf("%d",&n);

   begin = clock();
   int value  = iterativeFibonacci(n);
   end = clock();

   time_elapsed += (double)(end - begin) / CLOCKS_PER_SEC;

   begin2 = clock();
   int value2 = recursiveFibonacci(n);
   end2 = clock();

   time_elapsed2 += (double)(end2 - begin2) / CLOCKS_PER_SEC;

   begin3 = clock();
   int value3 = iterativeSumNOdd(n);
   end3 = clock();

   time_elapsed3 += (double)(end3 - begin3) / CLOCKS_PER_SEC;

   begin4 = clock();
   int value4 = recursiveSumNOdd(n);
   end4 = clock();

   time_elapsed4 += (double)(end4 - begin4) / CLOCKS_PER_SEC;


   printf("********************************\n");
   printf("The sum of odd integers using itteration is: %d\n",value3);
   printf("Time elapsed for iterative sum is %lf seconds\n",time_elapsed3);
   printf("The sum of odd integers using recursion is: %d\n",value4);
   printf("Time elapsed for recursive sum is %lf seconds\n",time_elapsed4);

   printf("********************************\n");

   printf("Iteratively, Fibonnaci(%d) = %d\n",n,value);
   printf("Time elapsed for iterative Fibonnaci is %lf seconds\n",time_elapsed);
   printf("Recursively, Fibonnaci(%d) = %d\n",n,value2);
   printf("Time elapsed for iterative Fibonnaci is %lf seconds\n",time_elapsed2);
   printf("********************************\n");

   return 0;
}

