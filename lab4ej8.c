#include <stdio.h>
int esprimo(int n);
int divisores(int n);
int main(){
    int n;
    printf("Introduce un numero entero:\n");
    scanf("%d",&n);
    esprimo(n);
    if(esprimo(n)){
        printf("El numero es primo");
    } else{
        printf("El numero no es primo");
    }
    return 0;
}
int esprimo(int n){
    return divisores(n) == 2;
}
int divisores (int n){
    int contador = 0;
    
    for (int i=1;i<=n;i++){
        if(n % i == 0){
            contador++;
        }

    }

    return contador;  
}