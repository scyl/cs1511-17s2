List zip(List l1, List l2) {
    Node cur1 = l1->head;
    Node cur2 = l2->head;
    Node curNew = l1->head;

    while(cur1 != NULL && cur2 != NULL) {
        cur1 = cur1->next;
        curNew->next = cur2;
        curNew = curNew->next;
        curNew->next = cur1;
        curNew = curNew->next;
        cur2 = cur2->next;
    }
    
    if (cur1 != NULL) {
        curNew->next = cur1;
    } else if (cur2 != NULL) {
        curNew->next = cur2;
    }
    
    return l1;
}
