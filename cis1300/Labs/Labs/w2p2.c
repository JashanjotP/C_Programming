#include <stdio.h>

int main(){

	int givenAmount;

	int bill100, bill50, bill20, bill10, bill5, leftOver;

	printf("Enter an amount:\n");
	scanf("%d", &givenAmount);

        bill100 = givenAmount / 100;
	givenAmount = givenAmount % 100;

        bill50 = givenAmount / 50;
	givenAmount = givenAmount % 50;

	bill20= givenAmount / 20;
	givenAmount = givenAmount % 20;

	bill10 = givenAmount / 10;
	givenAmount = givenAmount % 10;

	bill5 = givenAmount / 5;
	givenAmount = givenAmount % 5;

	leftOver = givenAmount; 

	printf("$100 bills: %d\n" ,bill100);
	printf("$50 bills: %d\n" ,bill50);
	printf("$20 bills: %d\n" ,bill20);
	printf("$10 bills: %d\n" ,bill10);
	printf("$5 bills: %d\n" ,bill5);
	printf("Remaining bills: %d\n" ,leftOver);





return 0;

}
