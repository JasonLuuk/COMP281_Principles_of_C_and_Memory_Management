#include<stdio.h>

int main() {
    int x[255], y[255], s[255];
    char a[255], b[255];
    int n, m;
    scanf("%s", &a);
    scanf("%s", &b);
    for (n = 0; a[n] != '\0'; n++)x[n] = a[n] - '0';
    for (m = 0; b[m] != '\0'; m++)y[m] = b[m] - '0';
    int c = 0, k = 0, i = n - 1, j = m - 1;
    for (; i >= 0 && j >= 0; i--, j--, k++) {
        s[k] = (x[i] + y[j] + c) % 10;
        c = (x[i] + y[j] + c) / 10;
    }
    if (n > m) {
        while (i >= 0) {
            s[k++] = (x[i] + c) % 10;
            c = (x[i--] + c) / 10;
        }
    }
    else if (n < m) {
        while (j >= 0) {
            s[k++] = (y[j] + c) % 10;
            c = (y[j--] + c) / 10;
        }
    }
    else { if (c > 0)s[k++] = c; }
    for (k--; k >= 0; k--)printf("%d", s[k]);
}