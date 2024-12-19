#include <stdio.h>
void menu(int x);
int main(){
    int n;
    int y;
    int z;
    int lado1;
    int lado2;
    int altura;
    int cono=1;
    int ortoedro=1;
    
    printf("Menú:\n1. Cono\n2. Ortoedro: 3: Salir\nDi opción: ");
    scanf("%d",&n);
    menu(n);
    return 0;
}
void menu(int n){
    int y;
    int z;
    int lado1;
    int lado2;
    int altura;
    int cono=1;
    int ortoedro=1;
    if(n!=1 && n!=2 && n!=3){
        scanf("%d",&n);
        menu(n);
    }
    if(n == 1)
    {
            printf("Introduce un radio: \n");
            scanf("%d",&y);
            printf("Introduce una altura: \n");
            scanf("%d",&z);
            cono = ((1/3)*3,14*(y^2)*z);
            printf("\nEl volumen del cono es %.2f\n", cono);
    }
    if(n == 2){
            printf("Introduce un lado: ");
            scanf("%d",&lado1);
            printf("Introduce el otro lado: ");
            scanf("%d",&lado2);
            printf("Introduce una altura: ");
            scanf("%d",&altura);
            ortoedro = (lado1*lado2*altura);
            printf("\nEl volumen del ortoedro es: %.2f\n", ortoedro);

    }
    if(n == 3){
            printf("Salir");

    }
    
}
