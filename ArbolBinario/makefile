a.out: main.o arbolbinario.o
	gcc main.o arbolbinario.o
main.o: main.c
	gcc -c main.c
arbolbinario.o: arbolbinario.c
	gcc -c arbolbinario.c
run: a.out
	./a.out
clear:
	rm a.out main.o arbolbinario.o 
