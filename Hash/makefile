a.out: main.o Hash.o
	gcc main.o Hash.o
main.o: main.c
	gcc -c main.c
Hash.o: Hash.c
	gcc -c Hash.c
run: a.out
	./a.out
clear:
	rm a.out main.o Hash.o 
