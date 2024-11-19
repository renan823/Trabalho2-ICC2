#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int contador_comp_chave = 0;
int contador_trocas = 0;

void bubble(int vec[], int n) {
    int aux;
    int swaps = 1;

    for (int i = 0; i < n && swaps > 0; i++) {
        swaps = 0;
        for (int j = 0; j < n-1-i; j++) {
            if (vec[j] > vec[j+1]) {
                aux = vec[j];
                vec[j] = vec[j+1];
                vec[j+1] = aux;
                swaps++;
                contador_trocas++;
            }
            contador_comp_chave++;
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
    bubble(vec, n);
    clock_t fim = clock();

    printf("%lf\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    printf("%d\n", contador_comp_chave);
    printf("%d\n", contador_trocas);
    
    free(vec);

    return(0);
}