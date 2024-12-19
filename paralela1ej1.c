#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(){
    int nthreads, tid;
    int num;
    
#pragma omp parallel num_threads(8) private(tid, num)
    {
        tid=omp_get_thread_num();
        srand(tid);
        nthreads=omp_get_num_threads();
        num = rand()%100+1;
        printf("El numero aleatorio es %d en el hilo %d\n",num, tid);
    }
    return 0;
}








