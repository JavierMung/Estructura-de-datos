a.out: main.o Lista_Circular.o
	gcc main.o Lista_Circular.o
main.o: main.c
	gcc -c main.c
Lista_Circular.o: Lista_Circular.c
	gcc -c Lista_Circular.c
run: a.out
	./a.out
indent:
	indent *.c *.h	
clear:
	rm a.out main.o Lista_Circular.o 
