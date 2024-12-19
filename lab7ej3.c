#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void minfil(int *p, int n, int m, int *filas){
    for (int i=0; i<n; i++){
        int min = 1000;
        for (int j=0; j<m; j++){
            if (*(p+i*m+j)<min){
                min = *(p+i*m+j);
            }
        }
        *(filas+i) = min;
    }
}

void initix(int *p, int n, int m){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            *(p+i*m+j) = rand()%21-10;
        }
    }
}


int main () {
    int n, m, *p, *filas;
    srand(time(NULL));
    scanf("%d", &n);
    scanf("%d", &m);
    p = (int *)malloc(n*m*sizeof(int));
    filas = (int *)malloc(n*sizeof(int));
    initix(p, n, m);
    minfil(p, n, m, filas);
    for (int i=0; i<n; i++){
        printf ("%d", *(filas+i));
    }
    free(p);
    return 0;
}