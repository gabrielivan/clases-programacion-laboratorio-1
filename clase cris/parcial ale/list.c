#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


/**
* \brief Mostrar los datos ingresados en un array de enteros
* \param pArray Es el array que recibe para mostrar
* \param pIndice Es puntero del indice del array que recibe para mostrar
* \param pSize Es el puntero del tamaño del array
* \param pMensaje Es el puntero del mensaje a mostrar al usuario
* \return Retorna void
*/

void array_mostrarInt(int* pArray,int indice,int size,char* pMensaje)
{
    printf(pMensaje);
    for(indice = 0 ; indice < size ; indice++ )
    {
        printf("  %d    -   %d \n",indice,pArray[indice]);//Se muestra el INDICE y luego el VALOR guardado en ese INDICE del ARRAY
    }
}
