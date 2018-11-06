//#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include "../utnLib/utn.h"


int main()
{
    float numero;
    if(utn_getNumeroConComa(&numero,"numero?","fuera de rango",10.5,20.5,3)==0)
    {
        printf("EL numero ES %f",numero);
    }
    return 0;
}






