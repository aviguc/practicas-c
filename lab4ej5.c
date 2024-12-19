#include <stdio.h>
void imprime_pares_intervalo (int x, int y);
int main(){
    int x,y;
    do{
        printf("Introduce un numero: \n");
        scanf("%d",&x);
        printf("Introduce otro numero: \n");
        scanf("%d",&y);
    if(x>=y){
        printf("Error");
        }
    }while(x>=y);
        imprime_pares_intervalo(x,y);
return 0;
}
void imprime_pares_intervalo (int x, int y){
    int i;
    for (int i = y; i >= x; i--) {
        if (i % 2 == 0) {
            printf("%d ", i);
        }
    }
}


    
    
  