#include <stdio.h>
void potencia (int x,int y);
int main(){
    int x;
    int y;
    do{
    printf("Introduce un valor x: ");
    scanf("%d",&x);
    if(x<0){
        printf("El valor es negativo");
    }
    }while(x<0);

    do{
    printf("Introduce un valor y: ");
    scanf("%d",&y);
    if(y<0){
        printf("El valor es negativo");
    }
    }while(y<0);

    potencia(x,y);

    return 0;
}
void potencia (int x,int y){
    int resultado = 1;
    for (int i = 0; i<y ; i++){
        resultado *= x;
    }
    printf("El resultado de elevar %d a %d es: %d",x,y,resultado);


}