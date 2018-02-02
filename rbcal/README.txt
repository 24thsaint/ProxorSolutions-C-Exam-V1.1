Start here to solve the rbcal task.

In this task, you will write a "calendar" that stores and looks up
appointments by time.

Details: Your calendar is a dictionary that stores hour-long
appoinments described by a (char *) string.  The time of an
appointment is specified by an int day and an int hour.

Modify and complete the file rbcal.c by implementing:

- createkey(int day, int hour) -- make a representation of day, hour
    that can be stored in the red-black tree,
- compare(void *a, void *b) -- compare two keys,
- cal_add(int day, int hour, char *) -- make an appointment. Return
    0 if the time is already taken; otherwise, reserve the
    specified time and return 1.
- cal_lookup(int day, int hour) -- look up an appointment. Return
    the (char *) string given to cal_add when the appointment was
    made, or NULL if there is no matching appointment.

The function main() will call these functions and perform a
preliminary test. main() uses init() and cleanup(), which must also be
defined according to comments in rbcal.c.  createkey() and compare()
should also be defined according to comments because they will be
tested individually.

You MUST use the red-black tree implementation in ../rb_tree. (Any
modifications to code in ../rb_tree will not be used in testing your
solution.) To use ../rb_tree, you must define functions including
compare().  You can use any representation you wish for keys in the
red-black tree. For simplicity, days are integers rather than
day/month/year or some other compound structure.  You can assume days
are positive and, for example, that 0 means Jan 1, 2000, 366 means Jan
1, 2001, etc.  Hours are the integers from 0 through 23, inclusive.

Important: free all allocated memory before your program exits.

Example output:
----------------
cal_add() and cal_lookup() worked as expected in simple tests.
----------------
  (Passing this test is necessary but not sufficient for a high
   score.)

Your solution should reside entirely in rbcal.c.
You may not introduce additional files. After compiling rbcal.c, 
it will be run with no command-line arguments.


DEVELOPING IN A TERMINAL WINDOW
===============================

% make        -- Compile your program
% make run    -- Run your program
% make debug  -- debug your program
% make submit -- submit your program


ADDITIONAL INFORMATION
======================
See ../rb_tree/red_black_tree.c and ../rb_tree/list.c for details of
red-black tree functions implemented for you.

Be very careful with nil vs. NULL. In the red-black tree library,
tree->nil is a pointer to a special sentinel node. Sometimes tree->nil
is returned to indicate no node was found. nil is not equal to NULL,
the often-used "null pointer" in C.

IMPORTANT HINT: the compare function required by RBTreeCreate() must
return -1, 0, or +1, but, for example, the expression time1 - time2
returns a wide range of integer values.

You may not add new source files, you must change only rbcal.c.

Modifications/extensions to ../rb_tree will be REMOVED when Proxor
tests your solution.
