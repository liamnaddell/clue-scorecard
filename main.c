#include <stdio.h>
#include <sqlite3.h>
#include <string.h>

struct hand {
	char	playerName[50];
	char 	card1[50];
	char 	card2[50];
	char 	card3[50];
	char 	card4[50];
};

int app_close(sqlite3 *db, int rc) {
	puts("oof");
	sqlite3_close(db);
	puts("koof1");
	return rc;
}

//static int callback(void *NotUsed, int argc, char **argv, char **azColName){
///	int i;
//	struct hand hand1[argc];
//	puts("debu");
//
//	for(i=0; i<argc; i++){
//		//puts("debu");
//		//printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
//		//puts(azColName[i]);
//		//printf("%d\n",argc);// //printf("hi%d",i);
//
//		printf("herrow1 %s \n",argv[i]);
//		strcpy(hand1[i].playerName,argv[i+1]);
//		printf("herrow %s \n",hand1[i].playerName);
//		strcpy(hand1[i].card1name,argv[i+2]);
//		strcpy(hand1[i].card2name,argv[i+3]);
//		strcpy(hand1[i].card3name,argv[i+4]);
//		strcpy(hand1[i].card4name,argv[i+5]);
//	}
//	printf("\n");
//	return 0;
//}


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
		puts("hi1");
		const unsigned char *name = sqlite3_column_text(res,0);	
		puts("hi2");
		const unsigned char *card1 = sqlite3_column_text(res,1);	
		puts("hi3");
		const unsigned char *card2 = sqlite3_column_text(res,2);	
		puts("hi4");
		const unsigned char *card3 = sqlite3_column_text(res,3);	
		puts("hi5");
		const unsigned char *card4 = sqlite3_column_text(res,4);	
		puts("hi6");
		strcpy(hand1[i].playerName,name);
		puts("hi7");
		strcpy(hand1[i].card1,card1);
		puts("hi8");
		strcpy(hand1[i].card2,card2);
		puts("hi9");
		strcpy(hand1[i].card3,card3);
		puts("hi10");
		strcpy(hand1[i].card4,card4);
		puts("hi11");
		i=i+1;
		printf("iperf %d\n",i);
		if (i >= 5) {
			puts("BROEKN");
			break;
		}
		puts("LOL");

	}
//	printf("ibef %d\n",i);
	//for (;;) {
	//	printf("%s|%s|%s|%s|%s|\n",hand1[i].playerName,hand1[i].card1,hand1[i].card2,hand1[i].card3,hand1[i].card4);
	//	i=i-1;
	//	printf("ibef %d\n",i);
	//	if (i <= 0) {
	//		break;
	//	}
	//}
	puts("kappa");
	sqlite3_finalize(res);
	puts("kappa2");
	return 0;
}

int main() {
	sqlite3 *db;
	int ret = sqlite3_open("tmpdb_cluesc",&db);
	struct hand hand1[4];
	puts("joof");
	GetHands(db,hand1);
	puts("joof3");
	return app_close(db,0);
	puts("smkoke waed");
}
