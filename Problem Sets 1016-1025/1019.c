#include<stdio.h>

int s(int n) {
    int c = 0;
    if (n == 1)return 1;
    while (n > 1) {
        if (n % 2 == 1) n = n * 3 + 1; else n /= 2;
        c++;
    }
    return c + 1;
}

main() {
    int a, b, t, c = 0;
    scanf("%d%d", &a, &b);
    if (a > b) {
        t = a;
        a = b;
        b = t;
    }
    for (int i = a; i <= b; i++) { if (i == 1)c = s(i); else { if (s(i) > c)c = s(i); }}
    printf("%d", c);
}
