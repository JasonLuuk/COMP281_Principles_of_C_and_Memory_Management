#include<stdio.h>
#include<math.h>

float a(int n) {
    float f = 1;
    for (; n > 0; n--) { f *= n; }
    return f;
}

int main() {
    float y, f;
    int z;
    scanf("%f %d", &y, &z);
    for (; z > 0; z--)f += pow(-1, z - 1) * (pow(y, z)) / a(z);
    printf("%.4f\n", f);
}
