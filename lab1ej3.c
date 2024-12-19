#include <stdio.h>
int main(){
    float celsius;
    float grados_farenheit;
    printf("Introduce la temperatura en grados Celsius:");
    scanf("%f",&celsius);
    grados_farenheit = (celsius*9/5)+32;
    printf("Los grados farenheit son:%.2f", grados_farenheit);
    return 0;
}