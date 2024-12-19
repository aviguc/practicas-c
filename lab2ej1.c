 #include <stdio.h>
    int main ()
    {
    int Num;
    printf("Escribe un número: "); scanf("%d", &Num);
    if (Num == 3){
        printf("Has introducido un 3\n");
    }
    else {
        printf("No has introducido un 3 sino un %d\n", Num); 
    }

 return 0;
 }