main() {
    int n, i, s = 0;
    scanf("%d", &n);
    int *in = (int *) malloc(sizeof(int) * n);
    for (i = 0; i < n; i++) { scanf("%d", in + i); }
    for (i = 0; i < n; i++) { if (*(in + i) % 2 == 0) { s += *(in + i); }}
    printf("%d", s);
    free(in);
}
