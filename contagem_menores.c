#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void contagem_menores(int *vec, int tam) {
    int *vec_menores = (int *)calloc(sizeof(int), tam);
    for (int i = 1; i < tam; i++){
        for (int j = i - 1; j >= 0; j--){
            if(vec[i] < vec[j]) {
                vec_menores[j]++;
            } else {
                vec_menores[i]++;
            }
        }
    }

    int *vec_ordenado = (int*) malloc(sizeof(int) * tam);

    for (int i = 0; i < tam; i++){
        vec_ordenado[vec_menores[i]] = vec[i];
    }

    for (int i = 0; i < tam; i++) {
        vec[i] = vec_ordenado[i];
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
    contagem_menores(vec, n);
    clock_t fim = clock();

    printf("Tempo decorrido: %lf segundos\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    //debug
    for (int i = 0; i < n; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");

    free(vec);

    return(0);
}
