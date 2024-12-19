#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    int x;
    int tid, nthreads;
    int num, i;
    int ganador = 0;
    printf("Introduce un numero del 1 al 10000: ");
    scanf("%d", &x);
    

#pragma omp parallel num_threads(8) private(num)
    {
        tid=omp_get_thread_num();
        srand(tid);
        nthreads=omp_get_num_threads();
        while (ganador==0){
            num = rand()%10000+1;
            if (num==x){
                ganador = 1;
            }
        
        }
        
    }
    printf("El hilo %d ha ganado",tid);
    return 0;
}




