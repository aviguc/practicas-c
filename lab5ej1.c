#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void inicializa (int v[10]);
int suma(int v[]);
int main(){
    int v[10];
    int resultado;
    srand(time(NULL));
    inicializa(v);
    resultado = suma(v);
    printf("Elementos del vector: ");
    for(int i=0;i<10;i++){
        printf("%d", v[i]);
    }
    printf("El resultado es %d", resultado);
    
    return 0;
}
void inicializa (int v[10]){
    for(int i=0;i<10;i++){
        v[i]=rand()%10+1;
    }
    }
int suma(int v[10]){
    int resultado=0;
    for(int i=0;i<10;i++){
        resultado+=v[i];
    }
return resultado;
}