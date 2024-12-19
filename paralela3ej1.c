#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int tid, nthreads;
    int v;
    int *p;
    int sum=0;
    int resultado=0;
    int i, n;
    printf("Introduce tamaño v: \n");
    scanf("%d",&n);
    p = (int *)malloc(v*sizeof(int));
    
    
    #pragma omp parallel private (tid)
    {
        #pragma omp for
            for(i=0;i<n;i++){
                p[i]=rand()%100+1;
            }
        #pragma omp for reduction(+:sum)
            
            for (i=0;i<n;i++){
                sum+=p[i];
            }
    }

    resultado = sum/n;
    printf("la media es %d", resultado);
    free(p);
    return 0;
}