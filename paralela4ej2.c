#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void print_matrix(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <número de filas (n)> <número de columnas (m)>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]); 
    int m = atoi(argv[2]); 

    if (n <= 0 || m <= 0) {
        printf("Por favor, introduzca valores válidos para n y m.\n");
        return 1;
    }

    
    int **matrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        matrix[i] = (int *)malloc(m * sizeof(int));
        if (matrix[i] == NULL) {
            printf("Error al asignar memoria para la matriz.\n");
            return 1;
        }
    }

    
    printf("Inicialización sin collapse:\n");
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = omp_get_thread_num();
        }
    }
    print_matrix(matrix, n, m);

    
    printf("\nInicialización con collapse(2):\n");
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = omp_get_thread_num();
        }
    }
    print_matrix(matrix, n, m);

    printf("\nConfiguración static (chunk = 2) con collapse:\n");
    #pragma omp parallel for collapse(2) schedule(static, 2)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = omp_get_thread_num();
        }
    }
    print_matrix(matrix, n, m);

    printf("\nConfiguración dynamic (chunk = 2) con collapse:\n");
    #pragma omp parallel for collapse(2) schedule(dynamic, 2)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = omp_get_thread_num();
        }
    }
    print_matrix(matrix, n, m);

    printf("\nConfiguración guided con collapse:\n");
    #pragma omp parallel for collapse(2) schedule(guided)
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = omp_get_thread_num();
        }
    }
    print_matrix(matrix, n, m);

    for (int i = 0; i < n; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
