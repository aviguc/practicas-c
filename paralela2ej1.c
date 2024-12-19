#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 1000 

int main() {
    int tid, nthreads;
    int n;

    printf("Introduce el tamaño de la matriz: ", MAX_SIZE);
    scanf("%d", &n);

    if (n > MAX_SIZE) {
        printf("El tamaño máximo permitido para las matrices es %d.\n", MAX_SIZE);
        return 1;
    }

    int A[MAX_SIZE][MAX_SIZE];
    int B[MAX_SIZE][MAX_SIZE];
    int C[MAX_SIZE][MAX_SIZE];
    int D[MAX_SIZE][MAX_SIZE];

    double t1 = omp_get_wtime();

    #pragma omp parallel private(tid)
    {
        #pragma omp sections
        {
            #pragma omp section
            {
                srand(time(NULL) + omp_get_thread_num());
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        A[i][j] = rand() % 10 + 1; 
                    }
                }
            }

            #pragma omp section
            {
                srand(time(NULL) + omp_get_thread_num());
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        B[i][j] = rand() % 10 + 1; 
                    }
                }
            }

            #pragma omp section
            {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        C[i][j] = 0;
                        for (int k = 0; k < n; k++) {
                            C[i][j] += A[i][k] * B[k][j]; 
                        }
                    }
                }
            }

            #pragma omp section
            {
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < n; j++) {
                        D[i][j] = A[i][j] + B[i][j]; 
                    }
                }
            }
        }
    }

    double t2 = omp_get_wtime();
    printf("Tiempo de ejecución: %lf segundos\n", t2 - t1);

    return 0;
}
