#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "afiches.h"

/**
*\brief Genera automáticamente un ID único
*\param void
*\return Retorna el número de ID
*/

static int getNextId()
{
    static int ultimoId=-1;
    ultimoId++;
    return ultimoId;
}

/**
*\brief Busca el indice libre en un array
*\param array Es el array que reciba para recorrer
*\param len Es el tamaño del array
*\return Retorna el indice del lugar libre si no retorna -1
*/

static int cliente_getLugarLibre(Cliente* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            if(array[i].isEmpty)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

/**
*\brief Inicializa todos los elementos de un array con un valor de vacio
*\param array Es el array que reciba para recorrer
*\param len Es el tamaño del array
*\return Retorna 0 si esta todo bien sino en caso de error retorna -1
*/

int cliente_init(Cliente* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            array[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}

/**
*\brief Busca un elemento por ID dentro de un array de estructuras
*\param array Es el array que reciba para recorrer
*\param len Es el tamaño del array
*\param id Es el ID que recibe para buscar
*\return Retorna el puntero del elemento si no retorna NULL
*/

Cliente* cliente_getById(Cliente* array, int len,int id)
{
    Cliente* retorno = NULL;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            if(!array[i].isEmpty && array[i].id == id)//pregunta si en el array de pantallas que vos le mandaste no esta en empty y el id es igual al id que le mandaron.
            {
                retorno = &array[i];//te retorna la pantalla entera.
                break;
            }
        }
    }
    return retorno;
}


/**
*\brief Realiza el alta de un elemento del array
*\param array Es el array que reciba para recorrer
*\param len Es el tamaño del array
*\return Retorna 0 sino en caso de error retorna -1
*/

int cliente_alta(Cliente* array, int len)
{
    int retorno = -1;
    int indice;

    char nombre[50];
    char apellido[50];
    char cuit[14];

    indice = cliente_getLugarLibre(array,len);

    if( array != NULL && len > 0 &&
            indice >= 0 && indice < len
            && array[indice].isEmpty)
    {
        if( !utn_getNombre(nombre,50,"Nombre del cliente: ","\nError,nombre invalido.\n",2) &&
                !utn_getNombre(apellido,50,"Apellido del cliente: ","\nError,apellido invalido.",2)&&
                !utn_getCuit(cuit,"Ingrese el cuit del cliente: ","Error cuit invalido: ",2))
        {
            strncpy(array[indice].nombre,nombre,50);
            strncpy(array[indice].apellido,apellido,50);
            strncpy(array[indice].cuit,cuit,14);
            array[indice].isEmpty = 0;
            array[indice].id = getNextId();
            printf("\n");
            printf("El alta del cliente fue correcta,su ID es: %d \n",array[indice].id);
            retorno = 0;
        }
    }
    return retorno;
}

/**
*\brief Modifica los campos de un elemento del array
*\param array Es el puntero que recibe del elemento del array
*\param len Es el tamaño del array
*\return Retorna 0 si esta todo bien sino retorna -1
*/

int cliente_modificar(Cliente* array, int len)
{
    Cliente* cliente;
    char auxNombre[50];
    char auxApellido[50];
    char auxCuit[14];
    int idIngresado;
    int retorno = -1;

    cliente_mostrarTodo(array,len);

    if(utn_getNumero(&idIngresado,"Ingrese el ID del cliente: ","\nError ingrese un ID valido!",0,10000,2) == -1)
    {
        return retorno;
    }
    cliente = cliente_getById(array,len,idIngresado);
    if(cliente != NULL)
    {
        if(array != NULL && len > 0 &&
                !cliente->isEmpty)
        {
            if(!utn_getNombre(auxNombre,50,"\nIngrese el nuevo nombre: ","\nError,nombre invalido.",2)&&
                    !utn_getNombre(auxApellido,50,"\nIngrese el nuevo apellido: ","\nError,apellido invalido",2)&&
                    !utn_getCuit(auxCuit,"\nIngrese el nuevo Cuit: ","\nError,Cuit invalido.",2))
            {
                strncpy(cliente->nombre,auxNombre,50);
                strncpy(cliente->apellido,auxApellido,50);
                strncpy(cliente->cuit,auxCuit,14);

                retorno = 0;
            }

        }
    }
    return retorno;
}

