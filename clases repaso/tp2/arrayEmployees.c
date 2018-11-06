#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "arrayEmployees.h"
#include "utn.h"
#define CANTIDAD_EMPLEADOS 1000

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

static int getLugarLibre(Empleado* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
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
*\return Retorna 0 sino retorna -1
*/

int empleado_init(Empleado* array, int len)
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
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

Empleado* empleado_getById(Empleado* array, int len,int id)
{
    Empleado* retorno = NULL;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty && array[i].id == id)
            {
                retorno = &array[i];
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
*\return Retorna 0 sino retorna -1
*/

int empleado_alta(Empleado* array, int len)
{
    int retorno = -1;
    int indice;

    char nombre[51];
    char apellido[51];
    float salario;
    int sector;

    indice = getLugarLibre(array,len);

    if( array != NULL && len > 0 &&
        indice >= 0 && indice < len
        && array[indice].isEmpty)
    {
        if( !utn_getNombre(nombre,51,"Ingrese su nombre: ","Error, ingrese un nombre valido: ",2) &&
            !utn_getNombre(apellido,51,"Ingrese su apellido: ","Error,ingrese un apellido valido: ",2) &&
            !utn_getNumeroConComa(&salario,"ingrese el salario del empleado: ","Error reingrese el salario: ",0,99999,2)&&
            !utn_getNumero(&sector,"Ingrese el sector: ","Error,ingrese un sector valido: ",0,1000,2))
        {
            strncpy(array[indice].nombre,nombre,51);
            strncpy(array[indice].apellido,apellido,51);
            array[indice].salario = salario;
            array[indice].sector = sector;
            array[indice].isEmpty = 0;
            array[indice].id = getNextId();
            retorno = 0;
        }
    }
    return retorno;
}

/**
*\brief Modifica los campos de un elemento del array
*\param array Es el puntero que recibe del elemento del array
*\param len Es el tamaño del array
*\return Retorna 0 sino retorna -1
*/

int empleado_modificar(Empleado* array, int len)
{
    Empleado* empleado;
    char auxNombre[51];
    char auxApellido[51];
    float auxSalario;
    int auxSector;
    int idIngresado;
    int opcion = 0;
    int retorno = -1;

    if(utn_getNumero(&idIngresado,"Ingrese el ID del empleado a modificar: ","Error ingrese un ID valido: ",0,10000,2) == -1)
    {
        return retorno;
    }

    empleado = empleado_getById(array,len,idIngresado);

    if(empleado != NULL)
    {
        if(array != NULL && len > 0 &&
           !empleado->isEmpty)
        {

            utn_getNumero(&opcion,"Ingrese una opcion:\n \n1- MODIFICAR NOMBRE  \n2- MODIFICAR APELLIDO  \n3- MODIFICAR SALARIO  \n4- MODIFICAR SECTOR\n",
                          "Error,ingrese una opcion valida: ",1,4,2);
            switch(opcion)
            {
                case 1:
                    if( !utn_getNombre(auxNombre,51,"Ingrese el nuevo nombre: ","\nError,ingrese un nombre valido.",2))
                    {
                        strncpy(empleado->nombre,auxNombre,51);
                    }
                    break;

                case 2:
                    if( !utn_getNombre(auxApellido,51,"Ingrese el nuevo apellido: ","\nError,ingrese un apellido valido: ",2))
                    {
                        strncpy(empleado->apellido,auxApellido,51);
                    }
                    break;

                case 3:
                    if( !utn_getNumeroConComa(&auxSalario,"Ingrese el nuevo salario: ","\nError ingrese un salario valido",0,99999,2))
                    {
                        empleado->salario = auxSalario;
                    }
                    break;

                case 4:
                    if( !utn_getNumero(&auxSector,"Ingrese el nuevo sector: ","\n Error,precio invalido: ",0,10000,2))
                    {
                        empleado->sector = auxSector;
                    }
                    break;

             }

             retorno = 0;
        }
    }
    return retorno;
}


/**
*\brief Modifica los campos de un elemento del array
*\param array Es el puntero que recibe del elemento del array
*\param len Es el tamaño del array
*\return Retorna 0 sino retorna -1
*/

int empleado_baja(Empleado* array, int len)
{
    Empleado* empleado;
    int retorno = -1;
    int idIngresado;

  if(utn_getNumero(&idIngresado,"Ingrese el ID del empleado a borrar: ","Error ingrese un ID valido: ",0,10000,2) == -1)
    {
        return retorno;
    }
    empleado = empleado_getById(array,len,idIngresado);
    if(empleado != NULL)
    {
        if(array != NULL && len > 0 &&
            empleado->isEmpty == 0)
        {
            empleado->isEmpty = 1;
            retorno = 0;
        }
        else
        {
            printf("No hay empleado.");
        }
    }
    return retorno;
}


/**
*\brief Muestra los datos de un elemento del array
*\param array Es el puntero que recibe del elemento del array
*\param len Es el tamaño del array
*\return Retorna 0 sino retorna -1
*/

int empleado_mostrar(Empleado* array,int len)
{
    int retorno = -1;
    int i;

    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty)
            {
                printf("\n El nombre del empleado es: %s",array->nombre);
                printf("\n El apellido del empleado es: %s",array->apellido);
                printf("\n El salario del empleado es: %.2f",array->salario);
                printf("\n El sector del empleado es: %d",array->sector);
                printf("\n\n");

            }
        }

        retorno = 0;
    }
    //fflush(stdin);
    __fpurge(stdin);
    return retorno;
}

/**
*\brief Ordena todos los elementos de un array
*\param array Es el array que recibe para ordenar
*\param len Es el tamaño del array
*\return void
*/


void empleado_ordenarPorApellido(Empleado* array, int len)
{
	int i,j;
	Empleado empleadoAux;
	for(i = 0; i < len - 1; i++)
	{
        for(j = i + 1; j < len; j++)
        {
            if(strcmp(array[i].apellido,array[j].apellido)> 0)
            {
                empleadoAux = array[i];
                array[i] = array[j];
                array[j] = empleadoAux;
            }

            else if (!(strcmp(array[i].apellido,array[j].apellido)) && array[i].sector > array[j].sector)
            {
                empleadoAux = array[i];
                array[i] = array[j];
                array[j] = empleadoAux;
            }

		 }
	 }
}

/**
*\brief Ordena todos los elementos de un array
*\param array Es el array que recibe para ordenar
*\param len Es el tamaño del array
*\return void
*/


void empleado_ordenarPorSector(Empleado* array, int len)
{
	int i,j;
	Empleado empleadoAux;
	for(i = 0; i < len - 1; i++)
	{
        for(j = i + 1; j < len; j++)
        {
            if((array[i].sector > array[j].sector))
            {
                empleadoAux = array[i];
                array[i] = array[j];
                array[j] = empleadoAux;
            }

		}
	}
}

/**
*\brief Lista los datos de todos los elementos del array
*\param array Es el array que recibe para recorrer
*\param len Es el tamaño del array
*\return Retorna 0 sino retorna -1
*/

int empleado_listar(Empleado* array,int len)
{
    int retorno = -1;
    int i;

    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty)
            {
                printf("\n El nombre del empleado es: %s",array[i].nombre);
                printf("\n El apellido del empleado es: %s",array[i].apellido);
                printf("\n El salario del empleado es: %.2f",array[i].salario);
                printf("\n El sector del empleado es: %d",array[i].sector);
                printf("\n El ID del empleado es: %d",array[i].id);
                printf("\n\n");

            }
        }

        retorno = 0;
    }
    //fflush(stdin);
    __fpurge(stdin);
    return retorno;
}

