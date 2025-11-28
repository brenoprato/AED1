#include <stdio.h>

int main() {
    int N, X, Y;
    int city_index = 1;
    int first = 1;

    while (scanf("%d", &N) && N != 0) {
        if (!first) {
            printf("\n");
        }
        first = 0;

        int count[201] = {0};
        int total_people = 0;
        int total_consumption = 0;

        for (int i = 0; i < N; i++) {
            scanf("%d %d", &X, &Y);
            total_people += X;
            total_consumption += Y;
            int C = Y / X;
            count[C] += X;
        }

        printf("Cidade# %d:\n", city_index);
        int printed = 0;
        for (int i = 0; i <= 200; i++) {
            if (count[i] > 0) {
                if (printed) {
                    printf(" ");
                }
                printf("%d-%d", count[i], i);
                printed = 1;
            }
        }
        printf("\n");

        double avg = (double)total_consumption / total_people;
        int integer_part = (int)avg;
        int fractional_part = (int)((avg - integer_part) * 100 + 0.0000001);
        printf("Consumo medio: %d.%02d m3.\n", integer_part, fractional_part);

        city_index++;
    }

    return 0;
}
