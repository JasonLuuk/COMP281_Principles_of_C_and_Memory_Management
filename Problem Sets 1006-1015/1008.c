#include<stdio.h>
#include<stdlib.h>

int main() {
    int a[9], j, n;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
        if (i == 0)n = a[0];
        if (abs(a[i]) < n) {
            n = a[i];
            j = i;
        }
    }
    a[j] = a[9];
    a[9] = n;
    for (int i = 0; i < 10; i++)printf("%d ", a[i]);
}
