make:	
	clang -g -o cluesc main.c -lncurses -lsqlite3

run: make
	./cluesc

clean:
	rm -f ./cluesc
