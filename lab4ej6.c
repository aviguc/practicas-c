#include <stdio.h>
int factorial(int n);
int main(){
    int n;
    int resultado;
    scanf("%d",&n);
    if(n<0){
        printf("Error");
    }else{
    resultado = factorial(n);
    printf("El factorial de %d es: %d",n,resultado);
    }
return 0;
}
int factorial(int n){
    int resultado = 1;
    for(int i = 1; i<=n; i++){
        resultado *= i;
    }
return resultado;
}