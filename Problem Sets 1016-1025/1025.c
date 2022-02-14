#include<stdio.h>

int main() {
    int m, n, a, b, c;
    scanf("%d %d", &a, &b);
    m = a;
    n = b;
    while (b != 0) {
        c = a % b;
        a = b;
        b = c;
    }
    printf("%d %d", a, m * n / a);
}
