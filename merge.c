#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int contador_comp_chave = 0;
int contador_trocas = 0;

void merge(int *vec, int ini, int fim, int meio) {
    int i, j, k, n1, n2;

    n1 = meio - ini + 1;
    n2 = fim - meio;

    int L[n1+1], R[n2+1];

    for (i = 0; i < n1; i++) {
        L[i] = vec[ini + i];
    }

    L[n1] = 9999;

    for(j = 0; j < n2; j++) {
        R[j] = vec[meio + 1 + j];
    }

    R[n2] = 9999;

    i = j = 0;

    for (k = ini; k <= fim; k++) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
    }
}

void merge_sort(int *vec, int ini, int fim) {
    if(ini < fim) {
        int meio = (ini + fim) / 2;
        merge_sort(vec, ini, meio);
        merge_sort(vec, meio + 1, fim);
        merge(vec, ini, fim, meio);
        contador_trocas++;
    }
    contador_comp_chave++;
    return;
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
    merge_sort(vec, 0, n-1);
    clock_t fim = clock();

    printf("%lf\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    printf("Número de comparações: %d\n", contador_comp_chave);
    printf("Número de trocas: %d\n", contador_trocas);

    free(vec);

    return(0);
}