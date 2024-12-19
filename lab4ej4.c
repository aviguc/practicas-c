#include <stdio.h>
int menu (int x);
void volumen_cono (int x);
void volumen_ortoedro (int x);
int main(){
    int x = menu (x);
    if(x == 1){
        volumen_cono(x);
    }
    if(x == 2){
        volumen_ortoedro(x);
    }
    if(x == 3){
        printf("Salir");
    }
return 0;
}
int menu (int x){
    printf("Introduzca 1,2,3 en funcion de si quiere calcular el volumen de un cono, de un ortoedro o salir:\n");
    scanf("%d",&x);
    if(x != 1 && x != 2 && x != 3){
            printf("Error\n");
            menu(x);
        }
    return x;
    
}
void volumen_cono (int x){
    int y;
    int z;
    int volcon;
    printf("Introduce un radio: \n");
    scanf("%d",&y);
    printf("Introduce una altura: \n");
    scanf("%d",&z);
    volcon = ((1/3)*3,14*(y^2)*z);
    printf("El volumen del cono es: %d \n",volcon);
}
void volumen_ortoedro (int x){
    int lado1;
    int lado2;
    int altura;
    int volort;
    printf("Introduce un lado: ");
    scanf("%d",&lado1);
    printf("Introduce el otro lado: ");
    scanf("%d",&lado2);
    printf("Introduce una altura: ");
    scanf("%d",&altura);
    volort = (lado1*lado2*altura);
    printf("El volumen del ortoedro es: %d",volort);
}
    