//#include <sqlite3.h>
#include <ncurses.h>
#include <string.h>

char *splash = "   ___ _            \n"
                "  / __\\ |_   _  ___ \n"
                " / /  | | | | |/ _ \\\n"
                "/ /___| | |_| |  __/\n"
                "\\____/|_|\\__,_|\\___|\n\n";

int main(int argc, char **argv) {
	initscr();            // Initializes the screen
	keypad(stdscr,TRUE);  // Allows keyboard input
  noecho();             // Doesn't echo keyboard input
  cbreak();             // Allows CTRL-C to break

	printw(splash);
	refresh();

  int c;
  while (c != '\n') {
    printw("%c", c);
    c = getch();
  }

	endwin();
	return 0;
}
