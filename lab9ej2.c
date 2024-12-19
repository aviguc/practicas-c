#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ALUMNOS 5
#define MAX_LONGITUD 100

void leerArchivo(const char *nombreArchivo, char alumnos[][MAX_LONGITUD], int *numAlumnos);
void buscarPorInicial(char alumnos[][MAX_LONGITUD], int numAlumnos, char inicial);
void imprimirMatriz(char alumnos[][MAX_LONGITUD], int numAlumnos);

int main() {
    char alumnos[MAX_ALUMNOS][MAX_LONGITUD]; 
    int numAlumnos = 0;                      
    char inicial;

    leerArchivo("info.txt", alumnos, &numAlumnos);

    printf("Introduce una letra para buscar alumnos por inicial: ");
    scanf(" %c", &inicial);

    printf("\nAlumnos que comienzan con la letra '%c':\n", inicial);
    buscarPorInicial(alumnos, numAlumnos, inicial);

    printf("\nContenido completo del archivo:\n");
    imprimirMatriz(alumnos, numAlumnos);

    return 0;
}

void leerArchivo(const char *nombreArchivo, char alumnos[][MAX_LONGITUD], int *numAlumnos) {
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) {
        perror("Error al abrir el archivo");
        exit(EXIT_FAILURE);
    }

    char *linea = NULL;
    size_t longitud = 0;
    ssize_t leidos;

    while ((leidos = getline(&linea, &longitud, archivo)) != -1 && *numAlumnos < MAX_ALUMNOS) {
        if (linea[leidos - 1] == '\n') {
            linea[leidos - 1] = '\0';
        }

        strncpy(alumnos[*numAlumnos], linea, MAX_LONGITUD - 1);
        alumnos[*numAlumnos][MAX_LONGITUD - 1] = '\0'; 
        (*numAlumnos)++;
    }

    free(linea); 
    fclose(archivo);
}

void buscarPorInicial(char alumnos[][MAX_LONGITUD], int numAlumnos, char inicial) {
    int encontrado = 0;
    for (int i = 0; i < numAlumnos; i++) {
        if (alumnos[i][0] == inicial) {
            printf("%s\n", alumnos[i]);
            encontrado = 1;
        }
    }
    if (!encontrado) {
        printf("No se encontraron alumnos con la inicial '%c'.\n", inicial);
    }
}

void imprimirMatriz(char alumnos[][MAX_LONGITUD], int numAlumnos) {
    for (int i = 0; i < numAlumnos; i++) {
        printf("%s\n", alumnos[i]);
    }
}
