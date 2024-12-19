#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int minimo(int *p, int n, int m){
    int min = 1000;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (*(p+i*m+j)<min){
                min = *(p+i*m+j);
            }
        }
    }
    return min;
}

void inicializar(int *p, int n, int m){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            *(p+i*m+j) = rand()%10+1;
        }
    }
}


int main () {
    int n, m, *p;
    srand(time(NULL));
    scanf("%d", &n);
    scanf("%d", &m);
    p = (int *)malloc(n*m*sizeof(int));
    inicializar(p, n, m);
    int min = minimo(p, n, m);
    for (int i=0; i<n; i++){
        printf("%d", *(p+i));
    }
    printf ("%d", min);
    free(p);
    return 0;
}