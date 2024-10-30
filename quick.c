#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int median(int vec[], int start, int end) {
    int mid = (start + end) / 2;

    //ordenando os dados para achar a mediana
    if (vec[start] > vec[mid]) {
        swap(&vec[start], &vec[mid]);
    }

    if (vec[start] > vec[end]) {
        swap(&vec[start], &vec[end]);
    }

    if (vec[end] < vec[mid]) {
        swap(&vec[end], &vec[mid]);
    }

    return(mid);
}

int partition(int vec[], int start, int end) {
    int med = median(vec, start, end);
    int pivot = vec[med];

    // mover pivot para o fim
    swap(&vec[end], &vec[med]);

    int i = start - 1; //if start = 0 then i = -1
    for (int j = start; j < end; j++) {
        if (vec[j] < pivot) {
            i++;

            swap(&vec[j], &vec[i]);
        }
    }

    //fazer swap ultima vez (colocar pivo na posição)
    swap(&vec[end], &vec[i+1]);

    return(i+1); //posicão do pivo
}

void quick(int vec[], int start, int end) {
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