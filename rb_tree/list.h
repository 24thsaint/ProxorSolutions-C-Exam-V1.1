#include "misc.h"

/*  CONVENTIONS:  All data structures for lists have the prefix */
/*                "lst_" to prevent name conflicts. */
/*                                                                      */
/*                Function names: Each word in a function name begins with */
/*                a capital letter.  An example funcntion name is  */
/*                CreateRedTree(a,b,c). Furthermore, each function name */
/*                should begin with a capital letter to easily distinguish */
/*                them from variables. */
/*                                                                     */
/*                Variable names: Each word in a variable name begins with */
/*                a capital letter EXCEPT the first letter of the variable */
/*                name.  For example, int newLongInt.  Global variables have */
/*                names beginning with "g".  An example of a global */
/*                variable name is gNewtonsConstant. */

/*  if DATA_TYPE is undefined then list.h and list.c will be code for */
/*  lists of void *, if they are defined then they will be lists of the */
/*  appropriate data_type */

#ifndef DATA_TYPE
#define DATA_TYPE void *
#endif

typedef struct lst_list_node {
  DATA_TYPE info;
  struct lst_list_node * next;
} lst_list_node;

typedef struct lst_list { 
  lst_list_node * top;
  lst_list_node * tail;
} lst_list ;

/*  These functions are all very straightforward and self-commenting so */
/*  I didn't think additional comments would be useful */
lst_list * ListJoin(lst_list * list1, lst_list * list2);
lst_list * ListCreate();
void ListPush(lst_list * theList, DATA_TYPE newInfoPointer);
void * ListPop(lst_list * theList);
int ListNotEmpty(lst_list *);
void ListDestroy(lst_list *);
