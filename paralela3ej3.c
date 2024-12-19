#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>

void inicializar_matriz(int *matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            *(matriz + i * columnas + j) = rand() % 10 + 1; 
        }
    }
}

void imprimir_matriz(int *matriz, int filas, int columnas) {
    for (int i = 0; i < filas; i++) {
        for (int j = 0; j < columnas; j++) {
            printf("%d ", *(matriz + i * columnas + j));
        }
        printf("\n");
    }
}

void multiplicar_matrices(int *A, int *B, int *C, int n, int m, int p, int num_hilos) {
    #pragma omp parallel for num_threads(num_hilos)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < p; j++) {
            *(C + i * p + j) = 0; 
            for (int k = 0; k < m; k++) {
                *(C + i * p + j) += *(A + i * m + k) * *(B + k * p + j);
            }
        }
    }
}

int main() {
    int n, m, p, num_hilos;
    
    printf("Ingrese las dimensiones de las matrices A (n x m) y B (m x p):\n");
    printf("n (filas de A): ");
    scanf("%d", &n);
    printf("m (columnas de A y filas de B): ");
    scanf("%d", &m);
    printf("p (columnas de B): ");
    scanf("%d", &p);

    printf("Ingrese el número de hilos a usar: ");
    scanf("%d", &num_hilos);

    
    int *A = (int *)malloc(n * m * sizeof(int));
    int *B = (int *)malloc(m * p * sizeof(int));
    int *C = (int *)malloc(n * p * sizeof(int));

    if (A == NULL || B == NULL || C == NULL) {
        printf("Error al asignar memoria.\n");
        return -1;
    }

    srand(time(NULL)); 

    inicializar_matriz(A, n, m);
    inicializar_matriz(B, m, p);

    printf("\nMatriz A:\n");
    imprimir_matriz(A, n, m);

    printf("\nMatriz B:\n");
    imprimir_matriz(B, m, p);

    double inicio = omp_get_wtime();
    multiplicar_matrices(A, B, C, n, m, p, num_hilos);
    double fin = omp_get_wtime();

    printf("\nMatriz C (Resultado de A x B):\n");
    imprimir_matriz(C, n, p);

    printf("\nTiempo de ejecución: %f segundos\n", fin - inicio);

    
    free(A);
    free(B);
    free(C);

    return 0;
}

