/*
 * linkedList.c - Various functions relating to linked lists
 * Author: Daniel Reay
 * COMP1917 S1 2014
 * Date: 26th May 2014
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// pointer to the node struct
typedef struct _node *nodePointer;

// pointer to the list struct
typedef struct _list *List;

// node containing some data and a pointer to the next node
typedef struct _node {
   int value;
   nodePointer next;
} node;

// struct containing pointer to first node in the list
typedef struct _list {
   nodePointer first;
} list;

// linked list functions
List newList (void);
int length (List l);
void appendItem (List l, int value);
void showList (List l);
void addItemEnd (List l, int value);
int getItem (List l, int position);
void deleteHead (List l);
void deleteLast (List l);
void concatenate (List to, List from);
void deleteAtPosition (List l, int position);
void addAtPosition (List l, int value, int position);
void moveToFront (List l, int positionFrom);
void moveToBack (List l, int positionFrom);
void moveToPosition (List l, int positionFrom, int positionTo);
void removeLargest (List l);
void removeSmallest (List l);
void reverseList (List l);
void swapNodes (List l, int positionFirst, int positionSecond);
int count42s (List l);
void splitLists (List oldList, List newList, int splitAfter);
void zip(List l1, List l2, List result);

// ====================================================================

int main (int argc, char *argv[]) {
    List l1 = newList();
    List l2 = newList();
    List l3 = newList();
    
    addItemEnd(l1, 5);
    addItemEnd(l1, 3);
    addItemEnd(l1, 1);
    
    addItemEnd(l2, 2);
    addItemEnd(l2, 4);
    addItemEnd(l2, 6);
    
    showList(l1);
    showList(l2);
    
    zip(l1, l2, l3);
    
    showList(l3);

   return EXIT_SUCCESS;
}


void zip(List l1, List l2, List result) {
    nodePointer cur1 = l1->first;
    nodePointer cur2 = l2->first;
    nodePointer curR = NULL;
    
    result->first = cur1;
    curR = result->first;
    
    while(cur1 != NULL && cur2 != NULL) {
        cur1 = cur1->next;
        curR->next = cur2;
        curR = curR->next;
        
        cur2 = cur2->next;
        curR->next = cur1;
        curR = curR->next;
    } 
}

void zip(List l1, List l2, List result) {
    // void addToNth(List l, int i, Node new)
    // Node removeFromFront(List l)
    
    int i = 0;
    
    while(length(l2) > 0) {
        addToNth(result, i, removeFromFront(l1));
        i++;
        addToNth(result, i, removeFromFront(l2));
        i++;
    }
}











