Start here to solve the rbsort task.

In this task, you will write a program to sort a file of
signed decimal integer numbers in the file "numbers.txt".

Details: Modify and complete the file rbsort.c to read 
numbers from "numbers.txt", enter them into a red-black tree 
and print the numbers in order to the standard output like this:

1
10
...
23
42

In other words, write one number on each line

The numbers should be in increasing order

You MUST complete the implementation of read_number() in 
rbsort.c according to the description (see comments in rbsort.c).

You MUST use the red-black tree
implementation in ../rb_tree. (Any modifications to code
in ../rb_tree will not be used in testing your solution.)

Important: free all allocated memory before your program
exits.

Example input:
----------------
10
5
7
----------------

Example output:
----------------
5
7
10
----------------

Your solution should reside entirely in rbsort.c.
You may not introduce additional files. After compiling rbsort.c, 
it will be run with no command-line arguments. (Thus, 
the input file name "numbers.txt" should be "hard coded" into 
your program.) 

Please assume that numbers are integers that can be properly
represented using C's long int type.
There is no extra credit for relaxing this assumption.


DEVELOPING IN A TERMINAL WINDOW
===============================

% make        -- Compile your program
% make run    -- Run your program
% make debug  -- debug your program
% make submit -- submit your program
% make test   -- Test your program
  (Passing this test is necessary but 
   not sufficient for a high score. It should
   print "OK (1 test)" if you pass the test.)

ADDITIONAL INFORMATION
======================
See ../rb_tree/red_black_tree.c and ../rb_tree/list.c 
for details of red-black tree functions implemented for 
you. 

Be very careful with nil vs. NULL. In the 
red-black tree library, tree->nil is a pointer to a
special sentinel node. Sometimes tree->nil is returned to
indicate no node was found. nil is not equal to NULL,
the often-used "null pointer" in C.

You may not add new source files, you must change only
rbsort.c.

Modifications/extensions to ../rb_tree will be REMOVED
when Proxor tests your solution.
