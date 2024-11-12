#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *vec, int ini, int fim) {

}

void merge_sort(int *vec, int ini, int fim) {
    if(ini == fim) {
        return;
    }
    int meio = (ini + fim) / 2;
    merge_sort(vec, ini, meio);
    merge_sort(vec, meio + 1, fim);

    merge(*vec, ini, fim);
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

    printf("Tempo decorrido: %lf segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    //debug
    for (int i = 0; i < n; i++) {
        printf("%d\n", vec[i]);
    }

    free(vec);

    return(0);
}