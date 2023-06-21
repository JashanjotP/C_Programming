#include <stdio.h>
#define Pi 3.14 

int main(){

     int choice;
     float radius, area, circumfrence;
     char ans;

     printf("Which loop do you want to use (1,2,3): ");
     scanf("%d", &choice);

     printf("\n");

     if(choice == 1){

     printf("This loop runs 3 times \n");

     printf("\n");

     int number = 1;

     while(number <=3){

          printf("Enter radius: ");
          scanf("%f", &radius);

          area = Pi*(radius * radius);
          circumfrence = 2 * radius * Pi;

          printf("Area = %f\n", area);
          printf("Circumference = %f\n", circumfrence);

          printf("\n");

          number++;
          }

     }

     if(choice == 2){

     printf("This loop runs until the radius entered is -1\n");
     printf("\n");

     radius = 0;

     printf("Enter radius: ");
     scanf("%f", &radius);

     while (radius >=0){


          area = Pi*(radius * radius);
          circumfrence = 2* radius * Pi;

          printf("Area = %f\n", area);
          printf("Circumfrence = %f\n", circumfrence);

          printf("Enter radius: ");
          scanf("%f", &radius);

          }

         printf("\n");
     }

       if(choice == 3){

       ans = 'y';

       while(ans == 'y'){

           printf("Enter radius: ");
           scanf("%f", &radius);

           area = Pi*(radius * radius);
           circumfrence = 2 * radius * Pi;

           printf("Area = %f\n", area);
           printf("Circumfrence = %f\n", circumfrence);

           printf("Would you like to continue (y/n): ");
           scanf(" %c",&ans);
           printf("\n");

          }
   }

   return 0;
}
