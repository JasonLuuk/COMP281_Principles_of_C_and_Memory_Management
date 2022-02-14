#include <stdio.h>

int main() {
    char c;
    int l = 0, s = 0, d = 0, o = 0;;
    while ((c = getchar()) != EOF) {
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z') { l++; }
        else if (c == ' ') { s++; } else if (c >= '0' && c <= '9') { d++; } else { o++; }
    }
    printf("%d %d %d %d", l, d, s, o);
}
