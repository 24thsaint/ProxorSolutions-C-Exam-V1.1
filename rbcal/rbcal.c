/* rbcal.c -- solution to rbcal task */

#include "../rb_tree/red_black_tree.h"

/* do not change the name of rbtree, and do not make it static */
rb_red_blk_tree *rbtree = NULL;

/* define a function to convert days, hours to a key.
 *   You are free to use any representation. The companion
 *   function destroykey() will be called when key is no
 *   longer needed.
 */
void *createkey(int day, int hour)
{
    /* your code goes here */
}


/* define functions for red black tree */

void destroykey(void *a)
{
    /* your code goes here */
}


int compare(const void *a, const void *b)
{
    /* return 0 if key a equals key b,
     * return 1 if key a is EARLIER than key b
     * return -1 if key a is LATER than key b
     */
}


/* init - initialize rbtree
 *   before calling init, rbtree is NULL
 *   when init returns, rbtree must be an empty tree
 */
void init()
{
    /* your code goes here */
}


/* cleanup - deallocate all allocated memory 
 *    before calling cleanup, rbtree is either NULL or a tree
 *    after cleanup, rbtree is NULL and any memory allocated
 *          by rbtree functions or other functions is freed
 */
void cleanup()
{
    /* your code goes here */
}


/* cal_add - associate a string with a time in rbtree
 *    Before calling cal_add, day/hour may or may not be in rbtree
 *    After calling cal_add, day/hour is associated with *content*
 *        of string s such that cal_lookup(day, hour) will 
 *        retrieve s. The storage pointed to by s may be 
 *        overwritten by the caller, so do not assume s is 
 *        immutable (i.e. make a copy).
 *        Although the red-black tree can store two identical
 *        keys with different info values, cal_add should 
 *        not add a new appointment if day/hour is already in
 *        the calendar.
 *    Return 0 if the day/hour is already entered into the calendar.
 *    Otherwise, the appointment is entered and return 1.
 */
int cal_add(int day, int hour, char *s)
{
    /* your code goes here */
}


/* cal_lookup - retrieve the appointment for a given time
 *    Before cal_lookup is called, rbtree is a valid red-black tree.
 *    After cal_lookup is called, rbtree is unchanged.
 *    The returned value is NULL if there is no appointment at the
 *        given day and hour; otherwise, the returned value is the string
 *        associated with the appointment in a previous call to cal_add().
 *    The returned string should be the address of the string in the 
 *        tree. The returned string will not be modified or freed.
 */
char *cal_lookup(int day, int hour)
{
    /* your code goes here */
}


int main()
{
    init();
    int pass = 1;
    pass &= cal_add(3560, 10, "Appointment 1 (day 3560, hour 10)");
    cal_add(3560, 11, "Appointment 2 (day 3560, hour 11)");
    pass &= (cal_lookup(3560, 12) == NULL);
    pass &= (strcmp(cal_lookup(3560, 10), 
                    "Appointment 1 (day 3560, hour 10)") == 0);
    cleanup();
    if (pass) {
        printf("cal_add() and cal_lookup() worked as expected "
               "in simple tests.\n");
    } else {
        printf("There is a problem with cal_add() or cal_lookup().\n");
    }
    return 0; /* return 0 on success */
}
