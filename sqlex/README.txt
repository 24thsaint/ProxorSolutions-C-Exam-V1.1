Start here to solve the sqlex task.

In this task you will you implement and test a program to retrieve and
display inventory records from a pre-created database using select
calls and console formatting.

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
 
This table will be created and populated for you.

You MUST complete the implementation of the following functions:

    void init(void)
Open the database, storing the database connection handle  
into the variable db (already declared) - the database name  
is DB_FILE, defined for you in ../sqlutil/sqlutil.h.  
  
    void cleanup(void)
Close the database, and set the database connection handle to NULL. If
the connection handle (the variable db) is NULL, do nothing.

    void print_inventory_by_name(void)
Retrieve and print the inventory ordered alphabetically by name (A-Z).

    void print_inventory_by_price(void)
Retrieve and print the inventory ordered by price (most expensive
first). 

You should use a single select SQL statement in the retrieve and print
functions. Use SQL to deliver results sorted by name or price (you
should not sort data after retrieving them from the database.) The
progam's output will be formatted by a two line header code (already
implemented in print_header() within sqlex.c), followed by one row per
item and formatted as shown below.

You must leave main() as is in the provided code. main() will call
print_inventory_by_name() and print_inventory_by_price() to produce
output as shown below.


Name                Description                               Price($) Avail(kg)
================================================================================
D24                 The strongest smell. Bitter then sweet.      17.64      1200
Durian Kampung      Most common on market. Village-grown.         8.58     20300
Durian Mas          Milder, known for special creamy taste.      14.47     14500
Hor Lor             A little bitter, older fruit chocolatey.     17.64       910
Mao Shan Wang       Most popular. More sweet than bitter.        24.39       200
Red Prawn           Popular a bitter sweet taste, red flesh.     18.32       550
Name                Description                               Price($) Avail(kg)
================================================================================
Mao Shan Wang       Most popular. More sweet than bitter.        24.39       200
Red Prawn           Popular a bitter sweet taste, red flesh.     18.32       550
Hor Lor             A little bitter, older fruit chocolatey.     17.64       910
D24                 The strongest smell. Bitter then sweet.      17.64      1200
Durian Mas          Milder, known for special creamy taste.      14.47     14500
Durian Kampung      Most common on market. Village-grown.         8.58     20300


Your solution should reside entirely in sqlex.c. You may not introduce
additional files. After compiling sqlex.c, it will be run without
command-line arguments. You may assume that correctly implemented
database commands will not fail (you do not have to implement any 
error handling.) You may assume that descriptions are at most 40
characters long.

DEVELOPING IN A TERMINAL WINDOW
===============================

% make        -- Compile your program
% make run    -- Run your program
% make debug  -- debug your program
% make submit -- submit your program


ADDITIONAL INFORMATION
====================== 
Use the formatting information in the header code as a basis for
formatting your records. For full credit, the output to the console
should identically match the expected output, so do not introduce any
extra white space, new lines etc. You may not add new source files,
you must change only sqlex.c.
