/*
 * sqlex.c
 *
 * Created on: Sep 7, 2014
 * sqlex -- extract data from a database and format to stdout
 *
 * Copyright 2014, Proxor
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// sql setup function and constant definitions - DO NOT REMOVE
#include "sqlutil.h"

sqlite3 *db = NULL;


/* open database */
void init(void)
{
    /* You should modify init to meet the specifications */
}

/* close database */
void cleanup(void)
{
    /* You should modify cleanup to meet the specifications */
}


/* retrieve and print the inventory contained in the database order 
 *       from higest price downward
 */
void print_inventory_by_price(void)
{
    /* You should modify print_inventory_by_price to meet the specifications */
    return 0;
}

/* retrieve and print the inventory contained in the database order 
 *       by alphabetical name
 */
void print_inventory_by_name(void)
{
    /* You should modify print_inventory_by_name to meet the specifications */
}

/*
 * use this to create a header for the output lines DO NOT REMOVE OR MODIFY
 * if you don't use and follow the formatting your output will fail
*/
void print_header(void)
{
    char hdr[81];

    memset(hdr,'=',80);
    memset(&hdr[80],0,1);
    printf("%-20s%-40s%10s%10s\n%s\n", "Name", "Description", "Price($)",
           "Avail(kg)", hdr );
}


/* main function - DO NOT MODIFY */
int main(int argc, char* argv[])
{
   prepare_db();    /* set up database for solution DO NOT REMOVE */

   init();

   print_header();
   print_inventory_by_name();

   print_header();
   print_inventory_by_price();

   cleanup();

   drop_db();             /* delete the database DO NOT REMOVE */
   
   return EXIT_SUCCESS;
}
