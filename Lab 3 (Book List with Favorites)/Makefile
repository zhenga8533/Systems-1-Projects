all: lab3.zip lab3

lab3.zip: Makefile lab3.c
	zip lab3 Makefile lab3.c lab3.h
	
lab3: lab3.c
	gcc -std=c99 -pedantic -g -o lab3 lab3.c

clean:
	rm -rf lab3 lab3.zip
