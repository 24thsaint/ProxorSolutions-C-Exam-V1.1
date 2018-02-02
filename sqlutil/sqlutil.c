/*
 * sqlutil.c
 *
 * Created on: Sep 7, 2014
 * sqlutil -- support utils for sql tests
 *
 * Copyright 2014, Proxor
 */


#include "sqlutil.h"
#include "sqlaudit.h"
#include <time.h>
#include <unistd.h>

int rflag = FALSE;     /* boolean - randomize the database numbers */
unsigned seed = 0;

/* randomize_on - enable randomization (default is disabled) */
void randomize_on()
{
    rflag = TRUE;
}

/* randomize_price - optionally randomize the price */
double randomize_price(double price)
{   
    if (!rflag) return price;
    int r = rand() % 100;
    int p = (int) price;
    return p + (r / 100.0);
}

void exec_sql_command(sqlite3 *db,char *sql)
{
    char *zErrMsg = 0;
    int rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "Database command failed on setup: %s - %d - %s %s\n",
                sql, rc, sqlite3_errmsg(db), zErrMsg!=NULL?zErrMsg:"");
        exit(1);
    }
}

/* populate_db - add test data to db, randomizing price if rflag */
void populate_db(sqlite3 *db)
{
    char buff[512];
    if (seed == 0) {
        seed = time(NULL);
    }
    srand(seed);

    sprintf(buff, "insert into inventory values ('Mao Shan Wang',"
            "'Most popular. More sweet than bitter.',%f,200)",
            randomize_price(24.39));
    exec_sql_command(db, buff);

    sprintf(buff, "insert into inventory values ('Red Prawn',"
            "'Popular a bitter sweet taste, red flesh.',%f,550)",
            randomize_price(18.32));
    exec_sql_command(db, buff);

    sprintf(buff, "insert into inventory values ('Hor Lor',"
            "'A little bitter, older fruit chocolatey.',%f,910)",
            randomize_price(17.64));
    exec_sql_command(db, buff);

    sprintf(buff, "insert into inventory values ('D24',"
            "'The strongest smell. Bitter then sweet.',%f,1200)",
            randomize_price(17.64));
    exec_sql_command(db, buff);

    sprintf(buff, "insert into inventory values ('Durian Mas',"
            "'Milder, known for special creamy taste.',%f,14500)",
            randomize_price(14.47));
    exec_sql_command(db, buff);

    sprintf(buff, "insert into inventory values ('Durian Kampung',"
            "'Most common on market. Village-grown.',%f,20300)",
            randomize_price(8.58));
    exec_sql_command(db, buff);
}

/* prepare_db -- create a database for test takers and for grading
 *   if rflag is true, randomize the prices in the database
 */
void prepare_db()
{
    sqlite3 *db;
    int rc;

    /* open or create */
    rc =  sqlite3_open(DB_FILE, &db);

    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        exit(0);
    }

    // create inventory table if doesn't exist
    exec_sql_command(db, "CREATE TABLE IF NOT EXISTS inventory "
            "(name TEXT PRIMARY KEY,desc TEXT NOT NULL,"
            "price DOUBLE NOT NULL,kgs INTEGER NOT NULL)");

    // empty the table
    exec_sql_command(db, "DELETE FROM inventory");

    // populate with inventory
    populate_db(db);

    // create table for sales
    exec_sql_command(db, "CREATE TABLE IF NOT EXISTS sales "
            "(name TEXT,date TEXT NOT NULL,kgs INTEGER NOT NULL)");

    // empty table
    exec_sql_command(db, "DELETE FROM sales");

    // drop sales trigger
    rc = sqlite3_exec(db, "DROP TRIGGER SALES_TGR", 0, 0, 0);
    // can fail if not exist

    // create sales trigger
    exec_sql_command(db, "CREATE TRIGGER SALES_TGR AFTER INSERT ON SALES "
            "BEGIN UPDATE INVENTORY SET KGS=KGS-NEW.KGS WHERE NAME=NEW.NAME; "
            "END;");

    sqlite3_close(db);
}


/* drop_db - remove the database file DB_FILE */
void drop_db()
{
    if (access(DB_FILE, F_OK) == -1)
        return;

    int rc = unlink(DB_FILE);
    if (rc == 0)
        return;

    char msg[256];
    sprintf(msg, "WARNING - drop_db - unlink() failed trying to remove %s",
            DB_FILE);
    perror(msg);
}
