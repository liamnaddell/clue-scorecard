//#include <sqlite3.h>
#include <ncurses.h>

int main(int argc, char **argv) {
	initscr();
	raw();
	keypad(stdscr,TRUE);
	noecho();


	//print
	printw("Hello world");
	refresh();

	//get char
	getch();

	//close 
	endwin();
	return 0;
}
