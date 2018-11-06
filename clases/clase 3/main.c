#include <stdio.h>
#include <stdlib.h>

//prototipos...
int PedirEdad();
int ValidarEdad(int,int,int);

int main()
{
    int edad;
    edad = PedirEdad();
    printf("la edad ingresada es %d",edad);

}
//implementaciones...

/**
*\brief pide una edad y la valida
*\return int edad ingresada y validada
*/
int PedirEdad()
{
    int edad;
    printf("ingrese su edad\n");
    scanf("%d",&edad);
    return ValidarEdad(edad,17,65);
}

/**
*\brief valida que la edad recibida por parametro se encuentre dentro de los rangos recibidos por parametro.
*\brief si la edad no esta en rango vuelve a pedirla
*\param edad: edad a validar
*\param minimo: valor minimo que pueda tener la edad
*\param maximo: valor maximo que pueda tener la edad
*\return edad validada
*/
int ValidarEdad(int edad,int minimo,int maximo)
{
    while(edad < minimo || edad > maximo)
    {
        printf("ingrese su edad nuevamente\n");
        scanf("%d",&edad);
    }
    return edad;
}
