a.out: main.o ListasDobleLigada.o
	gcc main.o ListasDobleLigada.o
main.o: main.c
	gcc -c main.c
ListasDobleLigada.o: ListasDobleLigada.c
	gcc -c ListasDobleLigada.c
run: a.out
	./a.out
clear:
	rm a.out main.o ListasDobleLigada.o 
