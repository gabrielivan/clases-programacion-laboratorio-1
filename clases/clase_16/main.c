#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#define CLIENTES 100

int main()
{
    Cliente* aux;
    Cliente* arrayClientes[CLIENTES];
    char nombreAux[64];
    int indexVacio;

    cliente_inicializarArray(arrayClientes,CLIENTES);
    //ALTA
    aux = cliente_newCliente();
    indexVacio = cliente_buscarLugarVacio(arrayClientes,CLIENTES);
    if(aux != NULL && indexVacio >=0)
    {
        cliente_setNombre(aux,"Juan");
        arrayClientes[indexVacio] = aux;

        cliente_getNombre(aux,nombreAux);
        printf("%s",nombreAux);
    }


    return 0;
}
