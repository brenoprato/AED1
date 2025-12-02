#include <stdio.h>

#define PI 3.14159

double area(double r) {
    return PI * r * r;
}

int main() {
    double r;
    
    scanf("%lf", &r);
    double a = area(r);
    
    printf("A=%.4f\n", a);
    return 0;
}
