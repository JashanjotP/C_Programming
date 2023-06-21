#include <stdio.h>

int main(){
	char op;
	
	float num1;
	float num2;
	float ans;

	printf("********************\n");

	printf("Welcome to basic calculator\n");
	
	printf("Enter an operator ('+' '-' '*' '/'): ");
	scanf("%c", &op);

	printf("Enter the 1st number: ");
	scanf("%f", &num1);
 
	printf("Enter the 2nd number: ");
	scanf("%f", &num2);

	if (op == '+'){
        	ans = num1 + num2;
		printf("%f + %f = %f\n", num1 , num2, ans);
	}
	
	if (op == '-'){
		ans = num1 - num2;
		printf("%f - %f = %f\n", num1, num2, ans);
	}

	if (op == '*'){
		ans = num1 * num2;
		printf("%f * %f = %f\n" , num1, num2, ans);
	}
	if (op == '/'){

		if (num2 == 0){
			printf("Denominator cannot be 0\n");
		}

		else{
			ans = num1 / num2;
			printf("%f / %f = %f \n" , num1 , num2 , ans);
		}
	}

	if(op != '+' && op != '-' && op != '*' && op != '/'){
		printf("%c is an invalid operator\n ", op);
	}


	printf("********************\n");

   return 0 ;
}
