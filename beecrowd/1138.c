#include <stdio.h>

long long count_digit(long long n, int d) {
    if (n < 1) return 0;
    long long count = 0;
    long long base = 1;
    while (base <= n) {
        long long high = n / (base * 10);
        long long low = n % base;
        long long current_digit = (n / base) % 10;
        
        if (d != 0) {
            if (current_digit < d) {
                count += high * base;
            } else if (current_digit == d) {
                count += high * base + low + 1;
            } else {
                count += (high + 1) * base;
            }
        } else {
            if (high > 0) {
                if (current_digit == 0) {
                    count += (high - 1) * base + low + 1;
                } else {
                    count += high * base;
                }
            }
        }
        base *= 10;
    }
    return count;
}

int main() {
    long long A, B;
    while (scanf("%lld %lld", &A, &B) != EOF) {
        if (A == 0 && B == 0) break;
        long long results[10];
        for (int d = 0; d < 10; d++) {
            results[d] = count_digit(B, d) - count_digit(A - 1, d);
        }
        for (int d = 0; d < 10; d++) {
            if (d > 0) printf(" ");
            printf("%lld", results[d]);
        }
        printf("\n");
    }
    return 0;
}
