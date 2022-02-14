#include<stdio.h>

int main() {
    int a[10] = {0};
    int i, count = 0, average = 0;
    for (i = 0; i < 10; i++) {
        scanf("%d", &a[i]);
        average += a[i];
    }
    average /= 10;
    for (i = 0; i < 10; i++) {
        if (a[i] > average) {
            count++;
        }
    }
    printf("%d", count);
}
