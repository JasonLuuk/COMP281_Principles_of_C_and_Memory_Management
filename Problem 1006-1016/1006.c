#include<stdio.h>
int main() {
    char a,b,c;
    scanf(" %c %c %c",&a, &b, &c);
    printf("%hd", (int)(a+b+c)-144);
}
