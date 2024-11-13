#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shell(int* vec, int tam) {
    int h = tam / 2;

    while (h >= 1) {
        for (int i = tam-1; i >= 0; i -= h) {
            for (int j = i - h; j >= 0; j -= h) {
                if((vec[i] < vec[j]) && (j >= 0)) {
                    int temp = vec[i];
                    vec[i] = vec[j];
                    vec[j] = temp;
                }
            }
        }

        h /= 2;
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

    printf("%lf\n", (double)(fim - inicio) / CLOCKS_PER_SEC);
    
    free(vec);

    return(0);
}
