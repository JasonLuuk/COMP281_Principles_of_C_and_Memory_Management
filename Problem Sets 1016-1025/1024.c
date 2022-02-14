#include <stdio.h>

main() {
    int m, n, i, j, s = 0;
    scanf("%d %d", &m, &n);
    for (i = m; i <= n; i++) {
        if (i == 2) {
            s += i;
            continue;
        }
        for (j = 2; j < i; j++)if (i % j == 0)break;
        if (j == i) { s += i; }
    }
    printf("%d", s);
}
