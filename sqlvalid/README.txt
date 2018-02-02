Start here to solve the sqlvalid task.

In this task you will you implement:

1. A test to determine that the inventory of stock of items is equal
to or above a certain level. This routine will interrogate the
INVENTORY table of a database and report on the number of items below
this level.

2. An update function to raise the stock levels of the items that have
fallen below this level.

3. A test to check whether the company's perishable stock exposure is
higher than an acceptable monetary value.

Note that sqlite3 documentation is available in your exam environment.  
 
The DURIAN database is created for you (the durian is a highly
regarded fruit in SE-Asia chosen for this application for its many
flavors and pricing).

The database contains a table called INVENTORY which has the following
structure:

NAME TEXT PRIMARY KEY  (the name of the item)  
DESC TEXT NOT NULL     (a description of the item)  
PRICE DOUBLE NOT NULL  (the price of the item)  
KGS INTEGER NOT NULL   (the amount of item in inventory in kilograms) 


You MUST complete the implementation of the following functions:

    void init(void)
Open the database, storing the database connection handle 
into the variable db (already declared) - the database name 
is DB_FILE, defined for you in ../sqlutil/sqlutil.h. 


    void cleanup(void)
Close the database, and set the database connection handle to NULL. If
the connection handle (the variable db) is NULL, do nothing.

    int validate_inventory_stock(int minimum_kg)
Validate that stock has the minimum level in the INVENTORY table (the
minimum level is the integer parameter; the level is given by the KGS
field of each entry in the INVENTORY table). Return the number of
items whose level is below the minimum.  You must use a single sql 
select command to access the INVENTORY table.

    int update_inventory_stock(int minimum_kg)
Update stock items that are low. The minimum_kg parameter is a minimum
level for the KGS field of each row of the INVENTORY table. For each
row of the table where the value of the KGS field is below minimum_kg,
raise the level in the KGS field to minimum_kg + 100. You must update
all low stock items with a single sql update command.

    int validate_inventory_exposure(int max_total)
Validate that the exposure of inventory (i.e. the sum over all rows of
the INVENTORY table of PRICE * KGS) does not exceed the value of the
parameter max_total. Return 0 if max_total is exceeded, 1 if not, and
-1 if an error occurs.

If you do not alter main() and run a completed program, the output 
should be:
------------------------------ 
Number of invalid inventory items: 3 
Number of invalid inventory items: 0 
inventory exposure is too high 
------------------------------
You may alter main to create additional tests.

Your solution should reside entirely in sqlvalid.c.
You may not introduce additional files. After compiling sqlvalid.c, 
it will be run without command-line arguments.

DEVELOPING IN A TERMINAL WINDOW
===============================

% make        -- Compile your program
% make run    -- Run your program
% make debug  -- debug your program
% make submit -- submit your program


ADDITIONAL INFORMATION
====================== 
You may not add new source files, you must change only sqlvalid.c. 



