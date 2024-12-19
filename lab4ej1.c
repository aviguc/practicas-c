#include <stdio.h>
void Calcula_nota (int x);
int main(){
    int x;
    printf("Introduzca un valor entre 0 y 10:");
    scanf("%d",&x);
    Calcula_nota(x);
    return 0;
}
void Calcula_nota (int x){
    if (x<0 || x>10){
        printf("El valor no está entre 0 y 10");
    }
    else{
        if(x >= 0 && x<5){
            printf("suspenso");
        }
        if(x == 5 || x == 6){
            printf("bien");
        }
        if(x == 7 || x == 8){
            printf("notable");
        }
        if(x == 9 || x == 10){
            printf("sobresaliente");
        }
    }
}
