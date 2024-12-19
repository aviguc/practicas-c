#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializa (int *matriz){
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            *(matriz+i*5+j) = rand()%13+3;
        }
    }
}

int main () {
    int *matriz;
    matriz = (int *)malloc(5*5*sizeof(int));
    srand(time(NULL));
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            printf ("%d", *(matriz+i*5+j));
        }
        printf ("\n");
    }
    free(matriz);
    return 0;
}