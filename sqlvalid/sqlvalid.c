/*
 * sqlvalid.c
 *
 * Created on: Sep 7, 2014
 * sqlvalid -- validate the database against two business rules
 *
 * Copyright 2014, Proxor
 */

#include "sqlutil.h"
#include <stdlib.h>

sqlite3 *db = NULL;

// open database
void init(void)
{
    /* You should modify init to meet the specifications */
}

// close database
void cleanup(void)
{
    /* You should modify cleanup to meet the specifications */
}


/* validate that all stock has at least the minimum number of kg in stock */
/* return the number of records not having this minimum */
/* return -1 if error */
int validate_inventory_stock(int minimum_kg)
{
    /* You should modify validate_inventory_stock to meet the specifications */
    return 0;
}

/* update the items of stock that under the minimum kg to the minimum + 100kg */
/* return the number of rows updated, -1 on error */
int update_inventory_stock(int minimum_kg)
{
    /* You should modify update_inventory_stock to meet the specifications */
    return 0;
}


/* validate that total exposure of held inventory (kg*price) is no more than
   max_total */
/* return 0 if max_total exceeded, 1 if OK */
/* return -1 if error */
int validate_inventory_exposure(double max_total)
{
    /* Modify validate_inventory_exposure to meet the specifications */
    return 1;
}


/* main function -- DO NOT MODIFY */
int main(int argc, char* argv[])
{
   prepare_db();       /* set up database for solution DO NOT REMOVE */

   init();

   int invalid = validate_inventory_stock(1000);
   printf("Number of invalid inventory items: %d\n", invalid);

   int rows = update_inventory_stock(1000);
   if (rows != invalid) {
       printf("update inventory returned unexpected number of updates "
              "expected: %d, got: %d\n", invalid,rows);
   }

   invalid = validate_inventory_stock(1000);
   printf("Number of invalid inventory items: %d\n", invalid);

   invalid = validate_inventory_exposure(3000);
   if (invalid>=0)
       printf("inventory exposure is %s\n", 
              (invalid == 1) ? "in range" : "too high");

   cleanup();

   drop_db();      /* delete database DO NOT REMOVE */

   return EXIT_SUCCESS;
}
