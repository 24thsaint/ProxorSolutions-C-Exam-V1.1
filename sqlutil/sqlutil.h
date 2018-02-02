/*
 * sqlutil.h
 *
 * Created on: Sep 7, 2014
 * sqlutil -- header for support utils for sql tests
 *
 * Copyright 2014, Proxor
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sqlite3.h>

#define MAX_LINE 512
#define MAX_STR 128
#define DELIM "|"
#define DB_FILE "durians.db"
#define SALES_FILE "durian-sales.txt"

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

void prepare_db();
void drop_db();
char *get_strbuff_string();
