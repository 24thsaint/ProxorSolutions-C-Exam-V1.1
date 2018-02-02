Start here to solve the rbspell task.

In this task, you will write a "spell check" program that finds
correct spellings for misspelled words.

The algorithm works as follows: Each dictionary word is stored with
multiple keys, including the original form and with each letter
deleted. For example, "red" is stored with the following keys: {"red",
"ed", "rd", "re"}. To find the possible correct spellings of a given
word, search for the word as well as the word with each letter
deleted. Thus, to correct "rsd", look up each of {"rsd", "sd", "rd",
"rs"}. Notice that "rsd" will match one of the keys for "red". Notice
also that "redd" and "re" can be used by this method to find "red".
This method will succeed if the misspelling has at most one missing
letter, one extra letter, or one incorrect letter.

Details: Modify and complete the file rbspell.c by implementing
add_word() and lookup_word() by following the instructions in comments
in rbspell.c. Notice that a string (key) may appear multiple times in
the dictionary. E.g. "red" is a key for "red" and also a key for
"read".

The function main() will call these functions and perform a
preliminary test. main() uses init() and cleanup(), which must also be
defined according to comments in rbspell.c. The correct output of this
test is given below after the heading "Example output ...".

You MUST use the red-black tree implementation in ../rb_tree. (Any
modifications to code in ../rb_tree will not be used in testing your
solution.) To use ../rb_tree, you must define functions including
compare(). Define compare() by following the instructions within the
comments in rbspell.c, and define whatever additional functions are
needed by the red-black tree.

Important: free all allocated memory before your program exits.

Example output (order of words is not significant)
-------------------------------------------------- 
thee
thee
their
there
--------------------------------------------------
  (Passing this test is necessary but 
   not sufficient for a high score.)

Your solution should reside entirely in rbspell.c.
You may not introduce additional files. After compiling rbspell.c, 
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

You MUST complete the implementation of compare() in rbwordcount.c.

You may not add new source files, you must change only rbspell.c.

Modifications/extensions to ../rb_tree will be REMOVED when Proxor
tests your solution.
