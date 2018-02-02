/* rbwordcount.c -- starting point for the rbwordcount task
 * Copyright 2014 Proxor
 */

/* Task basics:
    read a document
    split it into words
    count each word
    print all words in alphabetical order
*/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "../rb_tree/red_black_tree.h"
#define TRUE 1
#define FALSE 0
#define DOCFILENAME "words.txt"

/* define functions for red black tree */

int compare(const void *a, const void *b)
{
    /* return 0 if string a equals string b,
     * return 1 if string a is greater than string b
     * return -1 if string a is less than string b
     */
    
    /* add your implementation here */
}



/* read words from file */

/* be sure to write code to initialize the tree, etc. */
void init()
{
}

/* be sure to write code to free all allocated memory */
void cleanup()
{
}


/* a call to main should perform all the actions of this
 * program according to specifications.
 */
int main()
{
    init();
    /* your code goes here */
    cleanup();
    return 0; /* return 0 on success */
}
