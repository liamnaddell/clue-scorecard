PROG=clue_scorecard
CFLAGS=-lsqlite3 -O2 -g -lncurses
CC=gcc

all: $(PROG)

$(PROG): main.o
	$(CC) $(CFLAGS) $? -o $(PROG) 

main.o: main.c

main.c:
	$(CC) $(CFLAGS) -c main.c

edit:
	vim main.c
