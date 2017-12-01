all:
	gcc -o ./cluesc main.c -lncurses

run:
	./cluesc

clean:
	-rm ./cluesc
