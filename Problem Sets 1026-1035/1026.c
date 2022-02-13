#include<stdio.h>

int main() {
    char s[100], c;
    int j, k;
    c = getchar();
    scanf("%s", s);
    for (j = k = 0; s[j] != '\0'; j++)if (s[j] != c)s[k++] = s[j];
    s[k] = '\0';
    printf("%s", s);
}
