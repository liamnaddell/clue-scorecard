make:	
	clang -O2 -std=c11 -g -o cluesc main.c -lncurses -lsqlite3

run: make
	./cluesc

clean:
	rm -f ./cluesc
