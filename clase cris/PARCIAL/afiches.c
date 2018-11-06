#include <stdio.h>
//#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "utn.h"
#include "afiches.h"
#define CABA 1
#define ZONA_SUR 2
#define ZONA_OESTE 3
#define ESTADO_COBRAR 1
#define ESTADO_COBRADA 2

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

static int afiche_getLugarLibre(Afiche* array, int len)
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
*\return Retorna 0 si esta todo bien sino en caso de error retorna -1
*/

int afiche_init(Afiche* array, int len)
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
*\brief Busca un elemento por el ID del otro dentro de un array de estructuras
*\param array Es el array que reciba para recorrer
*\param len Es el tamaño del array
*\param pantallaId Es el ID que recibe para buscar
*\return Retorna el puntero del elemento si no retorna NULL
*/

Afiche* afiche_getById(Afiche* array,int len,int IdIngresado)//te trae una afiche by pantalla en este caso le mandas el id de la pantalla(que es uno de los tantos datos que tiene la estructura pantalla),para que atraves de ese id te de una afiche es decir...
                                                                                    //es decir que te da la afiche que tiene esa pantalla que vos le mandaste
{

    for(int i = 0; i < len; i++)
    {
        if(array[i].id == IdIngresado)//pregunta si el array de afichees que vos le mandaste en el campo pantallaId es igual al id que vos le acabas de mandar de una pantalla.
        {
            return &array[i];
        }
    }
    return NULL;
}

/**
*\brief Realiza el alta de un elemento del array
*\param array Es el array que reciba para recorrer
*\param arrayPantalla Es el otro array a recorrer
*\param len es el tamaño del array
*\return Retorna 0 sino en caso de error retorna -1
*/

int afiche_alta(Afiche* array,Cliente* arrayCliente, int len,int lenCliente)//en este caso dar de alta una entidad compleja es mas dificil,porque primero necesita el id de la otra entidad en este caso el id de la pantalla para que vos puedas cargar una afiche en esa pantalla
{
    int retorno = -1;
    int indice;
    int auxNumeroZona;
    int auxNumeroEstado = 1;
    int cantidadAfiche;
    char nombreArchivo[50];
    int idIngresado;

    cliente_mostrarTodo(arrayCliente,lenCliente);

    if(utn_getNumero(&idIngresado,"Ingrese el id del cliente: ","Error,ingrese un id valido: ",0,10000,2)== -1)//le pedis el id de la pantalla la cual quiere hacer una afiche
    {
        return retorno;
    }
    if(cliente_getById(arrayCliente,lenCliente,idIngresado)!= NULL)//necesitas que te traigan la pantalla para que le puedas hacer la afiche
    {
        if( array != NULL && len > 0 )
        //si entraste aca significa que ya te dieron una pantalla por que el id que ingresaste coincidio con el de la pantalla entonces recien ahi cargas la afiche
        {
           if(!utn_getNumero(&cantidadAfiche,"Ingrese la cantidad de afiches: ","\nError reingrese el numero: ",1,10000,2)&&
              !utn_getDescription(nombreArchivo,50,"Ingrese el nombre del archivo: ","\nError reingrese el nombre",2)&&
              !utn_getNumero(&auxNumeroZona,"Ingrese la zona: 1)- CABA  2)-  ZONA SUR  3)- ZONA OESTE \n","Error reingrese un numero",1,3,2)
             )

            {
                indice = afiche_getLugarLibre(array,len);// tomas un lugar libre para cargar los datos ahi ...

                strncpy(array[indice].nombreArchivo,nombreArchivo,50);
                array[indice].cantidadAfiche = cantidadAfiche;
                array[indice].zona = auxNumeroZona;
                array[indice].estado = auxNumeroEstado;
                array[indice].isEmpty = 0;
                array[indice].id = getNextId();
                array[indice].clienteId = idIngresado;//significa que como ya tenes el id de la pantalla   agarras el id  y se lo asignas a tu pantallaid(que es de afichees)
                printf("\n");
                printf("El alta de la venta fue correcta,el ID es: %d",array[indice].id);
                printf("\n");


                retorno = 0;

            }

        }

    }
    return retorno;
}

/**
*\brief Modifica los campos de un elemento del array
*\param array Es el puntero que recibe del elemento del array
*\param arrayPantalla Es el puntero que recibe del elemento del otro array
*\param len Es el tamaño del array
*\param lenPantalla es el tamaño del arrayPantalla
*\return Retorna 0 si esta todo bien sino retorna -1
*/

int afiche_modificar(Afiche* array, int len, Cliente* arrayCliente, int lenCliente)
{
    int retorno = -1;
    int idIngresado;
    int auxNumeroZona;
    int auxCantidadAfiche;
    Afiche* aficheElegido;

    afiche_mostrar(array,len);

    //lo primero que pide es un dato del cliente que hizo la afiche en este caso el unico dato que tenemos es el cuit del cliente
    utn_getNumero(&idIngresado,"Ingrese el ID de la venta de afiche: ","\nError ingrese un ID valido: ",0,10000,2);


    afiche_getById(array,len,idIngresado);


    aficheElegido = afiche_getById(array,len,idIngresado);

    if(aficheElegido != NULL)
    {
        if(aficheElegido -> estado)
        {

            if( !utn_getNumero(&auxCantidadAfiche,"Ingrese la cantidad de afiches que desea vender: ","\nError reingrese el numero: ",1,10000,2)&&
                !utn_getNumero(&auxNumeroZona,"Ingrese la zona: 1)- CABA  2)-  ZONA SUR  3)- ZONA OESTE","Error reingrese un numero",1,3,2))
            {
                aficheElegido->cantidadAfiche = auxCantidadAfiche;
                aficheElegido->zona = auxNumeroZona;
                retorno = 0;
            }

        }

    }
        else
        {
            printf("El id del cliente no pertence al id ingresado");
        }
    return retorno;
}

