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

// ========== create a new list ==========
List newList (void) {

   // create some memory for a pointer to a node
   List l = malloc (sizeof (struct _node));

   // make sure the creation worked
   assert (l != NULL);

   // set the list to point to NULL as its first node
   // so far this means we just have an empty list with no nodes
   l->first = NULL;

   return l;
}

// ========== produce number of items in list ==========
int length (List l) {

   int counter = 0;
   // pointer to the current node
   nodePointer current;

   // start at the first node in the list
   // count through the list until we hit NULL
   current = l->first;
   while (current != NULL) {
      counter++;
      // move onto the next node
      current = current->next;
   }

   return counter;
}

// ========== show everything in a list ==========
void showList (List l) {

   // pointer to the current node
   nodePointer current;

   // start at the first node in the list
   // count through until NULL, printing each element as we go
   current = l->first;
   while (current != NULL) {
      printf ("[%d] -> ", current->value);
      current = current->next;
   }

   // print [X] to signify the end of the list
   printf ("[X]\n\n");
}

// ========== show which item is at a particular position ==========
int getItem (List l, int position) {

   // pointer to the current node
   nodePointer current;
   int findPosition = 0;

   // set current to point to the first node in the list
   // cycle through the list until we reach the position we need
   current = l->first;
   while (findPosition != position) {
      current = current->next;
      // make sure we don't go past the end of the list
      assert (current != NULL);
      findPosition++;
   }

   int item = current->value;

   return item;
}

// ========== add an item to the start of the list ==========
void appendItem (List l, int value) {

   // check that we have a list to append to
   assert (l != NULL);

   // create a new node and give it a value
   nodePointer newNode = malloc (sizeof (struct _node));
   newNode->value = value;
   
   // new node now points to the old first node in the list
   newNode->next = l->first;

   // tell list which is the new start of the chain
   l->first = newNode;
}

// ========== add an item to the end of the list ==========
void addItemEnd (List l, int value) {

   // create a pointer to the new end of the list
   nodePointer newNode = malloc (sizeof (node));
   assert (newNode != NULL);
 
   // set the value for the new end and set its pointer to NULL
   newNode->value = value;
   newNode->next = NULL;
 
   // if the list is empty, set the first node to be the new item
   // otherwise find the end of the list
   if (l->first == NULL) {
      l->first = newNode;
   } else {
      nodePointer current = l->first;

      while (current->next != NULL) {
         current = current->next;
      }
 
      // add the item to the back of the list
      current->next = newNode;
   }
}

// ========== delete the first node from the list ==========
void deleteHead (List l) {

   // create a temporary pointer to the head of the list
   nodePointer temp = l->first;

   // set the new first node in the list to be the second node in temp
   l->first = temp->next;
}

// ========== delete the last node from the list ==========
void deleteLast (List l) {

   // create a pointer to the current and previous nodes
   nodePointer current;
   nodePointer previous = NULL;

   // check that the list is populated
   assert (l->first != NULL);

   // navigate to the last node of the list
   // and set previous to the second last node
   current = l->first;
   while (current->next != NULL) {
      previous = current;
      current = current->next;
   }

   // free the allocated memory and set it to NULL
   if (previous->next == current) {
      free (previous->next);
      previous->next = NULL;
   }
}

// ========== delete the node at a particular position ==========
void deleteAtPosition (List l, int position) {

   // if position is 0 we can just delete the head
   if (position == 0) {
      // create a temporary pointer to the head of the list
      nodePointer temp = l->first;
      // set the new first node in the list to be the second node in temp
      l->first = temp->next;
   } else {
      // create a pointer to the current and previous nodes
      nodePointer current;
      nodePointer previous = NULL;

      int findPosition = 0;

      // check that the list is populated
      assert (l->first != NULL);

      // navigate to the relevant node and set up the previous node
      current = l->first;
      while (findPosition != position) {
         previous = current;
         current = current->next;

         assert (current != NULL);
         findPosition++;
      }

      // free the allocated memory and set it to point to the node after
      if (previous->next == current) {
         free (previous->next);
         previous->next = current->next;
      }
   }
}

