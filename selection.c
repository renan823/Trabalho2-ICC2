#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void selection(int vec[], int n) {
    int aux;

    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (vec[j] < vec[min]) {
                min = j;
            }
        }

        if (min != i) {
            aux = vec[min];
            vec[min] = vec[i];
            vec[i] = aux;
        }
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
    selection(vec, n);
    clock_t fim = clock();

    printf("Tempo decorrido: %lf segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    //debug
    for (int i = 0; i < n; i++) {
        printf("%d\n", vec[i]);
    }
    
    free(vec);

    return(0);
}