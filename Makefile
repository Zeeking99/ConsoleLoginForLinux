# Makefile

main: main.o login.o console.o
	gcc main.o login.o console.o -o main
main.o: main.c
	gcc -c main.c -o main.o
login.o: login.c
	gcc -c login.c -o login.o
console.o: console.c
	gcc -c console.c -o console.o
clean:
	rm *.o
