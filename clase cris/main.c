#include <stdio.h>
#include <stdlib.h>
#include "../clases/arrayLib/array.h"
#include "../clases/utnLib/utn.h"

int main()
{
    int numero;
    int resultado = utn_getNumero(&numero,"Ingrese un numero del 1 al 5","Error, reingrese",1,5,3);
    if(resultado == 0)
    {
        printf("El numero ingresado es %d", numero);
    }
    else
    {
        printf("Se agotaron los intentos");

    }
    return 0;
}
