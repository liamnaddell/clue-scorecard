make:	
<<<<<<< HEAD
	clang -Wall -g -o cluesc main.c -lncurses -lsqlite3
=======
	clang -O2 -std=c11 -g -o cluesc main.c -lncurses -lsqlite3
>>>>>>> 665d55cf640197358712fad51c3a7a82d2f50d68

run: make
	./cluesc

clean:
	rm -f ./cluesc
