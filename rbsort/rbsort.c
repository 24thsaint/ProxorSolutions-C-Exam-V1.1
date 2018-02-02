/* rbsort.c -- solution to rbsort task
 */

/* Task basics:
    read numbers
    insert numbers into tree
    print all numbers in order
*/

#include <stdio.h>
#include <string.h>
#include "../rb_tree/red_black_tree.h"
#define TRUE 1
#define FALSE 0
#define FILENAME "numbers.txt"

/* define functions for red black tree */

/**** (add function definitions here) ****/


/* read_number reads a long int
 * parameters:
 *    inf - an opened input file 
 *    result - address where to store long int, if any
 * returns:
 *    1 if an integer was read
 *    0 if not, e.g. upon end-of-file
 * read_number can be called repeatedly to read
 *    successive integers from the file
 */
int read_number(FILE *inf, long *result)
{
    /**** (your code goes here) ****/
}


/**** (more function definitions probably go here) ****/


/* note: main ignores any command-line arguments */
int main()
{
    init(); /* either define init() or delete this line */
    /**** (your code goes here) ****/
    cleanup(); /* either define cleanup() or delete this line */
    return 0; /* return 0 on success */
}
