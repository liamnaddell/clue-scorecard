#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include <ncurses.h>
#define players 4
#define sentance 50
struct hand {
	char	playerName[sentance];
	char 	card1[sentance];
	char 	card2[sentance];
	char 	card3[sentance];
	char 	card4[sentance];
};

WINDOW *create_newwin(int height, int width, int starty, int startx);

int app_close(sqlite3 *db, int rc) {
	sqlite3_close(db);
	return rc;
}


int GetHands(sqlite3 *db, struct hand *hand1) {
	int error = 0;
	sqlite3_stmt *res;
	const char *tail;
	char *sql = "select * from hands";
	error =	sqlite3_prepare(db,sql,strlen(sql),&res,&tail);

	if (error != SQLITE_OK) {
		puts("We did not get any data!");
		return 0;
	}
	int i = 0;
	while (sqlite3_step(res) == SQLITE_ROW) {
		const unsigned char *name = sqlite3_column_text(res,0);	
		const unsigned char *card1 = sqlite3_column_text(res,1);	
		const unsigned char *card2 = sqlite3_column_text(res,2);	
		const unsigned char *card3 = sqlite3_column_text(res,3);	
		const unsigned char *card4 = sqlite3_column_text(res,4);	
		strncpy(hand1[i].playerName,name,sentance);
		strncpy(hand1[i].card1,card1,sentance);
		strncpy(hand1[i].card2,card2,sentance);
		strncpy(hand1[i].card3,card3,sentance);
		strncpy(hand1[i].card4,card4,sentance);
		i=i+1;
		if (i >= players) {
			break;
		}

	}
	sqlite3_finalize(res);
	return 0;
}


int printHands(struct hand *hand1) {
	int i = 0;
	for (;;) {
		printf("%s|%s|%s|%s|%s|\n",hand1[i].playerName,hand1[i].card1,hand1[i].card2,hand1[i].card3,hand1[i].card4);
		i=i+1;
		if (i >= players) {
			break;
		}
	}
}

int main() {
	//sqlite3 *db;
	//int ret = sqlite3_open("tmpdb_cluesc",&db);
	//struct hand hand1[players];
	//GetHands(db,hand1);
	//printHands(hand1);


	initscr();			/* Start curses mode 		  */
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	refresh();

	WINDOW *my_win;
	int ch;
	my_win = create_newwin(3,COLS,LINES-3,0);
	mvaddch(LINES-2,2,'>');
	while((ch = getch()) != KEY_F(1)) {
		switch(ch) {
			case (127):
				addch('b');
			case (KEY_BACKSPACE):
				addch('c');
			default:
				addch(ch);
		}
	}

	

	endwin();			/* End curses mode		  */

	//return app_close(db,0);
	return 0;
}

WINDOW *create_newwin(int height, int width, int starty, int startx) {      
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);
	box(local_win, 0 , 0);          /* 0, 0 gives default characters
				* for the vertical and horizontal
				 * lines                        */
	wrefresh(local_win);            /* Show that box                */

	return local_win;
}
