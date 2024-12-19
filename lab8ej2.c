#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void noespacios(char *cadena, char *cadenasin) {
    int j = 0;  
    for (int i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] != ' ') {  
            cadenasin[j] = cadena[i];
            j++;
        }
    }
    cadenasin[j] = '\0';  
}

int main() {
    int n;

    printf("Longitud máxima de la cadena: ");
    scanf("%d", &n);

    while (getchar() != '\n');

    char *cadena = (char *)malloc((n + 1) * sizeof(char)); 
    if (cadena == NULL) {
        printf("Error al reservar memoria.\n");
        return 1;
    }

    char *cadenasin = (char *)malloc((n + 1) * sizeof(char)); 
    if (cadenasin == NULL) {
        printf("Error.\n");
        free(cadena);  
        return 1;
    }

    printf("Introduce una cadena: ");
    fgets(cadena, n + 1, stdin);

    size_t longitud = strlen(cadena);
    if (cadena[longitud - 1] == '\n') {
        cadena[longitud - 1] = '\0';
    }

    noespacios(cadena, cadenasin);

    printf("La cadena quitando espacios es: %s\n", cadenasin);

    free(cadena);
    free(cadenasin);

    return 0;
}
