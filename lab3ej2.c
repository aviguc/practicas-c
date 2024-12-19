#include <stdio.h>
int main ()
 {
    int base, exponente, potencia, i;
    printf("Dime la base y el exponente:"); scanf("%d %d", &base, &exponente); 
    if ((base >= 1) && (exponente >= 1)){
    potencia = 1;
    i = 1;
    while (exponente >= 1){
    potencia = potencia * base;
    exponente = exponente - 1;
    }
        printf("La potencia es: %d", potencia);
    }
    else{
        if(base > 0 && exponente == 0){
            printf("La potencia es: 1");
        }
        else{
            printf("La potencia es: Error\n");
        }
    }
 return 0;
 }