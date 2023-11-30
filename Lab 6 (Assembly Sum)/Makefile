all: lab6.zip lab6

lab6.zip: Makefile lab6main.c lab6.s
	zip lab6 Makefile lab6main.c lab6.s
	
lab6: lab6main.c lab6.s
	gcc lab6.s lab6main.c -no-pie -o lab6

clean:
	rm -rf lab6 lab6.zip
