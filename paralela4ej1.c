#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

void print_vector(int *vec, int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Uso: %s <tamaño del vector>\n", argv[0]);
        return 1;
    }

    int n = atoi(argv[1]); 
    if (n <= 0) {
        printf("Por favor, introduzca un tamaño válido para el vector.\n");
        return 1;
    }

    int *vector = (int *)malloc(n * sizeof(int));
    if (vector == NULL) {
        printf("Error al asignar memoria para el vector.\n");
        return 1;
    }

    printf("Configuración por defecto de schedule:\n");
    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        vector[i] = omp_get_thread_num();
    }
    print_vector(vector, n);

    printf("\nConfiguración static (chunk = 2):\n");
    #pragma omp parallel for schedule(static, 2)
    for (int i = 0; i < n; i++) {
        vector[i] = omp_get_thread_num();
    }
    print_vector(vector, n);

    printf("\nConfiguración dynamic (chunk = 2):\n");
    #pragma omp parallel for schedule(dynamic, 2)
    for (int i = 0; i < n; i++) {
        vector[i] = omp_get_thread_num();
    }
    print_vector(vector, n);

    printf("\nConfiguración guided:\n");
    #pragma omp parallel for schedule(guided)
    for (int i = 0; i < n; i++) {
        vector[i] = omp_get_thread_num();
    }
    print_vector(vector, n);

    
    free(vector);
    return 0;
}
