#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int contador_comp_chave = 0;
int contador_trocas = 0;

int maior(int *vec, int n) {
    int max = vec[0];
    for (int i = 1; i < n; i++) {
        if (vec[i] > max) {
            max = vec[i];
        }
    }

    return(max);
}

void counting(int *vec, int n, int exp) {
    int max = maior(vec, n);
    int *contagem = (int *) calloc(sizeof(int), max);

    for (int i = 0; i < n; i++) {
        contagem[(vec[i] / exp) % 10]++;
    }

    for (int i = 1; i <= max; i++) {
        contagem[i] += contagem[i - 1];
    }

    int *ordenado = (int*) malloc(sizeof(int) * n);

    for (int i = n-1; i >= 0; i--) {
        ordenado[contagem[(vec[i] / exp) % 10] -1] = vec[i];
        contagem[(vec[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++) {
        vec[i] = ordenado[i];
    }

    free(contagem);
    free(ordenado);
}

void radix(int* vec, int n) {
    int digitos = maior(vec, n);

    for (int exp = 1; digitos / exp > 0; exp *= 10) {
        counting(vec, n, exp);
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
    radix(vec, n);
    clock_t fim = clock();

    printf("%lf\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    printf("%d\n", contador_comp_chave);
    printf("%d\n", contador_trocas);

    free(vec);

    return(0);
}
