#include "list.h"

int ListNotEmpty(lst_list * theList) {
  return( theList ? theList->top != NULL : 0);
}

lst_list * ListJoin(lst_list * list1, lst_list * list2) {
  if (!list1->tail) {
    free(list1);
    return(list2);
  } else if (!list2->tail) {
    free(list2);
    return(list1);
  } else {
    list1->tail->next=list2->top;
    list1->tail=list2->tail;
    free(list2);
    return(list1);
  }
}

lst_list * ListCreate() {
  lst_list * newList;
  
  newList=(lst_list *) SafeMalloc(sizeof(lst_list));
  newList->top=newList->tail=NULL;
  return(newList);
}


void ListPush(lst_list * theList, void *newInfoPointer) {
  lst_list_node * newNode;

  if(!theList->top) {
    newNode=(lst_list_node *) SafeMalloc(sizeof(lst_list_node));
    newNode->info=newInfoPointer;
    newNode->next=theList->top;
    theList->top=newNode;
    theList->tail=newNode;
  } else {
    newNode=(lst_list_node *) SafeMalloc(sizeof(lst_list_node));
    newNode->info=newInfoPointer;
    newNode->next=theList->top;
    theList->top=newNode;
  }
  
}

void *ListPop(lst_list * theList) {
  void *popInfo;
  lst_list_node * oldNode;

  if(theList->top) {
    popInfo=theList->top->info;
    oldNode=theList->top;
    theList->top=theList->top->next;
    free(oldNode);
    if (!theList->top) theList->tail=NULL;
  } else {
    popInfo=NULL;
  }
  return(popInfo);
}

/* ListDestroy destroys the list, but not the info pointed
 *  to by the list. In other words, this is a shallow 
 *  destroy. In the red-black tree, lists point to nodes in
 *  the tree, and destroying these tree nodes is usually
 *  incorrect. 
 */
void ListDestroy(lst_list * theList) {
  lst_list_node * x=theList->top;
  lst_list_node * y;

  if(theList) {
    while(x) {
      y=x->next;
      free(x);
      x=y;
    }
    free(theList);
  }
} 
    
