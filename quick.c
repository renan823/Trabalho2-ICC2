#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int partition(ITEM* vec[], int start, int end) {
    int mid = (start + end) / 2;
    ITEM* pivot = vec[mid];

    // mover pivot para o fim
    ITEM* aux = vec[end];
    vec[end] = pivot;
    vec[mid] = aux;

    int i = start - 1; //if start = 0 then i = -1
    for (int j = start; j < end; j++) {
        if (item_get_key(vec[j]) < item_get_key(pivot)) {
            i++;

            aux = vec[j];
            vec[j] = vec[i];
            vec[i] = aux;
        }
    }

    //fazer swap ultima vez (colocar pivo na posição)
    aux = vec[end];
    vec[end] = vec[i+1];
    vec[i+1] = aux;

    return(i+1); //posicão do pivo
}

void quick(ITEM* vec[], int start, int end) {
    if (start >= end) {
       return;
    }

    int pivotPos = partition(vec, start, end);
    quick(vec, start, pivotPos-1);
    quick(vec, pivotPos+1, end);
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
    quick(vec, 0, n-1);
    clock_t fim = clock();

    printf("Tempo decorrido: %lf segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    //debug
    for (int i = 0; i < n; i++) {
        printf("%d\n", vec[i]);
    }
    
    free(vec);

    return(0);
}