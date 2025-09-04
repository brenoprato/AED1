#include <stdio.h>

int main(){
    int j, i = 10;
    int *p = &i;
    j = *p + i;

    printf("%d", j);
}