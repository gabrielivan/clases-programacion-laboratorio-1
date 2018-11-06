#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "producto.h"


void producto_initArrayProducto(Producto arrayProducto[],int size,int valor)
{
    int i;
    for(i=0;i < size; i++)
    {
        arrayProducto[i].isEmpty = valor;
    }

}

int producto_altaArray(Producto arrayProducto[],int indice,int size)
{
    char auxNombre[50];
    char auxDescripcion[100];
    char auxPrecio[50];
    int retorno = -1;
    int auxID;

    if(arrayProducto[indice].isEmpty == 1)
    {
        if( !string_getStringLetras(auxNombre,50,"\n Ingrese el nombre del producto: ","\n Error,nombre invalido.")&&
            !string_getStringLetras(auxDescripcion,100,"\n Ingrese la descripcion: ","\n Error,descripcion invalida.")&&
            !string_getStringFloat(auxPrecio,50,"\n Ingrese el precio: ","\n Error,precio invalido.",0,10000))
        {
            auxID = indice + 1;//SE ASIGNA ID EN BASE AL INDICE
            strncpy(arrayProducto[indice].nombre,auxNombre,50);
            strncpy(arrayProducto[indice].descripcion,auxDescripcion,100);
            arrayProducto[indice].precio = atof(auxPrecio);
            arrayProducto[indice].isEmpty = 0;
            arrayProducto[indice].ID = auxID;//SE PASA ID ASIGNADO A LA ESTRUCTURA
            retorno = 0;
        }

    }
    return retorno;
}

int producto_mostrarArray(Producto arrayProducto[],int indice,int size)
{
    int retorno = -1;

    if(arrayProducto != NULL && size > 0 && indice >= 0 && indice < size)
    {
        printf("\n\nPRODUCTO -- %s",arrayProducto[indice].nombre);
        printf("\nDESCRIPCION -- %s",arrayProducto[indice].descripcion);
        printf("\nPRECIO -- $%.2f",arrayProducto[indice].precio);
        printf("\nID -- %i",arrayProducto[indice].ID);

        retorno = 0;

    }
    return retorno;
}

int producto_buscarIndiceArray(Producto arrayProducto[],int size,int* indiceVacio)
{
    int retorno = 1;
    int i;

    for(i=0;i < size; i++)
    {
        if(arrayProducto[i].isEmpty == 1)
        {
            *indiceVacio = i;
            retorno = 0;
            break;
        }

    }
    return retorno;
}

int producto_IDproducto(Producto arrayProducto[],int size)
{
    int retorno = -1;
    int i;
    int auxID;

    auxID = input_getInt("\nINGRESE ID: ");//SE PIDE ID A BUSCAR
    printf("\nID ingresado %d", auxID);

    for(i=0;i < size; i++)
    {
        if(arrayProducto[i].ID == auxID)//SE COMPARA ID A BUSCAR CONTRA TODO EL ARRAY
        {
            retorno = i;//SE PASA EL INDICE DEL ID BUSCADO
            break;
        }

    }
    return retorno;
}

int producto_modificarProducto(Producto arrayProducto[],int size)
{
    char auxNombre[50];
    char auxDescripcion[100];
    char auxPrecio[50];
    int retorno = -1;
    int indiceModificar;

    indiceModificar = producto_IDproducto(arrayProducto,size);


    if(arrayProducto[indiceModificar].isEmpty == 0)
    {
        if( !string_getStringLetras(auxNombre,50,"\n Ingrese el nombre del producto: ","\n Error,nombre invalido.")&&
            !string_getStringLetras(auxDescripcion,100,"\n Ingrese la descripcion: ","\n Error,descripcion invalida.")&&
            !string_getStringFloat(auxPrecio,50,"\n Ingrese el precio: ","\n Error,precio invalido.",0,10000) &&
            indiceModificar >= 0)
        {
            strncpy(arrayProducto[indiceModificar].nombre,auxNombre,50);
            arrayProducto[indiceModificar].precio = atof(auxPrecio);
            retorno = 0;
        }

    }
    else
    {
        printf("\nCasillero vacio");
    }
    return retorno;
}

int producto_eliminarProducto(Producto arrayProducto[],int size)
{
    int retorno = -1;
    int indiceModificar;

    indiceModificar = producto_IDproducto(arrayProducto,size);

    if(arrayProducto[indiceModificar].isEmpty == 0)
    {
        if(indiceModificar >= 0)
        {
            arrayProducto[indiceModificar].isEmpty = 1;
            retorno = 0;
        }
    }
    else
    {
        printf("\nCasillero vacio");
    }
    return retorno;
}
