
CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=simulation

all: simulation

simulation: main.o RR.o initialisation.o distribution.o
	gcc -o simulation main.o RR.o initialisation.o distribution.o
RR.o: RR.h RR.c distribution.h initialisation.h
	gcc -c RR.c
initialisation.o: initialisation.c initialisation.h  
	gcc -c initialisation.c
distribution.o: distribution.h distribution.c initialisation.h
	gcc -c distribution.c
clean:
	rm -rf *.o
