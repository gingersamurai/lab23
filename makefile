run : main
	./main

main : tree.o main.o
	gcc main.o tree.o -o main

tree.o : tree.c
	gcc -c tree.c -o tree.o

main.o : main.c
	gcc -c main.c -o main.o


