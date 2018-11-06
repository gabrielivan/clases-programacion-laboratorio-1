//#include <stdio_ext.h>
#include <stdio.h>
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
    float auxPrecio;
    int retorno = -1;

    if(arrayProducto[indice].isEmpty == 1)
    {
        if( !utn_getNombre(auxNombre,50,"\n Ingrese el nombre del producto: ","\n Error,nombre invalido.",2)&&
            !utn_getDescription(auxDescripcion,100,"\n Ingrese la descripcion: ","\n Error,descripcion invalida.",2)&&
            !utn_getNumeroConComa(&auxPrecio,"\n Ingrese el precio: ","\n Error,precio invalido.",0,10000,2))
        {
            strncpy(arrayProducto[indice].nombre,auxNombre,50);
            strncpy(arrayProducto[indice].descripcion,auxDescripcion,100);
            arrayProducto[indice].precio = auxPrecio;
            arrayProducto[indice].isEmpty = 0;
            if(indice > 0)
            {
                arrayProducto[indice].id =  (arrayProducto[indice - 1].id) + 1;
            }
            else
            {
                arrayProducto[indice].id =  1;
            }

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
        printf("\n El ID del producto es: %d",arrayProducto[indice].id);
        printf("\n El nombre del producto es: %s",arrayProducto[indice].nombre);
        printf("\n La descripcion del producto es: %s",arrayProducto[indice].descripcion);
        printf("\n El precio del producto es: %.2f",arrayProducto[indice].precio);
        printf("\n\n");

        retorno = 0;
    }
    fflush(stdin);
    return retorno;
}

void producto_mostrarArrayCompleto(Producto arrayProducto[],int size)
{
    for(int i  = 0; i < size; i++)
    {
        if(!arrayProducto[i].isEmpty)
        {
            producto_mostrarArray(arrayProducto,i,size);
        }
    }
}

int producto_buscarIndiceArray(Producto arrayProducto[],int size)
{
    int i;

    for(i=0;i < size; i++)
    {
        if(arrayProducto[i].isEmpty == 1)
        {
            return i;
        }

    }
    return -1;
}

int producto_buscarIndiceArrayById(Producto arrayProducto[],int id, int size)
{
    int i;
    for(i=0;i < size; i++)
    {
        if(arrayProducto[i].id == id)
        {
            return i;
        }

    }
    return -1;
}


int producto_modificar(Producto arrayProducto[],int indice,int size)
{
    char auxNombre[50];
    float auxPrecio;
    int retorno = -1;

    if(arrayProducto[indice].isEmpty == 0)
    {
        if( !utn_getNombre(auxNombre,50,"\n Ingrese el nuevo nombre: ","\n Error,nombre invalido.",2)&&
            !utn_getNumeroConComa(&auxPrecio,"\n Ingrese el nuevo precio: ","\n Error,precio invalido.",0,10000,2))
        {
            strncpy(arrayProducto[indice].nombre,auxNombre,50);
            arrayProducto[indice].precio = auxPrecio;

            retorno = 0;
        }

    }
    return retorno;
}


int producto_bajaLogica(Producto arrayProducto[],int indice,int size)
{
    int retorno = -1;

    if(arrayProducto[indice].isEmpty == 0)
    {
        arrayProducto[indice].isEmpty = 1;

        retorno = 0;
    }
    else
    {
        printf("\nNo hay producto.");
    }

    return retorno;
}

void limpiarPantalla(void)
{
    //system("cls");
    system("clear");

}

void pararPantalla()
{
    printf("\ningrese una tecla para continuar...");
    getchar();
}
