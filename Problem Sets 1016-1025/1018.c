#include<stdio.h>

void R() {
    char c;
    scanf("%c", &c);
    if (c != '\0') {
        R();
        printf("%c", c);
    }
}

int main() { R(); }
