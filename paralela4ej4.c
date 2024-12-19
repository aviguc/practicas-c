#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

int main() {
    int n;

    do {
        printf("Introduce el número de alumnos (positivo): ");
        scanf("%d", &n);
    } while (n <= 0);

    
    int vector1[n], vector2[n];
    srand(time(NULL)); 


    #pragma omp parallel for
    for (int i = 0; i < n; i++) {
        vector1[i] = rand() % 11;
        vector2[i] = rand() % 11;
    }
    double media1 = 0, media2 = 0;
    int min1 = 10, max1 = 0;
    int min2 = 10, max2 = 0;

    #pragma omp parallel for reduction(+:media1,media2) reduction(min:min1,min2) reduction(max:max1,max2) nowait
    for (int i = 0; i < n; i++) {
    
        media1 += vector1[i];
        media2 += vector2[i];

        if (vector1[i] < min1) min1 = vector1[i];
        if (vector1[i] > max1) max1 = vector1[i];

        if (vector2[i] < min2) min2 = vector2[i];
        if (vector2[i] > max2) max2 = vector2[i];
    }

    media1 /= n;
    media2 /= n;

    printf("Resultados del Primer Parcial:\n");
    printf("Media: %.2f, Mínimo: %d, Máximo: %d\n", media1, min1, max1);

    printf("Resultados del Segundo Parcial:\n");
    printf("Media: %.2f, Mínimo: %d, Máximo: %d\n", media2, min2, max2);

    return 0;
}
