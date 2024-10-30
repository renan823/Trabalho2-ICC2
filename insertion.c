#include <time.h>
#include <stdio.h>
#include <stdlib.h>

void insertion(int vec[], int n) {
    for (int i = 1; i < n; i++) {
        int key = vec[i];
        int j = i - 1;
        
        while (j >= 0 && vec[j] > key) {
            vec[j + 1] = vec[j];
            j = j - 1;
        }
        vec[j + 1] = key;
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
    insertion(vec, n);
    clock_t fim = clock();

    printf("Tempo decorrido: %lf segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    //debug
    for (int i = 0; i < n; i++) {
        printf("%d\n", vec[i]);
    }
    
    free(vec);

    return(0);
}