/*
 * sqlverif.c
 *
 * Created on: Sep 7, 2014
 * sqlverif -- verify the a database import against 2 business rules and
 * create a report on inventory level
 *
 * Copyright 2014, Proxor
 */

#include "sqlutil.h"
#include <stdlib.h>
#include <errno.h>

sqlite3 *db;

// open database
void init(void)
{
}

// close database
void cleanup(void)
{
}

/* Validate that the durian name exists in the inventory table */
/* return 0 if doesn't exist, 1 if exists, -1 if error */
int validate_durian_name(char *name)
{
    return 0;
}

/* Validate that the sales kgs can be satisfied by quantity in the 
 *    inventory table 
 * return 0 if doesn't, 1 if can, -1 on error */
int validate_durian_kgs(char *name, int sales_kgs)
{
    return 0;
}

/* DO NOT CHANGE use this to create a header in the 
 * print_inventory_levels_callback function below */
void print_header(int kgs)
{
    char hdr[31];

    memset(hdr, '=', 30);
    memset(&hdr[30], 0, 1);
    printf("Inventory below %d kgs:\n%-20s%10s\n%s\n",
           kgs, "Name", "Avail(kg)", hdr);
}

/* complete to retrieve and print the names and kgs of inventory 
 *   contained in the database whose stock is beneath the minimum 
 *   level. Output should be ordered from lowest KGS to highest.
 * return 0 if success, 1 if fail */
int print_inventory_levels(int min_kgs)
{
    return 0;
}


/* use this method to import sales of durians from sales file */
/* DO NOT CHANGE - only implement the verify calls */
void import_sales(void)
{
    int kgs;
    char *ptr;
    char name[MAX_STR+1];
    char date[MAX_STR+1];
    char buff[MAX_LINE+1];
    char buff1[MAX_LINE+1];
    int errCount = 0;
    sqlite3_stmt *stmt;

    FILE *infile = fopen(SALES_FILE, "r");
    if (infile == NULL) {
        fprintf(stderr, "Cannot open input file %s\n", SALES_FILE);
        exit(1);
    }

    char *sql = "INSERT INTO SALES VALUES (?,?,?)";
    sqlite3_prepare(db, sql, strlen(sql) + 1, &stmt, NULL);

    while (fgets(buff, MAX_LINE, infile) != NULL) {
        strcpy(buff1, buff);
        ptr = strtok(buff, DELIM );
        strcpy(name, ptr);
        ptr = strtok(NULL, DELIM );
        strcpy(date, ptr);
        ptr = strtok(NULL, DELIM );
        sscanf(ptr, "%d", &kgs);

        if (!validate_durian_name(name)) {
            printf("Sales entry with name : %s - rejected, name not found :"
                   " \n%s", name, buff1);
            errCount++;
            continue;
        }

        if (!validate_durian_kgs(name, kgs)) {
            printf("Sales entry with name : %s - rejected, kgs in inventory "
                   "exceeded : \n%s", name, buff1);
            errCount++;
            continue;
        }

        if (sqlite3_bind_text(stmt, 1, name, -1, SQLITE_STATIC) != SQLITE_OK
            || sqlite3_bind_text(stmt, 2, date, -1, SQLITE_STATIC) != SQLITE_OK
            || sqlite3_bind_double(stmt, 3, kgs) != SQLITE_OK) {
            fprintf(stderr, "sqlite3_bind error: %s\n", sqlite3_errmsg(db));
            break;
        }

        if (sqlite3_step(stmt) != SQLITE_DONE) {
            fprintf(stderr, "insert error: %s\n", sqlite3_errmsg(db));
            break;
        }
        sqlite3_reset(stmt);
    }

    sqlite3_finalize(stmt);
    fclose(infile);
    printf("Sales file : %s imported with %d errors\n", SALES_FILE, errCount);
}


int main(int argc, char* argv[])
{
    prepare_db();         /* set up database for solution DO NOT REMOVE */

    init();

    print_inventory_levels(900);

    import_sales();

    print_inventory_levels(900);

    cleanup();

    drop_db();            /* delete the database DO NOT REMOVE */

    return EXIT_SUCCESS;
}
