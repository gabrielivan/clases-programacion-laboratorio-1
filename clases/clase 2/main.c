#include <stdio_ext.h>
#include <stdlib.h>
#define LIMITE_ARRAY 5

int main()
{
    int numero[LIMITE_ARRAY];
    int acumulador = 0;
    int i;

    for(i=0;i<LIMITE_ARRAY;i++)
    {
        printf("\ningrese un numero ");

        while(scanf("%d",&numero[i])!= 1)
        {
            printf("error ingrese un numero ");
            __fpurge(stdin);
        }

        acumulador=acumulador+numero[i];
    }

    printf("el promedio es: %d",acumulador/LIMITE_ARRAY);

    return 0;
}

