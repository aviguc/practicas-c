#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializa (int matriz[3][6]){
    for (int i=0; i<3; i++){
        for (int j=0; j<6; j++){
            matriz[i][j] = rand()%10+1;
        }
    }
}

void sumaf(int matriz[3][6], int sumas[6]){
    int suma = 0;
    for (int i=0; i<6; i++){
        for (int j=0; j<3; j++){
            suma += matriz[j][i];
        }
        sumas[i] = suma;
        suma = 0;
    }
}

int main () {
    int matriz[3][6], sumas[6];
    srand(time(NULL));
    inicializa(matriz);
    sumaf(matriz, sumas);
    for (int i=0; i<6; i++){
        printf ("%d", sumas[i]);
    }
    return 0;
}

