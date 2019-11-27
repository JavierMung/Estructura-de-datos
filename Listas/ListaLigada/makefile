a.out: main.o Listas_Ligadas.o
	gcc main.o Listas_Ligadas.o
main.o: main.c
	gcc -c main.c
Listas_Ligadas.o: Listas_Ligadas.c
	gcc -c Listas_Ligadas.c
run: a.out
	./a.out
clear:
	rm a.out main.o Listas_Ligadas.o 
