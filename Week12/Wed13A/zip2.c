List zip(List l1, List l2) {
    int i1 = 1;
    
    while (length(l2) > 0) {
        addToNth(l1, i1, removeFromNth(l2, 0));
        i1++;
        i1++;
    }
}
