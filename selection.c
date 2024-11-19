#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int contador_comp_chave = 0;
int contador_trocas = 0;

void selection(int vec[], int n) {
    int aux;

    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (vec[j] < vec[min]) {
                min = j;
            }
            contador_comp_chave++;
        }

        if (min != i) {
            aux = vec[min];
            vec[min] = vec[i];
            vec[i] = aux;
            contador_trocas++;
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

    printf("%lf\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    printf("Número de comparações: %d\n", contador_comp_chave);
    printf("Número de trocas: %d\n", contador_trocas);
    
    free(vec);

    return(0);
}