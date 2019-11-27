a.out: main.o Hasha.o
	gcc main.o Hasha.o
main.o: main.c
	gcc -c main.c
Hasha.o: Hasha.c
	gcc -c Hasha.c
run: a.out
	./a.out
clear:
	rm a.out main.o Hasha.o 
