void printList(List l) {
    printNode(l->head);
}

void printNode(Node n) {
    if (n != NULL) {
        printf("%d ->", n->data);
        printNode(n->next);
    }
}

int tri (int n) {
    if (n != 0) {
        n = n + tri(n - 1);
    }
    return n;
}
