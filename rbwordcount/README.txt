Start here to solve the rbwordcount task.

In this task, you will write a program to count the number of 
occurences of each word in the file "words.txt".

Details: Modify and complete the file rbwordcount.c to read 
words from "words.txt", enter the words into a red-black tree 
and count the number of times each word occurs. Print the words
in order to the standard output to look like this:

a 1
apple 2
the 3
...
zebra 1

In other words, for each line, write the word followed by a 
space followed by a decimal integer followed by a newline.

The words should be in alphabetical order as determined by
strcmp(). Notice that strcmp(A, B) returns <0 if A comes
before B, 0 if A is the same string as B, and >0 if A comes
after B. IMPORTANT HINT: the compare function required by 
RBTreeCreate() must return -1, 0, or +1, but strcmp() 
returns a wide range of integer values. 

You MUST complete the implementation of compare() in 
rbwordcount.c.

Words are considered the sequences of non-space characters. 
If c is a character, it is considered a non-space character
if !isspace(c). (For example, blanks, tabs, and newlines are
all space characters. "boy", "this!", "23", and "&x-y" are
all considered words.)

To count word occurrences, you MUST use the red-black tree
implementation in ../rb_tree. (Any modifications to code
in ../rb_tree will not be used in testing your solution.)
The algorithm to use is: When you find a word, if the
word is not in the tree, insert the word with a count of
1. If the word *is* in the tree, increment the count by 
one. After processing all words, retrieve the words in
order, and print each word with its occurrence count.

Important: free all allocated memory before your program
exits.

Example input:
----------------
This is an example. It is a simple example.
This is an easy one.
----------------

Example output:
----------------
It 1
This 2
a 1
an 2
easy 1
example. 2
is 3
one. 1
simple 1
----------------

Notice that capital letters sort before lower case using
strcmp().

Your solution should reside entirely within rbwordcount.c.
You may not introduce additional files. After compiling 
rbwordcount.c, it will be run with no command-line arguments. 
(Thus, the input file name "numbers.txt" should be "hard coded" 
into your program.)  

Please assume that words have less than 80 characters.
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
   print "OK (2 tests)" if you pass the test.)

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
rbwordcount.c.

Modifications/extensions to ../rb_tree will be REMOVED
when Proxor tests your solution.
