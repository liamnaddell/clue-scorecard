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
	sqlite3_close(db);
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

int main() {
	sqlite3 *db;
	int error = 0;
	sqlite3_stmt *res;
	const char *tail;
	int ret = sqlite3_open("tmpdb_cluesc",&db);
	char *sql = "select * from hands";
	error =	sqlite3_prepare(db,sql,strlen(sql),&res,&tail);

	if (error != SQLITE_OK) {
		puts("We did not get any data!");
		return 0;
	}
	struct hand hand1[60];
	int i;
	while (sqlite3_step(res) == SQLITE_ROW) {
		const unsigned char *name = sqlite3_column_text(res,0);	
		const unsigned char *card1 = sqlite3_column_text(res,1);	
		const unsigned char *card2 = sqlite3_column_text(res,2);	
		const unsigned char *card3 = sqlite3_column_text(res,3);	
		const unsigned char *card4 = sqlite3_column_text(res,4);	
		strcpy(hand1[i].playerName,name);
		strcpy(hand1[i].card1,card1);
		strcpy(hand1[i].card2,card2);
		strcpy(hand1[i].card3,card3);
		strcpy(hand1[i].card4,card4);
		i++;

	}
	i = i-1;
	while (i>=0) {
		printf("%s|%s|%s|%s|%s|\n",hand1[i].playerName,hand1[i].card1,hand1[i].card2,hand1[i].card3,hand1[i].card4);
		i--;
	}
	sqlite3_finalize(res);
    


	return app_close(db,0);
}


//int main(int argc, char **argv){
//	sqlite3 *db;
//	char *zErrMsg = 0;
//	int rc;
//
//	if( argc!=3 ){
//		fprintf(stderr, "Usage: %s DATABASE SQL-STATEMENT\n", argv[0]);
//		return(1);
//	}
//	rc = sqlite3_open(argv[1], &db);
//	if( rc ){
//		fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
//		sqlite3_close(db);
//		return(1);
//	}
//	rc = sqlite3_exec(db, argv[2], callback, 0, &zErrMsg);
//	if( rc!=SQLITE_OK ){
//		fprintf(stderr, "SQL error: %s\n", zErrMsg);
//		sqlite3_free(zErrMsg);
//	}
//	sqlite3_close(db);
//	return 0;
//}
