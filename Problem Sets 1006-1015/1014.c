#include<stdio.h>

int main() {
    float a, b, c, d;
    scanf("%f%f", &a, &b);
    while (a <= b) {
        c += 3.14 * a * a;
        d += 2 * 3.14 * a;
        ++a;
    }
    printf("%.3f\n%.3f", c, d);
}
