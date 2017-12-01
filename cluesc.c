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

	int word[100];
	int c, i;
	while (c != '\n') {
		if (c == '\t')
			printw("<TAB>");
		else;
		printw("%c", c);
		word[i] = c;
		i++;
		c = getch();
	}

	printw("\n");
	for (int x=1; i>x; x++)
		addch(word[x]);

	getch();

	endwin();
	return 0;
}
