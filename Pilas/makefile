a.out: main.o pilas.o
	gcc main.o pilas.o
main.o: main.c
	gcc -c main.c
pilas.o: pilas.c
	gcc -c pilas.c

indent: 
	indent *.c *.h


run: a.out
	./a.out
clear:
	rm a.out main.o arbol.o 
