#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializa (int matriz[3][3]){
    for (int i=0; i<3; i++){
        for (int j=0; j<3; j++){
            matriz[i][j] = rand()%5+1;
        }
    }
}

void mul(int matriz1[3][3], int matriz2[3][3], int matriz3[3][3]){
    int suma = 0;
    for (int i=0; i<6; i++){
        for (int j=0; j<3; j++){
            matriz3[i][j] = 0;
            for (int k=0; k<3; k++){
                matriz3[i][j] += matriz1[i][k]*matriz2[k][j];
            }
        }
    }
}

int main () {
    int matriz1[3][3], matriz2[3][3], matriz3[3][3];
    srand(time(NULL));
    inicializa(matriz1);
    inicializa(matriz2);

    mul(matriz1, matriz2, matriz3);
    for (int i=0; i<6; i++){
        for (int j=0; j<3; j++){
            printf ("%d", matriz3[i][j]);
        }
        printf ("\n");
    }
    return 0;
}