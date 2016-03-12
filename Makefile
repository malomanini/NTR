
CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=simulation

all: $(EXEC)

simulation: fichier.o main.o
	$(CC) -o $@ $^ $(LDFLAGS)

fichier.o: distribution.c RR.c initialisation.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: main.c distribution.h RR.h initialisation.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)