// ========== add a node at a particular position ==========
void addAtPosition (List l, int value, int position) {

   // check that we have a list to append to
   assert (l != NULL);

   // create a new node and give it a value
   nodePointer newNode = malloc (sizeof (struct _node));
   newNode->value = value;

   int finalPosition = length (l) - 1;

   if (position == finalPosition) {
      // set the pointer for the new node to NULL
      newNode->next = NULL;
    
      // if the list is empty, set the first node to be the new item
      // otherwise find the end of the list
      if (l->first == NULL) {
         l->first = newNode;
      } else {
         nodePointer current = l->first;

         while (current->next != NULL) {
            current = current->next;
         }
    
         // add the item to the back of the list
         current->next = newNode;
      }

   } else if (position == 0) {
      // new node now points to the old first node in the list
      newNode->next = l->first;
      // tell list which is the new start of the chain
      l->first = newNode;

   } else {
      nodePointer current;
      nodePointer previous = NULL;
      int findPosition = 0;

      // navigate to the relevant node and set up the previous node
      current = l->first;
      while (findPosition != position) {
         previous = current;
         current = current->next;

         assert (current != NULL);
         findPosition++;
      }
      
      // new node now points to the next node in the list
      newNode->next = current;

      // previous node now points to new node
      previous->next = newNode;
   }
}

// ========== move a particular node from one position to another ==========
void moveToPosition (List l, int positionFrom, int positionTo) {

   // create a new node and give it a value
   nodePointer newNode = malloc (sizeof (struct _node));
   newNode->value = 0;

   nodePointer current;
   nodePointer previous = NULL;
   int findPosition = 0;

   // if (positionFrom == 0) use this workaround
   int appended = 0;
   if (positionFrom == 0) {
      appendItem (l, 0);
      positionFrom = 1;
      appended = 1;
   }

   // navigate to the old position
   current = l->first;
   while (findPosition != positionFrom) {
      previous = current;
      current = current->next;

      assert (current != NULL);
      findPosition++;
   }

   // take the value from the node
   newNode->value = current->value;

   int finalPosition = length (l) - 1;

   if (positionTo == finalPosition) {
      // navigate to the back of the list
      current = l->first;
      while (current->next != NULL) {
            current = current->next;
         }
    
      // add the item to the back of the list
      current->next = newNode;

      // navigate to the new back of the list
      current = l->first;
      while (current != NULL) {
         previous = current;
         current = current->next;

         assert (current != NULL);
         findPosition++;
      }

      // free the allocated memory and set it to point to the node after
      if (previous->next == current) {
         free (previous->next);
         previous->next = current->next;
      }

   } else if (positionTo == 0) {
      // free the allocated memory and set it to point to the node after
      if (previous->next == current) {
         free (previous->next);
         previous->next = current->next;
      }

      // new node now points to the previous front of the list
      newNode->next = l->first;

      // tell list which is the new start of the chain
      l->first = newNode;

   } else {
      // free the allocated memory and set it to point to the node after
      if (previous->next == current) {
         free (previous->next);
         previous->next = current->next;
      }

      // navigate from there to the new position
      findPosition = 0;
      current = l->first;
      while (findPosition != positionTo) {
         previous = current;
         current = current->next;

         assert (current != NULL);
         findPosition++;
      }

      // new node now points to the next node in the list
      newNode->next = current;

      // previous node now points to new node
      previous->next = newNode;
   }

   // if we used the workaround for (positionFrom == 0),
   // now we delete the head that we appended
   if ((positionFrom == 1) && (appended == 1)) {
      deleteHead (l);
   }
}

