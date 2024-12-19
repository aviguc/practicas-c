 #include <stdio.h>
 int main (){
    int Num;
    printf("Escribe la nota numérica: "); scanf("%d", &Num); 
    switch (Num){
    case 5:
    case 6: printf("La nota es Aprobado\n");
    break; 
    case 7:
    case 8: printf("La nota es Notable\n");
    break; 
    case 9:
    case 10: printf("La nota es Sobresaliente\n");
    break; 
    default:
    printf("La nota es Suspenso\n");
    }
    return 0;
 }
