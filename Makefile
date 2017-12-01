make:	
	gcc -o ./cluesc main.c -lncurses

run: make
	./cluesc

clean:
	rm -f ./cluesc
