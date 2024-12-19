#include <stdio.h>
#include <string.h>

int main() {
    char cadena[101];      
    char compara[] = "compara";  
    char añadida[] = "añadida";  

    printf("Introduce una cadena: ");
    fgets(cadena, 101, stdin);

    
    size_t longitud = strlen(cadena);
    if (cadena[longitud - 1] == '\n') {
        cadena[longitud - 1] = '\0';
        longitud--; 
    }

    printf("Longitud: %zu\n", longitud);

    if (strcmp(cadena, compara) == 0) {
        printf("La cadena es igual a 'compara'.\n");
    } else {
        printf("La cadena no es igual a 'compara'.\n");
    }

    strcat(cadena, añadida);
    printf("La cadena despues de concatenar es: %s\n", cadena);

    return 0;
}


