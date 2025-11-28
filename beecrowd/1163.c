#include <stdio.h>
#include <math.h>

#define g 9.80665
#define PI 3.14159

int main() {
    double h;
    int p1, p2;
    int n;
    while (scanf("%lf", &h) != EOF) {
        scanf("%d %d", &p1, &p2);
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            double alpha, V;
            scanf("%lf %lf", &alpha, &V);
            double rad = alpha * PI / 180.0;
            double vx = V * cos(rad);
            double vy = V * sin(rad);
            double delta = vy * vy + 2 * g * h;
            double t = (vy + sqrt(delta)) / g;
            double x = vx * t;
            if (x >= p1 && x <= p2) {
                printf("%.5lf -> DUCK\n", x);
            } else {
                printf("%.5lf -> NUCK\n", x);
            }
        }
    }
    return 0;
}
