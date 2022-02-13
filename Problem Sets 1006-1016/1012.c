#include<stdio.h>
#include<stdlib.h>

int main() {
    int e = 1, b, x, y, a[e][e];
    scanf("%d", &e);
    for (int i = 0; i < e; i++) {
        for (int j = 0; j < e; j++) {
            scanf("%d", &a[i][j]);
            if (i == 0 && j == 0) {
                b = a[i][j];
                x = i + 1;
                y = j + 1;
            }
            else if (abs(a[i][j]) > abs(b)) {
                b = a[i][j];
                x = i + 1;
                y = j + 1;
            }
        }
    }
    printf("%d %d %d", b, x, y);
}