// ========== move a particular node to the front of the list ==========
void moveToFront (List l, int positionFrom) {

   // create a new node and give it a value
   nodePointer newNode = malloc (sizeof (struct _node));
   newNode->value = 0;

   nodePointer current;
   nodePointer previous = NULL;
   int findPosition = 0;

   // navigate to the old position
   current = l->first;
   while (findPosition != positionFrom) {
      previous = current;
      current = current->next;

      assert (current != NULL);
      findPosition++;
   }

   // take the value from the node
   newNode->value = current->value;

   // free the allocated memory and set it to point to the node after
   if (previous->next == current) {
      free (previous->next);
      previous->next = current->next;
   }

   // new node now points to the previous front of the list
   newNode->next = l->first;

   // tell list which is the new start of the chain
   l->first = newNode;
}

// ========== move a particular node to the back of the list ==========
void moveToBack (List l, int positionFrom) {

   // create a new node and give it a value
   nodePointer newNode = malloc (sizeof (struct _node));
   newNode->value = 0;

   nodePointer current;
   nodePointer previous = NULL;
   int findPosition = 0;

   // navigate to the old position
   current = l->first;
   while (findPosition != positionFrom) {
      previous = current;
      current = current->next;

      assert (current != NULL);
      findPosition++;
   }

   // take the value from the node
   newNode->value = current->value;

   // navigate to the back of the list
   current = l->first;
   while (current->next != NULL) {
         current = current->next;
      }
 
   // add the item to the back of the list
   current->next = newNode;

   // navigate to the new back of the list
   current = l->first;
   while (current != NULL) {
      previous = current;
      current = current->next;

      assert (current != NULL);
      findPosition++;
   }

   // free the allocated memory and set it to point to the node after
   if (previous->next == current) {
      free (previous->next);
      previous->next = current->next;
   }
}

// ========== join one list onto the end of another ==========
void concatenate (List to, List from) {
   
   // create a pointer to the first node of the second list
   nodePointer current = from->first;

   // append each item of the second list onto the first
   while (current != NULL) {
      addItemEnd (to, current->value);
      current = current->next;
   }

   // delete each item from the second list to empty it
   while (from->first != NULL) {
      deleteHead(from);
   }
}

// ========== remove the largest value from the list ==========
void removeLargest (List l) {

   // create a pointer to the first node of the list
   nodePointer current;

   // set some variables to keep track of the largest value
   int currentPosition = 0;
   int largestPosition = 0;
   int tempValue = 0;

   // find the position of the largest value
   current = l->first;
   while (current->next != NULL) {
      tempValue = current->value;
      current = current->next;

      if (current->value > tempValue) {
         largestPosition = currentPosition + 1;
      }

      currentPosition++;
   }

   // if the front item is the smallest we can just delete the head
   if (largestPosition == 0) {
      // create a temporary pointer to the head of the list
      nodePointer temp = l->first;
      // set the new first node in the list to be the second node in temp
      l->first = temp->next;

   } else {
      // set up to delete the node from the list
      nodePointer previous = NULL;
      int findPosition = 0;

      // navigate to the relevant node and set up the previous node
      current = l->first;
      while (findPosition != largestPosition) {
         previous = current;
         current = current->next;

         assert (current != NULL);
         findPosition++;
      }

      // free the allocated memory and set it to point to the node after
      if (previous->next == current) {
         free (previous->next);
         previous->next = current->next;
      }
   }
}

// ========== remove the smallest value from the list ==========
void removeSmallest (List l) {

   // create a pointer to the first node of the list
   nodePointer current;

   // set some variables to keep track of the smallest value
   int currentPosition = 0;
   int smallestPosition = 0;
   int tempValue = 0;

   // find the position of the smallest value
   current = l->first;
   while (current->next != NULL) {
      tempValue = current->value;
      current = current->next;

      if (current->value < tempValue) {
         smallestPosition = currentPosition + 1;
      }

      currentPosition++;
   }

   // if the front item is the smallest we can just delete the head
   if (smallestPosition == 0) {
      // create a temporary pointer to the head of the list
      nodePointer temp = l->first;
      // set the new first node in the list to be the second node in temp
      l->first = temp->next;

   } else {
      // set up to delete the node from the list
      nodePointer previous = NULL;
      int findPosition = 0;

      // navigate to the relevant node and set up the previous node
      current = l->first;
      while (findPosition != smallestPosition) {
         previous = current;
         current = current->next;

         assert (current != NULL);
         findPosition++;
      }

      // free the allocated memory and set it to point to the node after
      if (previous->next == current) {
         free (previous->next);
         previous->next = current->next;
      }
   }
}

