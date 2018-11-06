#include <stdio.h>
#include <stdlib.h>

int main()
{

    int numeroUno;
    int numeroDos;
    int numeroTres;
    int numeroMaximo;
    int numeroMinimo;

    printf("ingrese un numero");
    scanf("%d",&numeroUno);

    numeroMaximo = numeroUno;
    numeroMinimo = numeroUno;

    printf("ingrese un numero");
    scanf("%d",&numeroDos);

    if(numeroDos>numeroMaximo)
    {
        numeroMaximo = numeroDos;
    }
    if(numeroDos<numeroMinimo)
    {
        numeroMinimo = numeroDos;
    }

    printf("ingrese un numero");
    scanf("%d",&numeroTres);

    if(numeroTres > numeroMaximo)
    {
        numeroMaximo = numeroTres;
    }
    if(numeroTres<numeroMinimo)
    {
        numeroMinimo = numeroTres;
    }
    printf("el numero maximo es : %d",numeroMaximo);
    printf("el numero minimo es : %d",numeroMinimo);

    if(numeroUno>numeroMinimo && numeroUno<numeroMaximo)

    {
        printf("el numero del medio es : %d",numeroUno);
    }
    else if(numeroDos>numeroMinimo && numeroDos<numeroMaximo)
    {
        printf("el numero del medio es : %d",numeroDos);
    }
    else if (numeroTres>numeroMinimo && numeroTres<numeroMaximo)
    {
        printf("el numero del medio es : %d",numeroTres);
    }
    return 0;
}


