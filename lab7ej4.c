#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializar (int *p, int n){
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            *(p+i*n+j) = rand()%10+1;
        }
    }
}

void multi(int *matriz1, int *matriz2, int *matriz3, int n){
    int suma = 0;
    for (int i=0; i<6; i++){
        for (int j=0; j<3; j++){
            *(matriz3+i*n+j) = 0;
            for (int k=0; k<3; k++){
                *(matriz3+i*n+j) += *(matriz1+i*n+k) * *(matriz2+k*n+j);
            }
        }
    }
}

int main () {
    int matriz1[3][3], matriz2[3][3], matriz3[3][3], n;
    scanf("%d", &n);
    srand(time(NULL));
    inicializar(*matriz1, n);
    inicializar(*matriz2, n);

    multi(matriz1, matriz2, matriz3, n);
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            printf ("%d", *(matriz3+i*n+j));
        }
        printf ("\n");
    }
    return 0;
}