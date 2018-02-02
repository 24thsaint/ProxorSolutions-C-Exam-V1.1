/* rbdict.c -- solution to rbdictxf task
 */

#include <stdio.h>
#include <string.h>
#include "../rb_tree/red_black_tree.h"
#define TRUE 1
#define FALSE 0

/* do not change the name of rbtree, and do not make it static */
rb_red_blk_tree *rbtree = NULL;

/* define functions for red black tree here */
/* init - initialize rbtree
 *   before calling init, rbtree is NULL
 *   when init returns, rbtree must be an empty tree
 */
void init()
{
    /* implement init() here */
}

/* cleanup - deallocate all allocated memory 
 *    before calling cleanup, rbtree is either NULL or a tree
 *    after cleanup, rbtree is NULL and any memory allocated
 *          by rbtree functions or other functions is freed
 */
void cleanup()
{
    /* implement cleanup() here */
}

/* note: main ignores any command-line arguments */
int main()
{
    rbtree; /* if you removed the declaration of rbtree, 
               you should get a compilation error here */
    init();
    int pass = 1;
    /* if you did not define compare, the next line should alert you */
    compare("a", "b");
    pass &= (dict_get("pi") == 0.0);
    dict_put("pi", 3.14159);
    pass &= (dict_get("pi") == 3.14159);
    dict_put("speed of light in furlongs per fortnight", 1.8e12);
    pass &= (dict_get("speed of light in furlongs per fortnight") == 1.8e12);
    cleanup();
    if (pass) {
        printf(
            "dict_put() and dict_get() worked as expected in simple tests.\n");
    } else {
        printf("There is a problem with dict_put() or dict_get().\n");
    }
    return 0; /* return 0 on success */
}