/**
*\brief Modifica los campos de un elemento del array
*\param array Es el puntero que recibe del elemento del array
*\param arrayPantalla Es el puntero que recibe del elemento del otro array
*\param len Es el tamaño del array
*\param lenPantalla es el tamaño del arrayPantalla
*\return Retorna 0 si esta todo bien sino retorna -1
*/

int afiche_Cobrar(Afiche* array, int len,Cliente* arrayCliente, int lenCliente)
{
    int retorno = -1;
    int idIngresado;
    int auxNumero;
    Afiche* aficheElegido;

    afiche_mostrar(array,len);

    utn_getNumero(&idIngresado,"Ingrese el ID de la venta de afiche: ","\nError ingrese un ID valido: ",0,10000,2);

    aficheElegido = afiche_getById(array,len,idIngresado);

    cliente_mostrarById(arrayCliente,lenCliente,idIngresado);

    if(aficheElegido != NULL)
    {
        utn_getNumero(&auxNumero,"Esta seguro que quiere cambiar el estado?\n 1)-Si  2)-No: ","\nError reingrese el numero: ",1,2,2);

        if(auxNumero == 2)
        {
            printf("\nEL ESTADO SIGUE A COBRAR\n");
            return retorno;
        }
        else if(auxNumero)
        {
            aficheElegido-> estado = 0;
            printf("\nEL ESTADO ESTA COBRADO\n");
            retorno = 0;
        }

    }
    else
    {
        printf("El ID no pertence a una venta existente");
    }
    return retorno;
}



/**
*\brief Lista los datos de todos los elementos del array
*\param array Es el array que recibe para recorrer
*\param len Es el tamaño del array
*\return Retorna 0 si no retorna -1
*/

void afiche_mostrar(Afiche* array, int len)
{
     limpiarMemoria();

    for(int i = 0; i < len; i++)
    {
        if(array[i].isEmpty == 0)
        {
            printf("El ID del afiche es: %d\n",array[i].id);
            printf("El ID del cliente es: %d\n",array[i].clienteId);
            printf("El nombre del archivo de imagen del afiche es: %s\n",array[i].nombreArchivo);
            printf("La cantidad de afiches son: %d\n",array[i].cantidadAfiche);

            if(array[i].zona == 1)
            {
                printf("La zona es: CABA");
            }
            else if(array[i].zona == 2)
            {
                printf("La zona es: ZONA SUR");
            }
            else
            {
                printf("La zona es: ZONA OESTE");
            }
        }
            printf("\n\n");

            limpiarMemoria();
    }

}

int afiche_altaForzada(Afiche* arrayAfiche,int lenArrayAfiche,
                     Cliente* arrayCliente, int lenCliente,
                     int idCliente,char* nombreArchivo,int cantidadAfiche,int zona,int estado)
{
    int retorno = -1;
    int i;
    int posCliente;
    if(lenArrayAfiche > 0 && arrayAfiche != NULL)
    {
        i = afiche_getLugarLibre(arrayAfiche,lenArrayAfiche);
        if(i >= 0)
        {
            posCliente = cliente_buscarPorId(arrayCliente,lenCliente,idCliente);
            if(posCliente >= 0)
            {
                arrayAfiche[i].cantidadAfiche = cantidadAfiche;
                strcpy(arrayAfiche[i].nombreArchivo,nombreArchivo);
                arrayAfiche[i].zona = zona;
                arrayAfiche[i].estado = estado;
                //TODO
                arrayAfiche[i].clienteId = idCliente; // relacion
                arrayAfiche[i].isEmpty = 0;
                arrayAfiche[i].id = getNextId();
            }
        }
        retorno = 0;
    }
    return retorno;
}

int afiche_baja(Afiche* array, int len ,int idCliente)
{
    int retorno = -1;
    int i;
    for(i = 0; i < len; i++)
    {
        if(array[i].clienteId == idCliente)
        {
            array[i].isEmpty = 1;
            retorno = 0;
        }
    }

    return retorno;
}

int cliente_mostrarVentas(Cliente* array, int len, Afiche* arrayAfiche, int lenAfiche)
{
    int retorno = -1;
    int i;
    int j;
    int contadorDeVentas = 0;
    if(array != NULL && len > 0 && arrayAfiche != NULL && lenAfiche > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!array[i].isEmpty)
            {
                contadorDeVentas = 0;
                for(j=0;j<lenAfiche; j++)
                {
                    if(afiche_getById(&arrayAfiche[j], 1, array[i].id)!= NULL &&
                        arrayAfiche[j].estado == ESTADO_COBRAR)
                    {
                        contadorDeVentas++;
                    }
                }
                printf("\n");
                printf("El ID del cliente es: %d \n",array[i].id);
                printf("El nombre del cliente es: %s \n",array[i].nombre);
                printf("El apellido del cliente es: %s \n",array[i].apellido);
                printf("El CUIT del cliente es: %s \n",array[i].cuit);
                printf("La cantidad de ventas son: %d",contadorDeVentas);
                printf("\n");
            }
        retorno = 0;
        }
    }
    return retorno;
}

