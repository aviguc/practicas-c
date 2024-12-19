#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Uso: %s <cadena> <numero>\n", argv[0]);
        return 1;
    }

    char *cadenaArgumento = argv[1]; 
    int posicion = atoi(argv[2]);   
    char cadena[101];
    printf("Introduce una cadena de máximo 100 caracteres: ");
    fgets(cadena, 101, stdin);
    size_t longitud = strlen(cadena);
    if (cadena[longitud - 1] == '\n') {
        cadena[longitud - 1] = '\0';
    }
    printf("La longitud de la cadena introducida es: %zu\n", strlen(cadena));
    char cadenaConcatenada[201];
    strcpy(cadenaConcatenada, cadena); 
    strcat(cadenaConcatenada, " Cadena añadida");
    printf("Cadena concatenada: %s\n", cadenaConcatenada);
    if (strstr(cadena, cadenaArgumento) != NULL) {
        printf("La cadena introducida contiene la cadena '%s'.\n", cadenaArgumento);
    } else {
        printf("La cadena introducida no contiene la cadena '%s'.\n", cadenaArgumento);
    }
    if (posicion >= 0 && posicion < (int)strlen(cadena)) {
        printf("La letra en la posición %d es: %c\n", posicion, cadena[posicion]);
    } else {
        printf("La posición %d está fuera de rango.\n", posicion);
    }

    return 0;
}
