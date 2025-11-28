#include <stdio.h>
#include <string.h>

#define MAX_INPUT 2002

char input[MAX_INPUT];
char output[MAX_INPUT * 2];
int output_len;

void append_char(char c) {
    output[output_len++] = c;
}

int main() {
    int N;
    scanf("%d", &N);
    getchar(); // Consumir o newline após N

    for (int case_num = 0; case_num < N; case_num++) {
        fgets(input, MAX_INPUT, stdin);
        int len = strlen(input);
        if (len > 0 && input[len-1] == '\n') {
            input[len-1] = '\0';
            len--;
        }

        output_len = 0;
        int i = 0;
        while (i < len) {
            if (input[i] == '0') {
                int count = 0;
                int j = i;
                while (j < len && input[j] == '0') {
                    count++;
                    j++;
                }
                if (count > 2) {
                    int n = count;
                    while (n > 0) {
                        if (n > 255) {
                            append_char('#');
                            append_char((char)255);
                            n -= 255;
                        } else {
                            append_char('#');
                            append_char((char)n);
                            n = 0;
                        }
                    }
                    i = j;
                } else {
                    append_char(input[i]);
                    i++;
                }
            } else if (input[i] == ' ') {
                int count = 0;
                int j = i;
                while (j < len && input[j] == ' ') {
                    count++;
                    j++;
                }
                if (count > 2) {
                    int n = count;
                    while (n > 0) {
                        if (n > 255) {
                            append_char('$');
                            append_char((char)255);
                            n -= 255;
                        } else {
                            append_char('$');
                            append_char((char)n);
                            n = 0;
                        }
                    }
                    i = j;
                } else {
                    append_char(input[i]);
                    i++;
                }
            } else {
                append_char(input[i]);
                i++;
            }
        }
        output[output_len] = '\0';
        printf("%s\n", output);
    }
    return 0;
}

