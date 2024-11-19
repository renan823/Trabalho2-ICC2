#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int contador_comp_chave = 0;
int contador_trocas = 0;

void shell(int* vec, int tam) {
    for (int h = tam / 2; h > 0; h /= 2) { 
        for (int i = h; i < tam; i++) {
            int temp = vec[i]; 
            int j;

            for (j = i; j >= h && vec[j - h] > temp; j -= h) {
                vec[j] = vec[j - h];
                contador_comp_chave++;
            }


            vec[j] = temp;
            contador_trocas++;
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
    shell(vec, n);
    clock_t fim = clock();

    printf("%lf\n", (double)(fim - inicio) / CLOCKS_PER_SEC);

    printf("%d\n", contador_comp_chave);
    printf("%d\n", contador_trocas);
    
    free(vec);

    return(0);
}