/**
*\brief Modifica los campos de un elemento del array
*\param array Es el puntero que recibe del elemento del array
*\param len Es el tamaño del array
*\return Retorna 0 si no retorna -1
*/

int cliente_baja(Cliente* array, int len, int* idCliente)
{
    Cliente* cliente;
    int retorno = -1;
    *idCliente = -1;
    int idIngresado;
    int auxNumero;

    cliente_mostrarTodo(array,len);

    if(utn_getNumero(&idIngresado,"Ingrese el ID del cliente a borrar: ","\nError,ingrese un ID valido: ",0,10000,2) == -1)
    {
        return retorno;
    }

    cliente = cliente_getById(array,len,idIngresado);
    if(cliente != NULL)
    {
        *idCliente = cliente->id;
        if(array != NULL && len > 0 &&
                cliente->isEmpty == 0)
        {
            utn_getNumero(&auxNumero,"Esta seguro que quiere dar de baja a este cliente?\n 1)-Si  2)-no: ","\nError reingrese el numero: ",1,2,2);

            if(auxNumero == 1)
            {
                cliente->isEmpty = 1;
                retorno = 0;
            }

            else if(auxNumero == 2)
            {
                return -1;
            }

        }
        else
        {
            printf("\nNo hay pantalla.");
        }
    }
    return retorno;
}

/**
*\brief Lista los datos de todos los elementos del array
*\param array Es el array que recibe para recorrer
*\param len Es el tamaño del array
*\return Retorna 0 si no retorna -1
*/

void cliente_mostrarTodo(Cliente* array, int len)
{
    for(int i = 0; i < len; i++)
    {
        if(array[i].isEmpty == 0)
        {
            printf("El ID del cliente es: %d\n",array[i].id);
            printf("El Nombre del Cliente es: %s\n",array[i].nombre);
            printf("El Apellido del Cliente es: %s\n",array[i].apellido);
            printf("El Cuit del Cliente es: %s\n",array[i].cuit);
            printf("\n\n");
        }
        limpiarMemoria();
    }
}

int cliente_altaForzada(Cliente* array,int len,char* nombre,char* apellido, char* cuit)
{
    int retorno = -1;
    int i;

    if(len > 0 && array != NULL)
    {
        i = cliente_getLugarLibre(array,len);
        if(i >= 0)
        {
            retorno = 0;
            strcpy(array[i].nombre,nombre);
            strcpy(array[i].apellido,apellido);
            strncpy(array[i].cuit,cuit,14);
            //------------------------------
            //------------------------------
            array[i].id = getNextId();
            array[i].isEmpty = 0;
        }
        retorno = 0;
    }
    return retorno;
}

int cliente_buscarPorId(Cliente* array,int len, int id)
{
    int retorno = -1;
    int i;
    if(len > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0; i<len; i++)
        {
            if(!array[i].isEmpty && array[i].id == id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

void cliente_ordenarId(Cliente* array,int len)
{
    int i;
    int j;
    Cliente auxiliar;

    if(array != NULL && len > 0)
    {
        for(i=0; i<len; i++)
        {
            j= i++;

            if(array[i].id > array[j].id)
            {
                auxiliar = array[i];
                array[i] = array[j];
                array[j] = auxiliar;
            }
        }

    }

}

void cliente_mostrarById(Cliente* array, int len,int id)
{
    int i;
    if(array != NULL && len > 0)
    {
        limpiarMemoria();
        for(i=0; i<len; i++)
        {
            if(!array[i].isEmpty && array[i].id == id)
            {
                printf("\n");
                printf("El ID del cliente es: %d \n",array[i].id);
                printf("El nombre del cliente es: %s \n",array[i].nombre);
                printf("El apellido del cliente es: %s \n",array[i].apellido);
                printf("El CUIT del cliente es: %s \n",array[i].cuit);
                printf("\n");
            }
            limpiarMemoria();
        }
    }
}

