#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "venta.h"
#include "informes.h"
/**
* \brief    Se utiliza esta funcion para obtener un nuevo id
*           declarando una variable static para el id y suma 1 al anterior
* \return devuelve un id nuevo
*/
static int getNextId()
{
    static int ultimoId=-1;
    ultimoId++;
    return ultimoId;
}
/**
* \brief    Se utiliza esta funcion para obtener el primer lugar libre de un array de tipo venta
*           recorriendo el array hasta encontrar un isEmpty en 1
* \param arrayVentas Es el array que se recorre
* \param lenVentas Es el limite de ventas que puede guardar el array
* \return devuelve el indice de la posicion libre, sino el return es -1.
*/
static int getLugarLibreVenta(Venta* arrayVentas, int lenVentas)
{
    int retorno = -1;
    int i;
    if(arrayVentas != NULL && lenVentas > 0)
    {
        for(i=0;i<lenVentas;i++)
        {
            if(arrayVentas[i].isEmpty)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para inicializar un array de tipo venta,
*           recorriendo el array y poniendo cada isEmpty en 1
* \param arrayVentas Es el array que se recorre
* \param lenVentas Es el limite de ventas que puede guardar el array
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
int venta_init(Venta* arrayVentas, int lenVentas)
{
    int retorno = -1;
    int i;
    if(arrayVentas != NULL && lenVentas > 0)
    {
        for(i=0;i<lenVentas;i++)
        {
            arrayVentas[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para encontrar un venta a través de un id,
*           recorriendo el array y comparando los id (donde el isEmpty es 0)
* \param arrayVentas Es el array que se recorre
* \param lenVentas Es el limite de ventas que puede guardar el array
* \param id Es el id con que se compara cada id del array
* \return   retorna la direccion de la struct del venta donde se encontro el id,
*           si no el retorno es NULL.
*/
Venta* venta_getById(Venta* arrayVentas, int lenVentas, int id)
{
    Venta* retorno = NULL;
    int i;
    if(arrayVentas != NULL && lenVentas > 0)
    {
        for(i=0;i<lenVentas;i++)
        {
            if(!arrayVentas[i].isEmpty && arrayVentas[i].idVenta == id)
            {
                retorno = &arrayVentas[i];
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para encontrar un venta a través de un id de cliente,
*           recorriendo el array y comparando los id (donde el isEmpty es 0)
* \param arrayVentas Es el array que se recorre
* \param lenVentas Es el limite de ventas que puede guardar el array
* \param idCliente Es el id con que se compara cada idCliente del array
* \return   retorna la direccion de la struct del venta donde se encontro el id,
*           si no el retorno es NULL.
*/
Venta* venta_getByIdCliente(Venta* arrayVentas, int lenVentas, int idCliente)
{
    Venta* retorno = NULL;
    int i;
    if(arrayVentas != NULL && lenVentas > 0)
    {
        for(i=0;i<lenVentas;i++)
        {
            if(!arrayVentas[i].isEmpty && arrayVentas[i].idCliente == idCliente)
            {
                retorno = &arrayVentas[i];
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para encontrar un venta a través de un id de cliente, que
*           pertenezca a la zona indicada recorriendo el array y comparando los id (donde el isEmpty es 0)
* \param arrayVentas Es el array que se recorre
* \param lenVentas Es el limite de ventas que puede guardar el array
* \param idCliente Es el id con que se compara cada idCliente del array
* \param zona Es la zona con que se compara cada zona del array venta
* \return   retorna la direccion de la struct del venta donde se encontro el id y la zona,
*           si no el retorno es NULL.
*/
Venta* venta_getByIdClienteAndZona(Venta* arrayVentas, int lenVentas, int idCliente, int zona)
{
    Venta* retorno = NULL;
    int i;
    if(arrayVentas != NULL && lenVentas > 0 && zona > 0 && zona <=3)
    {
        for(i=0;i<lenVentas;i++)
        {
            if(!arrayVentas[i].isEmpty && arrayVentas[i].idCliente == idCliente && arrayVentas[i].zona == zona)
            {
                retorno = &arrayVentas[i];
                break;
            }
        }
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para dar de alta una venta generando un id
*           de manera automatica, poniendo el estado en a cobrar y el usuario introduce el resto de datos,
*           se verifica que el idCliente sea existente y
*           si se realiza todo correctamente se guardan los datos y se coloca el isEmpty en 0
* \param arrayVentas Es el array que se recorre
* \param lenVentas Es el limite de ventas que puede guardar el array
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
int venta_alta(Venta* arrayVentas, int lenVentas, void* arrayClientesVoid, int lenClientes)
{
    int retorno = -1;
    Cliente* arrayClientes = arrayClientesVoid;
    int indice;
    int idCliente;
    int cantidadAfiches;
    char archivoImagen[51];
    int zona;
    cliente_mostrar(arrayClientes, lenClientes);
    indice = getLugarLibreVenta(arrayVentas,lenVentas);
    if( arrayVentas != NULL && lenVentas > 0 &&
        arrayClientes != NULL && lenClientes > 0 && indice >= 0 &&
        indice < lenVentas && arrayVentas[indice].isEmpty &&
        !utn_getEnteroSoloNumeros(&idCliente, 10, "ID cliente?\n", "ID no valido\n", 2) &&
        cliente_getById(arrayClientes, lenClientes, idCliente) != NULL &&
        !utn_getEnteroSoloNumeros(&cantidadAfiches, 10,"cantidad afiches?\n", "cantidad no valida\n",2) &&
        cantidadAfiches != 0 &&
        !utn_getArchivo(archivoImagen, 51, "Nombre Archivo?\n", "archivo No Valido (nombre.ext)\n", 2) &&
        !utn_getEnteroSoloNumeros(&zona, 10, "Ingrese zona\n1-CABA\n2-Zona Sur\n3-Zona Oeste\n", "zona no valida\n", 2) &&
        zona > 0 && zona <=3)
    {
        arrayVentas[indice].idCliente = idCliente;
        arrayVentas[indice].cantidadAfiches = cantidadAfiches;
        strncpy(arrayVentas[indice].archivoImagen, archivoImagen, 51);
        arrayVentas[indice].zona = zona;
        arrayVentas[indice].estado = 1;
        arrayVentas[indice].isEmpty = 0;
        arrayVentas[indice].idVenta = getNextId();
        printf("Alta venta ID %d realizada\n", arrayVentas[indice].idVenta);
        retorno = 0;
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para modificar la zona y la cantidad de afiches de una venta,
*           el usuario elige a traves de un id e introduce todos los datos por teclado
* \param arrayVentas Es el array que se recorre
* \param lenVentas Es el limite de ventas que puede guardar el array
* \param reintentos Veces que el usuario podra volver a introducir el id
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
int venta_modificar(Venta* arrayVentas, int lenVentas, int reintentos)
{
    int retorno = -1;
    Venta *ventaModificado = NULL;
    int id;
    int i;
    int cantidadAfiches;
    int zona;
    if(arrayVentas != NULL && lenVentas > 0 && reintentos >= 0)
    {
        venta_mostrar(arrayVentas, lenVentas);
        for(i=0; i <= reintentos; i++)
        {
            if( !utn_getEntero(&id, lenVentas, "Introduzca el Id de venta que desea modificar\n", "", 0) &&
                venta_getById(arrayVentas, lenVentas, id) != NULL)
            {
                ventaModificado = venta_getById(arrayVentas, lenVentas, id);
                break;
            }
            else
            {
                printf("Id Erroneo\n");
            }
        }
    }
    if( ventaModificado != NULL &&
        !utn_getEnteroSoloNumeros(&cantidadAfiches, 10,"cantidad afiches?\n", "cantidad no valida\n",2) &&
        cantidadAfiches != 0 &&
        !utn_getEnteroSoloNumeros(&zona, 10, "Ingrese zona\n1-CABA\n2-Zona Sur\n3-Zona Oeste\n", "zona no valida\n", 2) &&
        zona > 0 && zona <=3)
    {
        ventaModificado->cantidadAfiches = cantidadAfiches;
        ventaModificado->zona = zona;
        retorno = 0;
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para dar de baja (baja logica) una venta
* \param arrayVentas Es el array que se recorre
* \param lenVentas Es el limite de ventas que puede guardar el array
* \param reintentos Veces que el usuario podra volver a introducir el id
* \return El retorno es 0 si se realizo de manera correcta, si no el retorno es -1.
*/
int venta_cobrar(Venta* arrayVentas, int lenVentas, void *arrayClientesVoid, int lenClientes, int reintentos)
{
    int retorno = -1;
    Venta *ventaCobrar;
    Cliente *arrayClientes = arrayClientesVoid;
    Cliente *clienteMostrar = NULL;
    char confirmarBaja[10];
    int id;
    int i;
    if(arrayVentas != NULL && lenVentas > 0 && arrayClientes != NULL && lenClientes > 0 && reintentos >= 0)
    {
        venta_mostrar(arrayVentas, lenVentas);
        for(i=0; i<= reintentos; i++)
        {
            if( !utn_getEntero(&id, lenVentas, "Introduzca el Id de venta a cobrar\n", "", 0) &&
                venta_getById(arrayVentas, lenVentas, id) != NULL)
            {
                ventaCobrar = venta_getById(arrayVentas, lenVentas, id);
                if(ventaCobrar->estado == A_COBRAR)
                {
                    printf("Se cobrara la venta de este cliente\n");
                    clienteMostrar = cliente_getById(arrayClientes, lenClientes, ventaCobrar->idCliente);
                    if(clienteMostrar != NULL)
                    {
                        cliente_mostrar(clienteMostrar, 1);
                    }
                    if( !utn_getTexto(confirmarBaja, 10, "Pulse 1 para confirmar\n", "Error\n", 2) &&
                        strcmp(confirmarBaja, "1") == 0)
                    {
                        ventaCobrar->estado = COBRADA;
                        retorno = 0;
                    }
                    break;
                }
                else
                {
                    printf("La venta ya esta cobrada\n");
                }
            }
            else
            {
                printf("Id Erroneo\n");
            }
        }
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para cargar todos los datos de una venta
* \param arrayVentas Es el array que se recorre
* \param lenVentas Es el limite de ventas que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/
int venta_ingresoForzado(Venta* arrayVentas, int lenVentas, int idCliente, int afiches, char *archivo, int zona, int estado)
{
    int retorno = -1;
    int indice;
    indice = getLugarLibreVenta(arrayVentas,lenVentas);
    if( arrayVentas != NULL && lenVentas > 0 && idCliente >= 0 && afiches >= 0 && archivo != NULL &&
        zona > 0 && zona <= 3 && estado > 0 && estado <= 2)
    {
        arrayVentas[indice].idCliente = idCliente;
        arrayVentas[indice].cantidadAfiches = afiches;
        strncpy(arrayVentas[indice].archivoImagen, archivo, 51);
        arrayVentas[indice].zona = zona;
        arrayVentas[indice].estado = estado;
        arrayVentas[indice].idVenta = getNextId();
        arrayVentas[indice].isEmpty = 0;
        retorno = 0;
    }
    return retorno;
}
/**
* \brief    Se utiliza esta funcion para mostrar todos los datos de las ventas
* \param arrayVentas Es el array que se recorre
* \param lenVentas Es el limite de ventas que puede guardar el array
* \return El retorno es 0 si se mostraron los datos, si no el retorno es -1.
*/
int venta_mostrar(Venta* arrayVentas, int lenVentas)
{
    int retorno = -1;
    int i;
    if(arrayVentas != NULL && lenVentas > 0)
    {
        for(i=0;i<lenVentas;i++)
        {
            if(!arrayVentas[i].isEmpty)
            {
                printf("\nIdcliente: %d\nAfiches: %d\nImagen: %s\nIDVenta: %d\n",
                arrayVentas[i].idCliente, arrayVentas[i].cantidadAfiches,
                arrayVentas[i].archivoImagen, arrayVentas[i].idVenta);
                if(arrayVentas[i].zona == CABA)
                {
                    printf("Zona: CABA\n");
                }
                else if(arrayVentas[i].zona == ZONA_SUR)
                {
                    printf("Zona: Zona Sur\n");
                }
                else if(arrayVentas[i].zona == ZONA_OESTE)
                {
                    printf("Zona: Zona Oeste\n");
                }
                if(arrayVentas[i].estado == A_COBRAR)
                {
                    printf("Estado: A cobrar\n\n");
                }
                else if(arrayVentas[i].estado == COBRADA)
                {
                    printf("Estado: Cobrado\n\n");
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}