// ========== reverse the contents of a list ========== 
void reverseList (List l) {

   // create a pointer to the new node
   nodePointer newNode = malloc (sizeof (struct _node));
   assert (newNode != NULL);

   // set the new node to point to the start of the list
   newNode = l->first;
 
   // find the end of the list and count how long it took to get there
   nodePointer current = l->first;
   int counter = 0;
   while (current->next != NULL) {
      current = current->next;
      counter++;
   }

   // determine the number of swaps needed
   int numSwaps = ((counter + 1) / 2);

   // set up a temp value and two more counters
   int temp = 0;
   int i = 0;
   int j = counter - 1;

   counter = 0;
   
   // look into optimising this loop and minimising the need for counters
   while (counter < numSwaps) {
      // swap the two values (not the nodes/pointers, just the values)
      temp = newNode->value;
      newNode->value = current->value;
      current->value = temp;

      // move onto the next node in both directions (current goes back to
      // first, then goes to one node less than last time)
      newNode = newNode->next;
      current = l->first;

      while (i < j) {
         current = current->next;
         i++;
      }

      i = 0;
      j--;
      counter++;
   }
}

// ========== swap two given nodes of a list ==========
void swapNodes (List l, int positionFirst, int positionSecond) {

   // create two pointers, one for each node to be swapped
   nodePointer newFirst = malloc (sizeof (struct _node));
   assert (newFirst != NULL);
   
   nodePointer newSecond = malloc (sizeof (struct _node));
   assert (newSecond != NULL);

   // set each pointer to point to the start of the list
   newFirst = l->first;
   newSecond = l->first;

   // navigate each list to find the two nodes to be swapped
   int findPosFirst = 0;
   int findPosSecond = 0;

   while (findPosFirst != positionFirst) {
      newFirst = newFirst->next;
      findPosFirst++;   
   }

   while (findPosSecond != positionSecond) {
      newSecond = newSecond->next;
      findPosSecond++;   
   }

   // swap the two elements
   int temp = 0;
   temp = newFirst->value;
   newFirst->value = newSecond->value;
   newSecond->value = temp;
}

void splitLists (List oldList, List newList, int splitAfter) {
   
   // create a pointer to the first node of the list
   nodePointer current;

   // navigate to the position to split after
   int findPosition = 0;
   current = oldList->first;
   while (findPosition != splitAfter) {
      current = current->next;
      findPosition++;
   }

   // set the start of the new list to the first node after the split
   newList->first = current->next;

   // set the last node of the old list to point to NULL
   current->next = NULL;
}

// ========== count the number of 42's in a list ==========
int count42s (List l) {

   int numOf42s = 0;

   // create a pointer to the first node of the list
   nodePointer current;

   current = l->first;
   // check whether the value of each item is 42
   while (current != NULL) {
      if (current->value == 42) {
         numOf42s++;
      }

      current = current->next;
   }

   return numOf42s;
}
























void zip(List l1, List l2, List result) {
    // General
    // One list longer than other
    
    nodePointer cur1 = l1->first; 
    nodePointer cur2 = l2->first;
    nodePointer curResult = NULL;
    
    result->first = cur1;
    curResult = result->first;
    
    while (cur1 != NULL && cur2 != NULL) {
        cur1 = cur1->next;
        curResult->next = cur2;
        cur2 = cur2->next;
        curResult = curResult->next;
        curResult->next = cur1;
        curResult = curResult->next;
    }
}

void zip(List l1, List l2, List result) {
    // void add(List, int, Node)
    // Node remove(List, int)
    
    int i = 1;
    
    while (lenth(l2) > 0) {
        add(l1, i, remove(l2, 0));
        i += 2;
    }

}
