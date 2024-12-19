#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<time.h>
int main(){
    int m,n,*p;
    int nthreads,tid;
    int i=0,j=0;
    int sum=0;
    int resultado=0;
    printf("Introduce n:\n");
    scanf("%d",&n);
    p = (int *)malloc(sizeof(int)*n);
    double t1 = omp_get_wtime();
    #pragma omp parallel private (tid)
    {
        srand(tid);
        #pragma omp for
                
                for(i=0;i<n;i++){
                    for(j=0;j<n;j++){
                        *(p+i*n+j)=rand()%10+1;
                    }
                }
        #pragma omp for reduction(+:sum)
            for (i=0;i<n;i++){
                for(j=0;j<n;j++){
                    sum+=*(p+i*n+j);
                }
            }
            
        
    }
    resultado=sum;
    printf("La suma es: %d",resultado);
    free(p);
    return 0;
}