#include<stdio.h>

int main() {
    int c = 0, r = 0;
    scanf("%d", &c);
    int b[c];
    for (int i = 0; i < c; i++) {
        scanf("%d", &b[i]);
        if (b[i] > r) { r = b[i]; }
    }
    int a[r][c];
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (b[j] >= i + 1) {
                scanf("%d", &a[i][j]);
            }
            else { a[i][j] = 1; }
        }
    }
    int s[c];
    int f = 1, k = 0;
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) { f = f * a[j][i]; }
        s[k] = f;
        k++;
        f = 1;
    }
    for (int i = 0; i < c; i++) { printf("%d ", s[i]); }
}
