#include<stdio.h>

int main() {
    int a[9], n = 10, i, j, t;
    for (int i = 0; i < 10; i++) { scanf("%d", &a[i]); }
    for (i = 0; i < n - 1; ++i) {
        for (j = 0; j < n - 1 - i; ++j) {
            if (a[j] > a[j + 1]) {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    for (int i = 0; i < 10; i++) { printf("%d ", a[i]); }
}
