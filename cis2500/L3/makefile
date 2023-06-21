lab3: lab3Main.o iterativeFibonacci.o recursiveFibonacci.o iterativeSumNOdd.o recursiveSumNOdd.o
	gcc -Wall -std=c99 lab3Main.o iterativeFibonacci.o recursiveFibonacci.o iterativeSumNOdd.o recursiveSumNOdd.o -o lab3

lab3Main.o: lab3Main.c
	gcc -Wall -std=c99 -c lab3Main.c

iterativeFibonacci.o: iterativeFibonacci.c
	gcc -Wall -std=c99 -c iterativeFibonacci.c

recursiveFibonacci.o: recursiveFibonacci.c
	gcc -Wall -std=c99 -c recursiveFibonacci.c

iterativeSumNOdd.o: iterativeSumNOdd.c
	gcc -Wall -std=c99 -c iterativeSumNOdd.c

recursiveSumNOdd.o: recursiveSumNOdd.c
	gcc -Wall -std=c99 -c recursiveSumNOdd.c

clean:
	rm *.o lab3