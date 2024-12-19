#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maximo(int *p, int n){
    int max = 0;
    for (int i=0; i<n; i++){
        if (*(p+i)>max){
            max = *(p+i);
        }
    }
    return max;
}

int main () {
    int n, *p;
    srand(time(NULL));
    scanf("%d", &n);
    p = (int *)malloc(n*sizeof(int));
    for (int i=0; i<n; i++){
        scanf("%d", p+i);
    }
    int max = maximo(p, n);
    for (int i=0; i<n; i++){
        printf("%d", *(p+i));
    }
    printf ("%d", max);
    free(p);
    return 0;
}