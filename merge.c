#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int contador_comp_chave = 0;
int contador_trocas = 0;

void merge(int *vec, int ini, int fim, int meio) {
    int n1 = meio - ini + 1;
    int n2 = fim - meio;

    int L[n1], R[n2];

    for (int i = 0; i < n1; i++) {
        L[i] = vec[ini + i];
        contador_trocas++;
    }

    for (int j = 0; j < n2; j++) {
        R[j] = vec[meio + 1 + j];
        contador_trocas++;
    }

    int i = 0, j = 0;

    for (int k = ini; k <= fim; k++) {
        if (L[i] <= R[j]) {
            vec[k] = L[i];
            i++;
        } else {
            vec[k] = R[j];
            j++;
        }
        contador_comp_chave++;
    }
}

void merge_sort(int *vec, int ini, int fim) {
    if (ini < fim) {
        int meio = (ini + fim) / 2;
        merge_sort(vec, ini, meio);
        merge_sort(vec, meio + 1, fim);
        merge(vec, ini, fim, meio);
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
    merge_sort(vec, 0, n-1);
    clock_t fim = clock();

    printf("%lf\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    printf("%d\n", contador_comp_chave);
    printf("%d\n", contador_trocas);

    free(vec);

    return(0);
}
