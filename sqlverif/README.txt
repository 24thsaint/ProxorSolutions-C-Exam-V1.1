Start here to solve the sqlverif task.

In this task you will you modify and complete a program to test the 
validity of data being imported from a text file into a precreated 
database. The tests will verify if a product name exists and if an order 
can be satisfied. You will also create a report to output inventory 
levels for the purpose of reordering.

Note that sqlite3 documentation is available in your exam environment. 

The DURIAN database is created for you (the durian is a highly 
regarded fruit in SE-Asia chosen for this application for its many 
flavors and pricing).

The database contains the following tables and structures which are
created for you:

INVENTORY:

NAME TEXT PRIMARY KEY  (the name of the item) 
DESC TEXT NOT NULL     (a description of the item) 
PRICE DOUBLE NOT NULL  (the price of the item) 
KGS INTEGER NOT NULL   (the amount of item in inventory in kilograms) 

SALES:

NAME TEXT NOT NULL     (the name of the item) 
DATE TEXT NOT NULL     (the date of the sale) 
KGS INTEGER NOT NULL   (the amount sold in kilograms) 

The function import_sales() provided to import the sales file into the
SALES table is implemented for you and MUST NOT BE CHANGED.  No
additional modifications are to be made to the database.  Your
functions should only read from the database.

Your verification tasks will check that the product NAME to be imported to 
the SALES table can be matched in the INVENTORY table and that the quantity 
of KGS to be imported to the SALES table does not exceed the amount in the 
KGS column in the INVENTORY table. You will also print a report to display 
inventory products from the INVENTORY table that fall below a certain level
(i.e for reordering purposes).

The format of this output must be:

Inventory below 900 kgs:
Name                 Avail(kg)
==============================
Mao Shan Wang              200
Red Prawn                  510

The print_header() function is provided and contains the format
spacing for the data lines.

Details: Modify and complete the file sqlverif.c by implementing
the following functions that will be called from the function main():

    void init(void)
Open the database, storing the database connection handle 
into the variable db (already declared) - the database name 
is DB_FILE, defined for you in ../sqlutil/sqlutil.h. 

    void cleanup(void)
Close the database, and set the database connection handle to NULL. If
the connection handle (the variable db) is NULL, do nothing.

    int print_inventory_levels(int min_kgs)
Print each inventory NAME and KGS where KGS is below the level
min_kgs. Order the output from lowest to highest KGS.


Also implement the following functions that will be called from 
import_sales(), which is supplied for you and must not be changed:

    int validate_durian_name(char *name)
Validate that the name (from the SALES import line) is present in
the INVENTORY table. You must use a single sql select command to
access the INVENTORY table. Hint: You may have to quote durian names
within sql commands.

    int validate_durian_kgs(char *name, int sales_kgs)
Validate that the INVENTORY KGS for name is greater than or equal to
sales_kgs (the KGS in the SALES import line). You must use a single
sql select command to access the INVENTORY table.

If you do not alter main() and run a completed program, the output 
should be:
------------------------------
Inventory below 900 kgs:
Name                 Avail(kg)
==============================
Mao Shan Wang              200
Red Prawn                  550
Sales entry with name : Mao Shan Wang - rejected, kgs in inventory exceeded : 
Mao Shan Wang|2013-09-10 18:00:00.000|300|
Sales entry with name : Durian Dodgy - rejected, name not found : 
Durian Dodgy|2013-09-10 18:00:00.000|1458|
Sales file : durian-sales.txt imported with 2 errors
Inventory below 900 kgs:
Name                 Avail(kg)
==============================
Mao Shan Wang              200
Red Prawn                  510
Hor Lor                    800
------------------------------
You may alter main to create additional tests. 

Your solution should reside entirely in sqlverif.c.
You may not introduce additional files. After compiling sqlverif.c, 
it will be run without command-line arguments.

DEVELOPING IN A TERMINAL WINDOW
===============================

% make        -- Compile your program
% make run    -- Run your program
% make debug  -- debug your program
% make submit -- submit your program


ADDITIONAL INFORMATION
====================== 
You may not add new source files, you must change only sqlverif.c. 
You can assume all the files in the sales text file are in the 
valid format.
