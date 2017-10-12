typedef struct _node *Node;
typedef struct _list *List;

typedef struct _list {
    Node head;
} list;

typedef struct _node {
    int value;
    Node next;
} node;

Node createNode(int val) {
    Node new = calloc(1, sizeof(node));
    if (new == NULL) {
        exit(1);
    }
    
    new->value = val;
    new->next = NULL;
    
    return new;
}

void printList(List l) {
    if (l == NULL) {
        exit(1);
    }
    
    Node cur = l->head;
    
    while(cur != NULL) {
        printf("%d -> ", cur->value);
        cur = cur->next;
    }
}

void addToEnd(List l, int val) {
    if (l == NULL) {
        exit(1);
    }
    
    // 1. General
    // 2. Empty
    // 3. Only one node
    
    Node newNode = createNode(val);
    
    if (l->head == NULL) {
        // 2
        l->head = newNode;
    } else {
        // 1 & 3
        Node cur = l->head;
        
        while(cur->next != NULL) {
            cur = cur->next;
        }
        
        cur->next = newNode;
    }
}

void removeEnd(list l) {
    if (l == NULL) {
        exit(1);
    }
    
    // 1. General
    // 2. Empty
    // 3. Only one node
    
    if (l->head == NULL) {
        // 2
        
    } else {
        if (l->head->next == NULL) {
            // 3
            free(l->head);
            l->head = NULL;
        } else {
            // 1
            Node cur = l->head;
            Node pre = NULL;
            
            while(cur->next != NULL) {
                pre = cur;
                cur = cur->next;
            }
            
            pre->next = cur->next;
            free(cur);
        }
    }
}
