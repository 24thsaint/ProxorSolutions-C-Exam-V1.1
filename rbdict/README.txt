Start here to solve the rbdict task.

In this task, you will write a "dictionary" that stores and looks up
values associated with strings.

Details: Modify and complete the file rbdict.c by implementing
    int compare(const void *a, const void *b) should return 1 if 
        *a > *b, -1 if *a < *b, and 0 otherwise.
    void dict_put(char *, double) that associates a double with a
        string, and
    double dict_get(char *) that looks up the double associated with
        the string. dict_get() should return 0.0 if the string has no
        association (i.e. there was no previous call to dict_put() to
        provide a value for the string).
    void init() should create and initialize rbtree. Before calling
        init(), rbtree is NULL. When init() returns, rbtree must be an
        empty tree.
    void cleanup() should deallocate all allocated memory. Before
        calling cleanup(), rbtree is either NULL or a tree. After
        cleanup(), rbtree is NULL and any memory allocated by rbtree
        functions, or other functions, is freed.

The function main() will call these functions and perform a
preliminary test. main() uses init() and cleanup(), which must also be
defined.

You MUST use the red-black tree implementation in ../rb_tree. (Any
modifications to code in ../rb_tree will not be used in testing your
solution.) To use ../rb_tree, you must define functions including
compare(). See ../rb_tree/red_black_tree.h for more information on 
using this implementation, and define whatever additional functions
are needed by the red-black tree.

Important: free all allocated memory before your program exits.

Example output:
----------------
dict_put() and dict_get() worked as expected in simple tests.
----------------
  (Passing this test is necessary but 
   not sufficient for a high score.)

Your solution should reside entirely in rbdict.c.
You may not introduce additional files. After compiling rbdict.c, 
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
return -1, 0, or +1, but strcmp() returns a wide range of integer
values.

You MUST complete the implementation of compare() in rbdict.c.

You may not add new source files, you must change only rbdict.c.

Modifications/extensions to ../rb_tree will be REMOVED when Proxor
tests your solution.
