#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int contador_comp_chave = 0;
int contador_trocas = 0;

void contagem_menores(int *vec, int n) {
    int max = vec[0];
    for (int i = 1; i < n; i++) {
        if (vec[i] > max) {
            max = vec[i];
        }
    }

    int *contagem = (int *) calloc(sizeof(int), max); //inicia com zero já

    for (int i = 0; i < n; i++) {
        contagem[vec[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        contagem[i] += contagem[i - 1];
    }

    int *ordenado = (int*) malloc(sizeof(int) * n);

    for (int i = n-1; i >= 0; i--) {
        ordenado[contagem[vec[i]] -1] = vec[i];
        contagem[vec[i]]--;
    }

    for (int i = 0; i < n; i++) {
        vec[i] = ordenado[i];
    }

    free(contagem);
    free(ordenado);
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
    contagem_menores(vec, n);
    clock_t fim = clock();

    printf("%lf\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    printf("%d\n", contador_comp_chave);
    printf("%d\n", contador_trocas);

    free(vec);

    return(0);
}
