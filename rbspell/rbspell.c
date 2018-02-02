/* rbspell.c */

/* Task basics:
    enter variants into dictionary
    lookup variants of word
    print matches
*/

#include "../rb_tree/red_black_tree.h"

/* do not change the name of rbtree, and do not make it static */
rb_red_blk_tree *rbtree = NULL;

/* define functions for red black tree */

int compare(const void *a, const void *b)
{
    /* return 0 if string a equals string b,
     * return 1 if string a is greater than string b
     * return -1 if string a is less than string b
     */
}

/* define additional functions for red black tree */


/* init - initialize rbtree
 *   before calling init, rbtree is NULL
 *   when init returns, rbtree must be an empty tree
 */
void init()
{
    /* this function needs to be implemented */
}


/* cleanup - deallocate all allocated memory 
 *    before calling cleanup, rbtree is either NULL or a tree
 *    after cleanup, rbtree is NULL and any memory allocated
 *          by rbtree functions or other functions is freed
 */
void cleanup()
{
    /* this function needs to be implemented */
}


/* add_word - add a word and mispellings to dictionary
 *    before calling add_word, s is not in rbtree, and s has
 *        at least 2 letters.
 *    after calling add_word, s is associated with itself, and
 *        also with each misspelling of s where one character is
 *        removed. The storage pointed to by s may be 
 *        overwritten by the caller, so do not assume s is 
 *        immutable (i.e. make a copy). The resulting tree may
 *        now have multiple values for a given key. E.g. after
 *        add_word("as") and add_word("is"), the key "s" will
 *        appear twice in the tree with info values of "as" and 
 *        "is".
 *    Note that while the red-black tree can take any pointer
 *        as the key and info fields of a node, the info field MUST
 *        be a (char *) pointer to the correctly spelled word.
 */
void add_word(const char *s)
{
    /* this function needs to be implemented */
}


/* lookup_word - retrieve the spellings associated with s.
 *    before lookup_word is called, rbtree is a valid red-black 
 *        tree and s is a word with at least 2 letters.
 *    after lookup_word is called, rbtree is unchanged
 *    The returned value is of type lst_list* which contains a list
 *        of all words that match s or any variant of s obtained by 
 *        deleting one letter.
 */
lst_list *lookup_word(const char *s)
{
    /* this function needs to be implemented */
}


/* main - this is a correct function that should run without
 *    any modification. You should change it only to perform
 *    further testing. See README.txt for expected output.
 */
int main()
{
    init();
    /* make a very small dictionary */
    add_word("make");
    add_word("very");
    add_word("small");
    add_word("dictionary");
    add_word("their");
    add_word("there");
    add_word("thee");
    /* look up a word and print the results */
    lst_list *words = lookup_word("ther");
    /* print the words */
    while (ListNotEmpty(words)) {
        rb_red_blk_node *node = (rb_red_blk_node *) ListPop(words);
        printf("%s\n", (char *) (node->info));
    }
    free(words);
    cleanup();
    return 0; /* return 0 on success */
}
