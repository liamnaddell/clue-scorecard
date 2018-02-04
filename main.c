#include <stdio.h>
#include <sqlite3.h>
#include <string.h>
#include <ncurses.h>
#include <stdint.h>
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

//closing handler
int app_close(sqlite3 *db, int rc) {
	sqlite3_close(db);
	return rc;
}


//gets the hands of all the players using the sqlite database
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
		//gets the individual names and cards out of the database	
		const unsigned char *name = sqlite3_column_text(res,0);	
		const unsigned char *card1 = sqlite3_column_text(res,1);	
		const unsigned char *card2 = sqlite3_column_text(res,2);	
		const unsigned char *card3 = sqlite3_column_text(res,3);	
		const unsigned char *card4 = sqlite3_column_text(res,4);	
		//have to convert to const char *
		strncpy(hand1[i].playerName,(const char *)name,sentance);
		strncpy(hand1[i].card1,(const char *)card1,sentance);
		strncpy(hand1[i].card2,(const char *)card2,sentance);
		strncpy(hand1[i].card3,(const char *)card3,sentance);
		strncpy(hand1[i].card4,(const char *)card4,sentance);
		i=i+1;
		if (i >= players) {
			break;
		}

	}
	sqlite3_finalize(res);
	return 0;
}


//just takes a hand and prints it
void printHands(struct hand *hand1) {
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
	keypad(stdscr, TRUE);
        noecho();
	//my_win is the window at the bottom of the screen
	WINDOW *my_win;
	//our character
	int ch;
	my_win = create_newwin(3,COLS,LINES-3,0);
	//move the cursor
        wmove(my_win,2,0);
	//create a buffer of user input
	char buffer[100];
	//i acts for two purposes, as an indicator of where we are in an array, as well as how many characters are on the screen, as those numbers should match up
	int i=1;
	//press F5 to exit
	while((ch = getch()) != KEY_F(5)) {
		//append ch to the buffer
	    buffer[i] = ch;
	    //set the character after it to a null byte so that printw does not print after it
	    buffer[i+1] = '\0';
	    //increment i due to increase of characters
	    i=i+1;
	    //all of those should detect a backspace key
	    //backspaces are hard lol
            if (ch == KEY_BACKSPACE || ch == KEY_DC || ch == 127) {
                int y;
                int x;
                getyx(my_win,y,x);
		//move back a char
                wmove(my_win,y,x-1);
		//delete the character under the cursor
                wdelch(my_win);
		//refresh
                wrefresh(my_win);
		//remove a character from the buffer
		buffer[i-1]= '\0';
		//set the program counter back two because we added one to i, we must remove that, as well as we must remove another number b/c we have just deleted a char
		i=i-2;
	//if the key is enter
            } else if (ch == 10) {;
	    //set the current character(which would be the enter key) to a null byte
	    	buffer[i-1] = '\0';
		printw(buffer);
		//burn the buffer down
		memset(buffer,'\0',100);
		//removes all of the characters in my_win, and sets i to zero
		for (; i > 0; i=i-1) {
			int yo;
			int xo;
			getyx(my_win,yo,xo);
			wmove(my_win,yo,xo-1);
			wdelch(my_win);
			wrefresh(my_win);
		}
	//if we are not adding or entering data, just add a character to my_win
	    } else {
                waddch(my_win,ch);
                wrefresh(my_win);
            }
        }

	endwin();			/* End curses mode		  */

	//return app_close(db,0);
	return 0;
}

WINDOW *create_newwin(int height, int width, int starty, int startx) {      
	WINDOW *local_win;

	local_win = newwin(height, width, starty, startx);

	return local_win;
}
