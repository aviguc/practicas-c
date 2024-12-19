#include <stdio.h>
void suma_n_numeros(int x);
int main(){
    int x;
    do{
    printf("Introduce un valor:");
    scanf("%d",&x);
    if (x<0){
        printf("No es positivo.");
    }
    }while(x<0);
    
    suma_n_numeros(x);
    
    return 0;
}
void suma_n_numeros(int x){
    int i,aux;
    i = 0;
    aux = 0;
    for (i=0; i<=x; i++){
        aux += i;
    }
    printf("La suma es:%d",aux);
}

    

