#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializa (int *matriz){
    for (int i=0; i<9; i++){
        *(matriz+i*9+i)=1;
    }
}

int main () {
    int *matriz;
    matriz = (int *)malloc(9*9*sizeof(int));
    srand(time(NULL));
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            printf ("%d", *(matriz+i*9+j));
        }
        printf ("\n");
    }
    free(matriz);
    return 0;
}