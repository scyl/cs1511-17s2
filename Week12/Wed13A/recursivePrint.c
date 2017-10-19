void printList(List l) {
    printNode(l->head);
}

void printNode(Node n) {
    if (n != NULL) {
        printf("%d -> ", n->data);
        printNode(n->next);
    }
}
