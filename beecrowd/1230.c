#include <stdio.h>
#include <stdlib.h>

// Estrutura para armazenar pontos (x, f(x)) conhecidos
typedef struct {
    int x;
    int f;
} Point;

// Função de comparação para ordenar pontos por coordenada x
int compare_points(const void *a, const void *b) {
    Point *p1 = (Point *)a;
    Point *p2 = (Point *)b;
    return p1->x - p2->x;
}

int main() {
    int N, M, Y;
    while (scanf("%d %d %d", &N, &M, &Y) == 3) {
        // Aloca e lê os pontos conhecidos
        Point *points = (Point *)malloc(M * sizeof(Point));
        for (int i = 0; i < M; i++) {
            scanf("%d %d", &points[i].x, &points[i].f);
        }
        // Ordena pontos por x para processamento sequencial
        qsort(points, M, sizeof(Point), compare_points);

        // Calcula a parte fixa da integral (base) usando valores conhecidos
        // Considera:
        // - Primeiro e último ponto com peso 1
        // - Pontos internos com peso 2 (devido à fórmula dos trapézios)
        long long base = 0;
        base += points[0].f;
        base += points[M-1].f;
        for (int i = 1; i < M-1; i++) {
            base += 2 * points[i].f;
        }

        // Verifica se é possível ter solução inteira
        if ((2 * Y - base) % 2 != 0) {
            printf("N\n");
            free(points);
            continue;
        }

        // Calcula o valor que precisa ser alcançado pelos pontos desconhecidos
        long long S_target = (2LL * Y - base) / 2;

        // Calcula limites mínimo e máximo para cada segmento entre pontos conhecidos
        int seg_count = 0;
        long long total_low = 0, total_high = 0;

        for (int i = 1; i < M; i++) {
            int a = points[i-1].x;
            int b = points[i].x;
            int fa = points[i-1].f;
            int fb = points[i].f;
            int L = b - a - 1;  // Número de pontos desconhecidos no segmento
            
            if (L <= 0) continue;
            
            long long low_seg, high_seg;
            // Define limites baseado na monotonia (crescente ou decrescente)
            if (fa <= fb) {
                low_seg = (long long)L * fa;   // Mínimo: todos valores = fa
                high_seg = (long long)L * fb;  // Máximo: todos valores = fb
            } else {
                low_seg = (long long)L * fb;   // Mínimo: todos valores = fb
                high_seg = (long long)L * fa;  // Máximo: todos valores = fa
            }
            
            total_low += low_seg;
            total_high += high_seg;
            seg_count++;
        }

        // Verifica se o alvo está dentro dos limites possíveis
        if (S_target < total_low || S_target > total_high) {
            printf("N\n");
            free(points);
            continue;
        }

        // Distribui o valor alvo pelos segmentos
        long long *s_i = (long long *)malloc(seg_count * sizeof(long long));
        long long current_total_high = total_high;
        long long rem = S_target;

        // Para cada segmento, calcula quanto deve contribuir
        for (int i = 0; i < seg_count; i++) {
            int a = points[i].x;
            int b = points[i+1].x;
            int fa = points[i].f;
            int fb = points[i+1].f;
            int L = b - a - 1;
            
            long long low_seg, high_seg;
            if (fa <= fb) {
                low_seg = (long long)L * fa;
                high_seg = (long long)L * fb;
            } else {
                low_seg = (long long)L * fb;
                high_seg = (long long)L * fa;
            }

            current_total_high -= high_seg;
            long long min_s = low_seg;
            long long max_s = high_seg;
            long long s = min_s;

            // Ajusta a contribuição do segmento considerando os limites
            if (rem - current_total_high > s) {
                s = rem - current_total_high;
            }
            if (s > max_s) {
                s = max_s;
            }
            
            s_i[i] = s;
            rem -= s;
        }

        // Imprime a solução e os valores dos pontos desconhecidos
        printf("S");
        for (int i = 0; i < seg_count; i++) {
            int a = points[i].x;
            int b = points[i+1].x;
            int fa = points[i].f;
            int fb = points[i+1].f;
            int L = b - a - 1;
            long long s = s_i[i];
            long long current_sum = s;

            // Para cada ponto desconhecido no segmento
            for (int j = a + 1; j < b; j++) {
                int k = b - j;  // Pontos restantes no segmento
                int left_bound = (j == a + 1) ? fa : previous_value;
                int v;

                if (fa <= fb) {
                    // Caso crescente: valores devem ser não-decrescentes
                    long long candidate_low = current_sum - (k - 1) * (long long)fb;
                    int low = left_bound;
                    if (candidate_low > low) low = candidate_low;
                    
                    int high = fb;
                    long long candidate_high = current_sum / k;
                    if (candidate_high < high) high = candidate_high;
                    
                    v = low;
                    if (v > high) v = high;
                } else {
                    // Caso decrescente: valores devem ser não-crescentes
                    long long candidate_low = (current_sum + k - 1) / k;
                    int low = fb;
                    if (candidate_low > low) low = candidate_low;
                    
                    long long candidate_high = current_sum - (k - 1) * (long long)fb;
                    int high = left_bound;
                    if (candidate_high < high) high = candidate_high;
                    
                    v = low;
                    if (v > high) v = high;
                }

                printf(" %d", v);
                current_sum -= v;
                previous_value = v;
            }
        }
        printf("\n");

        free(s_i);
        free(points);
    }
    return 0;
}
