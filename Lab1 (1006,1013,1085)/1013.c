#include <stdio.h>
int main() {
    int a = 1,b=0,c=0,d=0;
    while (a != 0) {
        scanf("%d", &a);
        if (a >= 85) { b++; } else if (a>=60&&a<85) { c++; } else if (a > 0 && a < 60) { d++; }
    }
    printf(">=85:%d\n60-84:%d\n<60:%d", b, c, d);
}
