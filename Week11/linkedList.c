typedef struct _node *Node;
typedef struct _list *List;

typedef struct _list {
    Node head;
} list;

typedef struct _node {
    int value;
    Node next;
} node;

List createList() {
    List new = calloc(1, sizeof(list));
    new->head = NULL;
    
    return new;
}

void printList(List list) {
    if (list != NULL) {
        Node cur = list->head;
        while (cur != NULL) {
            printf("%d -> ", cur->value);
            cur = cur->next;
        }
    }
}

void addToEnd(List list, int num) {
    if (list != NULL) {
        Node new = createNode(num);
        
        if (list->head == NULL) {
            list->head = new;
        } else {
            Node cur = list->head;
            while (cur->next != NULL) {
                cur = cur->next;
            }
            
            cur->next = new;
        }
    }
}

void removeSecondNode(List list) {
    if (list != NULL) {
        Node pre = NULL;
        Node cur = list->head;
        int count = 0;
        
        while (count < 2) {
            pre = cur;
            cur = cur->next;
            count++;
        }
        
        pre->next = cur->next;
        
        free(cur);
    }
}
