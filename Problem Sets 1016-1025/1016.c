#include<stdio.h>

int f(int i) {
    int t = 2;
    for (; t < i; t++) { if (i % t == 0)return 0; }
    return 1;
}

int main() {
    int i = 1, n = 0;
    scanf("%d", &n);
    for (; i <= n; ++i) { if (f(i) == 1 && i != 1)printf("%d\n", i); }
}
