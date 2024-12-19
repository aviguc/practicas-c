#include <stdio.h>

int divisores(int n);

int main(){
    int n;
    int num_divisores;
    printf("Introduce un numero para saber sus divisores:");
    scanf("%d",&n);

    if (n<=0) {
        printf("Error");
    } else {
        num_divisores = divisores(n);
        printf("Los divisores de %d son: %d",n, num_divisores);
    }
    
    return 0;
}
int divisores(int n){
    int contador = 0;
    
    for (int i=1;i<=n;i++){
        if(n % i == 0){
            contador++;
        }

    }

    return contador;  
}