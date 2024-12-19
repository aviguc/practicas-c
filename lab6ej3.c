#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializa (int *matriz){
    for (int i=0; i<6; i++){
        for (int j=0; j<6; j++){
            *(matriz+i*5+j) = rand()%10+1;
        }
    }
}

int suma(int *matriz){
    int suma = 0;
    for (int i=0; i<6; i++){
        for (int j=0; j<6; j++){
            suma += *(matriz+i*6+j);
        }
    }
    return suma;
}

int main () {
    int *matriz, suma;
    matriz = (int *)malloc(5*5*sizeof(int));
    srand(time(NULL));
    inicializa(matriz);
    suma = suma(matriz);
    printf ("%d", suma);
    free(matriz);
    return 0;
}