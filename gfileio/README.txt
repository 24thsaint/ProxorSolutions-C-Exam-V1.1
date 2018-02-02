Start here to solve the gfileio task.

In this task, you will implement a program that
reads a text file of integers, computes their sum,
and writes the sum to the console.

Details: Modify and complete the file gfileio.c by implementing  
functions read_number() and completing main(). The comments in  
gfileio.c describe each function, and full specifications are as  
follows: 
 
int read_number(FILE *inf, int *result)  
    read_number() reads a long int. The parameters are:
 - inf is an opened file.  The file contains signed decimal integers 
    and white space (including new lines). read_number skips any white 
    space, reads the next integer (delimited by white space or end of 
    file), stores the integer into the address given by result, and 
    returns 1. If no integer is found in the file, read_number() 
    returns 0, leaving the file open. 
 - result is the address of the integer that is read  
 
int main()  
    main() expects a file name to be passed on the command line.  The  
    file is opened and integers are read from the file. The sum of the  
    integers is printed to the console (to stdout), or zero is printed  
    if there are no integers in the file.  main() returns 0.  
 
Example command:
-----------------
gfileio numbers.txt

Example output (using the numbers.txt file provided to you):
----------------
2222
----------------
  (Passing this test is necessary but 
   not sufficient for a high score.)

Your solution should reside entirely in gfileio.c.
You may not introduce additional files. After compiling gfileio.c, 
it will be run with one command-line argument: the name of the
input file.


DEVELOPING IN A TERMINAL WINDOW
===============================

% make        -- Compile your program
% make run    -- Run your program
% make debug  -- debug your program
% make submit -- submit your program


ADDITIONAL INFORMATION
======================
You may not add new source files, you must change only
gfileio.c.

You may assume integers do not overflow.

You may assume the input file exists and has the expected
format.
