#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "contrataciones.h"


static int generateID();
static int contratacion_buscarIndiceLibre(Contratacion array[],int size);

static int generateID()
{
    static int id = 0;
    id++;
    return id;
}

static int contratacion_buscarIndiceLibre(Contratacion array[],int size)
{
    int retorno = 1;
    int i;

    for(i=0;i < size; i++)
    {
        if(array[i].isEmpty == 1)
        {
            retorno = i;
            break;
        }

    }
    return retorno;
}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int contratacion_init(Contratacion array[],int size,int valor)
{
    int i;
    int retorno = -1;
    if(array != NULL && size > 0 && valor >= 0)
    {
        retorno = 0;
        for(i=0;i < size; i++)
        {
        array[i].isEmpty = valor;
        }
    }
    return retorno;
}

Contratacion* contratacion_getByID(Contratacion array[],int size,int id)
{
    Contratacion* retorno = NULL;
    int i;

    if(array != NULL && size > 0)
    {
        for(i=0;i<size;i++)
        {
           if(array[i].id == id)
            {
            retorno = &array[i];
            break;
            }
        }
    }
    return retorno;
}

int contratacion_IDproducto(Contratacion array[],int size)
{
    int retorno = -1;
    int i;
    int auxID;

    input_ScanInt("\nINGRESE ID: ",&auxID);//SE PIDE ID A BUSCAR
    printf("\nID ingresado %d", auxID);

    for(i=0;i < size; i++)
    {
        if(array[i].idPantalla == auxID)//SE COMPARA ID A BUSCAR CONTRA TODO EL ARRAY
        {
            retorno = i;//SE PASA EL INDICE DEL ID BUSCADO
            break;
        }

    }
    return retorno;
}

int contratacion_alta(Contratacion array[],int size,int idSeleccionado)
{
    char auxCuit[100];
    char auxNombreVideo[500];
    int auxDias;
    int retorno = -1;
    int indice;

    indice = contratacion_buscarIndiceLibre(array,size);

    if(array->isEmpty == 1)
    {
        if( !input_getCuit(auxCuit,50,"\n Ingrese el CUIT: ","\n Error,Dato invalido.")&&
            !input_getLetras(auxNombreVideo,100,"\n Ingrese la descripcion: ","\n Error,Dato invalido.")&&
            !input_getNumeros(&auxDias,100,"\n Ingrese dias: ","\n Error,Dato invalido.",0,100))
        {

            strncpy(array[indice].cuit,auxCuit,50);
            strncpy(array[indice].nombreVideo,auxNombreVideo,100);
            array[indice].dias = auxDias;
            array[indice].isEmpty = 0;
            array[indice].id = generateID();//SE PASA ID ASIGNADO A LA ESTRUCTURA
            array[indice].idPantalla = idSeleccionado;
            retorno = 0;
        }
    }
    return retorno;
}

int contratacion_modificar(Contratacion array[],int size)
{
    int auxDias;
    int retorno = -1;

    if(array != NULL)
    {
        if( !input_getNumeros(&auxDias,100,"\n Ingrese dias: ","\n Error,Dato invalido.",0,100))
        {
            array->dias = auxDias;
            retorno = 0;
        }
    }
    else
    {
        printf("\nCasillero vacio");
    }
    return retorno;
}

int contratacion_eliminar(Contratacion array[],int size)
{
    int retorno = -1;

    if(array != NULL)
    {
            array->isEmpty = 1;
            retorno = 0;
    }
    else
    {
        printf("\nCasillero vacio");
    }
    return retorno;
}

int contratacion_mostrar(Contratacion array[],int size)
{
    int retorno = -1;
    int i;
    int j;
    char auxCuit[100];

    if(array != NULL && size > 0 )
    {
        for(i=0;i<size;i++)
        {
             for(j=i+1;j<size;j++)
             {
                if(array[j].cuit != array[i].cuit || i == size-1)
                {
                    strncpy(auxCuit,array[i].cuit,100);
                }

             }
             printf("\n\nCUIT -- %s",auxCuit);
        }

        retorno = 0;
    }
    return retorno;
}


int contratacion_ordenarId(Contratacion array[],int size)
{
    int retorno = -1;
    int i;
    int j;
    Contratacion auxiliar;

    if(array != NULL && size > 0)
    {
        retorno = 0;

        for(i=0;i<size;i++)
        {
            j = i+1;

            if(array[i].cuit > array[j].cuit)
            {
                auxiliar = array[i];
                array[i] = array[j];
                array[j] = auxiliar;
            }
        }

    }
    return retorno;
}


int contratacion_listar(Contratacion array[],int size,char nombrePantalla[])
{
    int retorno = -1;

    if(array != NULL && array->isEmpty == 0)
    {
        printf("\n\nCLIENTE Nº -- %d",array->id);
        printf("\nCUIT -- %s",array->cuit);
        printf("\nNOMBRE DE VIDEO -- %s",array->nombreVideo);
        printf("\nCANTIDAD DE DIAS-- %d",array->dias);
        printf("\nNOMBRE PANTALLA-- %s",nombrePantalla);

        retorno = 0;
    }
    return retorno;
}

int contratacion_ingresoForzado(Contratacion* array,int size,char* cuit,char* nombreVideo,int dias,int idPantalla)
{
    int indice;
    indice = contratacion_buscarIndiceLibre(array,size);
    strncpy(array[indice].cuit,cuit,100);
    strncpy(array[indice].nombreVideo,nombreVideo,100);
    array[indice].dias=dias;
    array[indice].id=generateID();
    array[indice].idPantalla = idPantalla;
    array[indice].isEmpty=0;

    return 0;
}
