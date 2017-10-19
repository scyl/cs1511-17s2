int tri (int n) {
    if (n != 0) {
        n = n + tri(n-1);
    }
    return n;
}
