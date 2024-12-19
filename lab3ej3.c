#include <stdio.h>
int main(){
    float n;
    float y;
    float z;
    float lado1;
    float lado2;
    float altura;
    float cono=1;
    float ortoedro=1;
    printf("Menú:  \n1.  Cono\n2.  Ortoedro:  \nDi opción:  ");
    scanf("%d",&n);
    if(n!=1 && n!=2){
        printf("\nEl volumen no se puede calcular. La opción tiene que ser 1 ó 2.\n");
    }
    else{
        if(n == 1)
        {
            printf("Introduce un radio: \n");
            scanf("%d",&y);
            printf("Introduce una altura: \n");
            scanf("%d",&z);
            cono = ((1/3)*3,14*(y*y)*z);
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
            printf("\nEl volumen del ortoedro es: %.2f\n",  ortoedro);

        }
    
    }
return 0;
}