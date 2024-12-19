#include <stdio.h>
void imprime_pares(int n1, int n2)
{
    for(n2;n2>=n1;n2--)
    {
        if(n2%2==0)
        {
            printf("%d ", n2);
        }
    }
} 
int main()
{
    int n1,n2;
    printf("Dime dos números: \n");
    scanf("%i %i",&n1,&n2);
    while(n1>n2 || n1<0 || n2<0)
    {
        printf("Dime otros números, estos no valen, error\n");
        scanf("%i %i",&n1,&n2);
    }
    imprime_pares(n1,n2);
}

