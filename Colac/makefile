a.out: main.o colac.o
	gcc main.o colac.o
main.o: main.c
	gcc -c main.c
colac.o: colac.c
	gcc -c colac.c
run: a.out
	./a.out
clear:
	rm a.out main.o colac.o 
