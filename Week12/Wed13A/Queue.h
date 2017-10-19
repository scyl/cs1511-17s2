// Will determine how big stackData will be.
#define STACK_SIZE 1000

// An ADT, at last!
typedef struct _Queue *Queue;

// create a new Stack
Stack newQueue (void);

// destroy a stack
void destroyQueue (Queue s);

// this is our add function, 'char elt' = character element.
void queuePush (Queue s, char elt);
// addToFront(); 

// returns the topmost element
char queueNext (Queue s);
// getLast();

// this is our pop function -- takes an element off.
char queuePop (Queue s);
// removeLast();
