#include <stdio.h>
#define Pi 3.14

   int main(){
	float radiusVar;
      
	printf("Enter the radius: \n");  
	scanf("%f", &radiusVar);   

	float area = Pi *( radiusVar * radiusVar);
	float Circumfrence = 2 * Pi * radiusVar;

	printf("Area is:%f \n",area);
	printf("Circumference is: %f \n", Circumfrence); 



	return 0;

}
