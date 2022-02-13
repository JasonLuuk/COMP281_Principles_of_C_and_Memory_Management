#include<stdio.h>

main() {
    int i = 0;
    char c;
    while ((c = getchar()) != EOF) { if (c == '$') { i++; }}
    printf("%d", i);
}
