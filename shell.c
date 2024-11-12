#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shell(int* vec, int tam) {
    int h = tam / 5;

    while (h >= 1) {
        printf("h: %d\n", h);
        for (int i = tam-1; i >= 0; i -= h) {
            for (int j = i - h; j >= 0; j -= h) {
                if((vec[i] < vec[j]) && (j >= 0)) {
                    int temp = vec[i];
                    vec[i] = vec[j];
                    vec[j] = temp;
                }
            }
        }

        h--;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);

    int* vec = (int*) malloc(n * sizeof(int));
    if (vec == NULL) {
        exit(1);
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &vec[i]);
    }

    clock_t inicio = clock();
    shell(vec, n);
    clock_t fim = clock();

    printf("Tempo decorrido: %lf segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    //debug
    for (int i = 0; i < n; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");

    free(vec);

    return(0);
}
