stringMe: panjrathJashanjotA2.o panjrathJashanjotA2Main.o
	gcc -Wall -std=c99 panjrathJashanjotA2.o panjrathJashanjotA2Main.o -o stringMe
	mv stringMe bin
panjrathJashanjotA2.o: src/panjrathJashanjotA2.c include/panjrathJashanjotA2.h
	gcc -Wall -std=c99 -c src/panjrathJashanjotA2.c
panjrathJashanjotA2Main.o: src/panjrathJashanjotA2Main.c include/panjrathJashanjotA2.h
	gcc -Wall -std=c99 -c src/panjrathJashanjotA2Main.c
clean:
	rm *.o bin/stringMe
