#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int tid, nthreads;
    int n;
    printf("n");
    scanf("%d",&n);
    int *a= (int *)malloc(n*n*sizeof(int));
    int *b= (int *)malloc(n*n*sizeof(int));
    int *c= (int *)malloc(n*n*sizeof(int));
    int *d= (int *)malloc(n*n*sizeof(int));
    
    double t1 = omp_get_wtime();
    #pragma omp parallel private(tid)
    {
        
        #pragma omp sections
        {
            #pragma omp section
            {
                
                srand(tid);
                for(int i=0;i<100;i++){
                    for(int j=0;j<100;j++){
                        *(a+i*n+j) = rand()%10+1;
                    }
                }
                
            }
            #pragma omp section
            {
                srand(tid);
                for(int i=0;i<100;i++){
                    for(int j=0;j<100;j++){
                        *(b+i*n+j) = rand()%10+1;
                    }
                }
            }
            #pragma omp section
            {
           
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        *(c+i*n+j) = (*(a+i*n+j))*(*(b+i*n+j));
                    }
            
                }
            }

            #pragma omp section
            {
            
                for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
                        *(d+i*n+j) = (*(a+i*n+j))+(*(b+i*n+j));
                    }
                }
            }
        }
    }

    double t2 = omp_get_wtime();
    printf("%lf",t2-t1);
    return 0;
}