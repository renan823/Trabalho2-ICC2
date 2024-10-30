#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Para usar, indique o numero de casos e o modo (normal | reverse | random)
Um arquivo sera criado como <modo>_<numero de casos>.txt
*/

int main(int argc, char* argv[]) {
    if (argc != 3) {
        exit(1);
    }

    int n = atoi(argv[1]); //numero de casos

    //Abrir arquivo para gravar (filename = argv[2]_<n>.txt)
    char filename[30];
    snprintf(filename, sizeof(filename), "%s_%d.txt", argv[2], n);
    FILE* file = fopen(filename, "w");

    if (file == NULL) {
        exit(1);
    }

    if (strcmp(argv[2], "normal") == 0) {
        for (int i = 1; i <= n; i++) {
            fprintf(file, "%d ", i);
            if (i % 10 == 0) {
                fprintf(file, "\n");
            }
        }
    }
    
    if (strcmp(argv[2], "reverse") == 0) {
        for (int i = n; i > 0; i--) {
            fprintf(file, "%d ", i);
            if (i % 10 == 0) {
                fprintf(file, "\n");
            }
        }
    }

    if (strcmp(argv[2], "random") == 0) {
        srand(time(NULL));
        for (int i = 1; i <= n; i++) {
            fprintf(file, "%d ", 1 + rand() % n);
            if (i % 10 == 0) {
                fprintf(file, "\n");
            }
        }
    }

    fclose(file);


    return(0);
}