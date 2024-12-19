#include <stdio.h>
int main ()
 {
    int Num, suma, i;
    printf("Introduce un número: "); scanf("%d", &Num); 
    suma = 0;
    i = 1;
    if (Num >= 1) {
    while (i <= Num){
    suma = suma + i;
    i = i + 1;
    }
        printf("La suma es: %d", suma);
    }
    else{
        printf("La suma es: Error");
 }
 return 0;
 }
 