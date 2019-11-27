a.out: main.o contigua.o
	gcc main.o contigua.o
main.o: main.c
	gcc -c main.c
contigua.o: contigua.c
	gcc -c contigua.c
run: a.out
	./a.out
clear:
	rm a.out main.o contigua.o 
