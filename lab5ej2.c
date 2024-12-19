#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void inicializa(char vector[26]);

int main() {
    char letras[26];    
    char vector_char[9];   
    srand(time(NULL));

    inicializa(letras);

    for (int i = 0; i < 8; i++) {
        int indice = rand() % 26; 
        vector_char[i] = letras[indice]; 
    }
    vector_char[8] = '\0';

    printf("%s", vector_char);

    return 0;
}

void inicializa(char vector[26]) {
    for (int i = 0; i < 26; i++) {
        vector[i] = 'a' + i;
    }
}