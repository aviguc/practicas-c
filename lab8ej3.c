#include <stdio.h>
#include <string.h>

void invertir(char *cadenaorigen, char *cadenadestino) {
    int longitud = strlen(cadenaOrigen)
    for (int i = 0; i < longitud; i++) {
        cadenadestino[i] = cadenaorigen[longitud - i - 1]; 
    }
    cadenadestino[longitud] = '\0'; 
}

int main() {
    char cadena[101];     
    char cadenaInvertida[101]; 

    printf("Introduce una cadena: ");
    fgets(cadena, 101, stdin);

    size_t longitud = strlen(cadena);
    if (cadena[longitud - 1] == '\n') {
        cadena[longitud - 1] = '\0';
    }

    invertir(cadena, cadenaInvertida);

    printf("La cadena invertida es: %s\n", cadenaInvertida);

    return 0;
}

