/*Name Jashanjot Panjrath
  Student No: 1222040
  email: jpanjrat@uoguelph.ca
  This program takes an array of 10 integers prints till it reaches the multiple of 11 then stops and returs the rest in main   */

#include <stdio.h>

int processArray(int toProcess[]);

int main(){

   int arr[10];

   printf("Enter your array \n");

   for(int i =0; i<10; i++){

      scanf("%d",&arr[i]);

   }

 int index =  processArray(arr);
printf("\n");
for(int j = index+1; j<10; j++){

printf(" %d", arr[j]);
}


return 0;
}


int processArray(int toProcess[10]){


    for (int i=0; i<10; i++){

         printf("%d ", toProcess[i]);

     }
     
    printf("\n");

    for(int j = 0; j<10; j++){

     
        if(toProcess[j] % 11 == 0){
          
            printf("%d ", toProcess[j]);
            return j;
        }
        else{
             
             printf("%d ", toProcess[j]);
        }
    }

printf("\n");
return 0;

}
