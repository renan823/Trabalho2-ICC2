#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int contador_comp_chave = 0;
int contador_trocas = 0;

void heap_rearrange(int vec[], int n, int index) {
    int left, right, max;
    int aux;

    left = 2*index + 1;
    right = 2*index + 2;
    max = index;


    if (left < n && vec[left] > vec[max]) {
        max = left;
    }
    contador_comp_chave++;

    if (right < n && vec[right] > vec[max]) {
        max = right;
    }
    contador_comp_chave++;

    if (max != index) {
        aux = vec[index];
        vec[index] = vec[max];
        vec[max] = aux;
        contador_trocas++;

        heap_rearrange(vec, n, max);
    }
}

void heap_create(int vec[], int n) {
    for (int i = n/2-1; i >= 0; i--) {
        heap_rearrange(vec, n, i);
    }
}

void heap(int vec[], int n) {
    int aux;
    int size = n;

    heap_create(vec, n);

    for (int i = 0; i < n; i++) {
        aux = vec[0]; //sempre o primeiro item
        vec[0] = vec[size-1];
        vec[size-1] = aux;

        size--;

        heap_rearrange(vec, size, 0); //sempre ordenar da raiz!
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
    heap(vec, n);
    clock_t fim = clock();

    printf("%lf\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    printf("%d\n", contador_comp_chave);
    printf("%d\n", contador_trocas);

    free(vec);

    return(0);
}