//#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "afiches.h"
#define CABA 1
#define ZONA_SUR 2
#define ZONA_OESTE 3
#define VENTA_COBRAR 1
#define VENTA_COBRADA 2

//static int comparacionNombreApellido(Cliente* arrayUno, Cliente* arrayDos)
//{
//    int retorno=-1;
//    if(arrayUno != NULL && arrayDos != NULL && !arrayUno->isEmpty && !arrayDos->isEmpty)
//    {
//        if(strcmp(arrayUno->nombre, arrayDos->nombre)> 0 ||
//          (strcmp(arrayUno->nombre, arrayDos->nombre)== 0 && strcmp(arrayUno->apellido, arrayDos->apellido) > 0))
//        {
//            retorno = 0;
//        }
//    }
//    return retorno;
//}
//
//int informar_sortClientePorNombreApellido(Cliente* array, int len)
//{
//    Cliente auxiliar;
//    int retorno=-1;
//    int i;
//    int j;
//    if(array != NULL && len > 0 )
//    {
//        for(i=1; i < len; i++)
//        {
//            auxiliar = array[i];
//            j = i - 1;
//            while ((j >= 0) && !comparacionNombreApellido(&array[j], &auxiliar))
//            {
//                array[j + 1] = array[j];
//                j--;
//            }
//            array[j + 1] = auxiliar;
//        }
//        retorno = 0;
//    }
//    return retorno;
//}
//
//int informar_ventasMayorMenorNumeroAfiches(Afiche* arrayAfiche, int lenAfiche, int* cantidadVentas,int mayorMenor, int numeroAfiches)
//{
//    int retorno=-1;
//    int i;
//    if(arrayAfiche != NULL && lenAfiche > 0)
//    {
//        for(i=0; i < lenAfiche; i++)
//        {
//            if(mayorMenor == 0 && !arrayAfiche[i].isEmpty && arrayAfiche[i].cantidadAfiche > numeroAfiches)
//            {
//                afiche_mostrar(&(arrayAfiche[i]),1);
//                *cantidadVentas = *cantidadVentas + 1;
//            }
//            else if(mayorMenor == 1 && !arrayAfiche[i].isEmpty && arrayAfiche[i].cantidadAfiche < numeroAfiches)
//            {
//                afiche_mostrar(&(arrayAfiche[i]), 1);
//                printf("%d",*cantidadVentas);
//                *cantidadVentas = *cantidadVentas + 1;
//            }
//        }
//        retorno = 0;
//    }
//    return retorno;
//}
//
//int informar_cantidadTotalDeAfiches(Afiche* arrayAfiche, int lenAfiche, int *cantidadTotalAfiches)
//{
//    int retorno=-1;
//    int i;
//    if(arrayAfiche != NULL && lenAfiche > 0)
//    {
//        *cantidadTotalAfiches = 0;
//        for(i=0; i < lenAfiche; i++)
//        {
//            if(!arrayAfiche[i].isEmpty)
//            {
//                *cantidadTotalAfiches+=arrayAfiche[i].cantidadAfiche;
//            }
//        }
//        retorno = 0;
//    }
//    return retorno;
//}
//
//int informar_cantidadTotalDeVentas(Afiche* arrayAfiche, int lenAfiche, int *cantidadTotalVentas)
//{
//    int retorno=-1;
//    int i;
//    if(arrayAfiche != NULL && lenAfiche > 0)
//    {
//        *cantidadTotalVentas = 0;
//        for(i=0; i < lenAfiche; i++)
//        {
//            if(!arrayAfiche[i].isEmpty)
//            {
//                *cantidadTotalVentas+=1;
//            }
//        }
//        retorno = 0;
//    }
//    return retorno;
//}
//
//int informar_promedioAfichesPorVenta(Afiche* arrayAfiche, int lenAfiche, float *promedio)
//{
//    int retorno=-1;
//    int cantidadTotalAfiches;
//    int cantidadTotalVentas;
//    if( arrayAfiche != NULL && lenAfiche > 0 &&
//        !informar_cantidadTotalDeAfiches(arrayAfiche, lenAfiche, &cantidadTotalAfiches) &&
//        !informar_cantidadTotalDeVentas(arrayAfiche, lenAfiche, &cantidadTotalVentas))
//    {
//        *promedio = (float)cantidadTotalAfiches/cantidadTotalVentas;
//        retorno = 0;
//    }
//    return retorno;
//}
//
//int informar_VentasSuperaOrNoPromedioAfiches(Afiche* arrayAfiche,int lenAfiche,int *cantidadVentas,int SuperaNoSupera)
//{
//    int retorno=-1;
//    float promedio;
//    if( arrayAfiche != NULL && lenAfiche > 0 &&
//        !informar_promedioAfichesPorVenta(arrayAfiche, lenAfiche, &promedio) &&
//        !informar_ventasMayorMenorNumeroAfiches(arrayAfiche, lenAfiche, cantidadVentas, SuperaNoSupera, promedio))
//    {
//        retorno = 0;
//    }
//    return retorno;
//}
//
//int informar_mostrarVentaPorEstado(Afiche* arrayAfiche, int len, int estado)
//{
//    int retorno = -1;
//    int i;
//    if(arrayAfiche != NULL && len > 0)
//    {
//        for(i=0;i<len;i++)
//        {
//            if(!arrayAfiche[i].isEmpty && arrayAfiche[i].estado == estado)
//            {
//                printf("El ID del afiche es: %d\n",arrayAfiche[i].id);
//                printf("El ID del cliente es: %d\n",arrayAfiche[i].clienteId);
//                printf("El nombre del archivo de imagen del afiche es: %s\n",arrayAfiche[i].nombreArchivo);
//                printf("La cantidad de afiches son: %d\n",arrayAfiche[i].cantidadAfiche);
//
//                if(arrayAfiche[i].zona == 3)
//                {
//                    printf("Zona: Zona Oeste\n");
//                }
//                else if(arrayAfiche[i].zona == 2)
//                {
//                    printf("Zona: Zona Sur\n");
//                }
//                else if(arrayAfiche[i].zona)
//                {
//                    printf("Zona: CABA\n");
//                }
//                if(arrayAfiche[i].estado == 2)
//                {
//                    printf("Estado: Cobrado\n\n");
//                }
//                else if(arrayAfiche[i].estado)
//                {
//                    printf("Estado: A cobrar\n\n");
//                }
//            }
//        }
//        retorno = 0;
//    }
//    return retorno;
//}
//
//int informar_mostrarVentaPorZona(Afiche* arrayAfiche, int len, int zona)
//{
//    int retorno = -1;
//    int i;
//    if(arrayAfiche != NULL && len > 0)
//    {
//        for(i=0;i<len;i++)
//        {
//            if(!arrayAfiche[i].isEmpty && arrayAfiche[i].zona == zona)
//            {
//                printf("El ID del afiche es: %d\n",arrayAfiche[i].id);
//                printf("El ID del cliente es: %d\n",arrayAfiche[i].clienteId);
//                printf("El nombre del archivo de imagen del afiche es: %s\n",arrayAfiche[i].nombreArchivo);
//                printf("La cantidad de afiches son: %d\n",arrayAfiche[i].cantidadAfiche);
//
//                if(arrayAfiche[i].zona == 3)
//                {
//                    printf("Zona: Zona Oeste\n");
//                }
//                else if(arrayAfiche[i].zona == 2)
//                {
//                    printf("Zona: Zona Sur\n");
//                }
//                else if(arrayAfiche[i].zona)
//                {
//                    printf("Zona: CABA\n");
//                }
//                if(arrayAfiche[i].estado == 2)
//                {
//                    printf("Estado: Cobrado\n\n");
//                }
//                else if(arrayAfiche[i].estado)
//                {
//                    printf("Estado: A cobrar\n\n");
//                }
//            }
//        }
//        retorno = 0;
//    }
//    return retorno;
//}
//
//int informar_clienteTotalPorZona(Cliente* array, int len, Afiche* arrayAfiche, int lenAfiche,int* cantidadTotalClientes)
//{
//    int retorno = -1;
//    int i;
//    int j;
//    int contadorDeClientes = 0;
//    if(array != NULL && len > 0 && arrayAfiche != NULL && lenAfiche > 0)
//    {
//        for(i=0;i<len;i++)
//        {
//            if(!array[i].isEmpty)
//            {
//                contadorDeClientes = 0;
//                for(j=0;j<lenAfiche; j++)
//                {
//                    if(afiche_getById(&arrayAfiche[j],lenAfiche, array[i].id)!= NULL &&
//                        arrayAfiche[j].zona == 1)
//                    {
//                        contadorDeClientes+=1;
//                    }
//                }
//            }
//        *cantidadTotalClientes = contadorDeClientes;
//        retorno = 0;
//        }
//    }
//    return retorno;
//}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
* \brief    esta funcion sirve para encontrar una venta a través de un id de un cliente,recorriendo el array y comparando los id.
* \param    arrayAfiche Es el array que se recorre
* \param    lenAfiche Es el limite de afiches vendidos que puede guardar el array
* \param    idCliente Es el id con que se compara con cada clienteId del array
* \return   retorna la direccion de la estructura de la venta donde se encontro el id,
*           si no se retorna  NULL.
*/

Afiche* afiche_getByIdCliente(Afiche* arrayAfiche, int lenAfiche, int idCliente)
{
    Afiche* retorno = NULL;
    int i;
    if(arrayAfiche != NULL && lenAfiche > 0)
    {
        for(i=0;i<lenAfiche;i++)
        {
            if(!arrayAfiche[i].isEmpty && arrayAfiche[i].clienteId == idCliente)
            {
                retorno = &arrayAfiche[i];
                break;
            }
        }
    }
    return retorno;
}


/**
* \brief    esta funcion sirve para encontrar el cliente con mas ventas recorriendo los dos array y comparando la mayor cantidad de ventas
* \param    arrayAfiche Es el array que se recorre
* \param    arrayAfiche Es el segundo array a recorrer
* \param    lenAfiche Es el limite de afiches vendidos que puede guardar el array
* \param    lenCliente Es el limite de clientes del array.
* \return   retorna -1 en caso de error y 0 en el caso que este todo correcto
*
*/

int informar_clienteConMasVentas(Afiche* arrayAfiche, int lenAfiche,Cliente* arrayCliente, int lenCliente)
{
    int arrayCantidadVentasPorCliente[lenCliente];
    int retorno=-1;
    int i;
    int j;
    int mayorCantidadVentas = 0;
    int contadorDeVentasCliente;
    if(arrayAfiche != NULL && lenAfiche > 0 && arrayCliente != NULL && lenCliente > 0)
    {
        for(i=0; i < lenCliente; i++)
        {
            if(!arrayCliente[i].isEmpty)
            {
                contadorDeVentasCliente = 0;
                for(j=0;j<lenAfiche; j++)
                {
                    if(afiche_getByIdCliente(&arrayAfiche[j], 1, arrayCliente[i].id) != NULL)
                    {
                        contadorDeVentasCliente++;
                    }
                }
                arrayCantidadVentasPorCliente[i] = contadorDeVentasCliente;
            }
            if(!arrayCliente[i].isEmpty && arrayCantidadVentasPorCliente[i] > mayorCantidadVentas)
            {
                mayorCantidadVentas = arrayCantidadVentasPorCliente[i];
            }
        }
        for(i=0; i < lenCliente; i++)
        {
            if(!arrayCliente[i].isEmpty && mayorCantidadVentas == arrayCantidadVentasPorCliente[i])
            {
                cliente_mostrarTodo(&arrayCliente[i], 1);
            }
        }
        retorno = 0;
    }
    return retorno;
}

/**
* \brief    esta funcion sirve para encontrar el cliente con mas ventas a cobrar recorriendo los dos array y comparando los clientes con las ventas en el estado "A COBRAR"
* \param    arrayAfiche Es el array que se recorre
* \param    arrayAfiche Es el segundo array a recorrer
* \param    lenAfiche Es el limite de afiches vendidos que puede guardar el array
* \param    lenCliente Es el limite de clientes del array.
* \return   retorna -1 en caso de error y 0 en el caso que este todo correcto
*
*/


int informar_clienteConMasVentasAcobrar(Afiche* arrayAfiche, int lenAfiche,Cliente* arrayCliente, int lenCliente)
{
    int arrayCantidadVentasPorCliente[lenCliente];
    int retorno=-1;
    int i;
    int j;
    int mayorCantidadVentasAcobrar = 0;
    int contadorDeVentasCliente;
    if(arrayAfiche != NULL && lenAfiche > 0 && arrayCliente != NULL && lenCliente > 0)
    {
        for(i=0; i < lenCliente; i++)
        {
            if(!arrayCliente[i].isEmpty)
            {
                contadorDeVentasCliente = 0;
                for(j=0;j<lenAfiche; j++)
                {
                    if(afiche_getByIdCliente(&arrayAfiche[j], 1, arrayCliente[i].id) != NULL)
                    {
                        if(arrayAfiche[j].estado == 1)
                        {
                            contadorDeVentasCliente++;
                        }

                    }
                }
                arrayCantidadVentasPorCliente[i] = contadorDeVentasCliente;
            }
            if(!arrayCliente[i].isEmpty && arrayCantidadVentasPorCliente[i] > mayorCantidadVentasAcobrar)
            {
                mayorCantidadVentasAcobrar = arrayCantidadVentasPorCliente[i];
            }
        }
        for(i=0; i < lenCliente; i++)
        {
            if(!arrayCliente[i].isEmpty && mayorCantidadVentasAcobrar == arrayCantidadVentasPorCliente[i])
            {
                cliente_mostrarTodo(&arrayCliente[i], 1);
            }
        }
        retorno = 0;
    }
    return retorno;
}

/**
* \brief    esta funcion sirve para encontrar el cliente con mas ventas cobradas recorriendo los dos array y comparando los clientes con las ventas en el estado "COBRADO"
* \param    arrayAfiche Es el array que se recorre
* \param    arrayAfiche Es el segundo array a recorrer
* \param    lenAfiche Es el limite de afiches vendidos que puede guardar el array
* \param    lenCliente Es el limite de clientes del array.
* \return   retorna -1 en caso de error y 0 en el caso que este todo correcto
*
*/

int informar_clienteConMasVentasCobradas(Afiche* arrayAfiche, int lenAfiche,Cliente* arrayCliente, int lenCliente)
{
    int arrayCantidadVentasPorCliente[lenCliente];
    int retorno=-1;
    int i;
    int j;
    int mayorCantidadVentasCobradas = 0;
    int contadorDeVentasCliente;
    if(arrayAfiche != NULL && lenAfiche > 0 && arrayCliente != NULL && lenCliente > 0)
    {
        for(i=0; i < lenCliente; i++)
        {
            if(!arrayCliente[i].isEmpty)
            {
                contadorDeVentasCliente = 0;
                for(j=0;j<lenAfiche; j++)
                {
                    if(afiche_getByIdCliente(&arrayAfiche[j], 1, arrayCliente[i].id) != NULL)
                    {
                        if(arrayAfiche[j].estado == 2)
                        {
                            contadorDeVentasCliente++;
                        }

                    }
                }
                arrayCantidadVentasPorCliente[i] = contadorDeVentasCliente;
            }
            if(!arrayCliente[i].isEmpty && arrayCantidadVentasPorCliente[i] > mayorCantidadVentasCobradas)
            {
                mayorCantidadVentasCobradas = arrayCantidadVentasPorCliente[i];
            }
        }
        for(i=0; i < lenCliente; i++)
        {
            if(!arrayCliente[i].isEmpty && mayorCantidadVentasCobradas == arrayCantidadVentasPorCliente[i])
            {
                cliente_mostrarTodo(&arrayCliente[i], 1);
            }
        }
        retorno = 0;
    }
    return retorno;
}

/**
* \brief    esta funcion sirve para encontrar el cliente con mas afiches comprados recorriendo los dos array.
* \param    arrayAfiche Es el array que se recorre
* \param    arrayAfiche Es el segundo array a recorrer
* \param    lenAfiche Es el limite de afiches vendidos que puede guardar el array
* \param    lenCliente Es el limite de clientes del array.
* \return   retorna -1 en caso de error y 0 en el caso que este todo correcto
*
*/

int informar_clienteConMasAfichesComprados(Afiche* arrayAfiche, int lenAfiche,Cliente* arrayCliente, int lenCliente)
{
    int arrayCantidadAfichesPorCliente[lenCliente];
    int retorno=-1;
    int i;
    int j;
    int mayorCantidadAfiches = 0;
    int contadorDeAfichesPorCliente;
    if(arrayAfiche != NULL && lenAfiche > 0 && arrayCliente != NULL && lenCliente > 0)
    {
        for(i=0; i < lenCliente; i++)
        {
            if(!arrayCliente[i].isEmpty)
            {
                contadorDeAfichesPorCliente = 0;
                for(j=0;j<lenAfiche; j++)
                {
                    if(afiche_getByIdCliente(&arrayAfiche[j], 1, arrayCliente[i].id) != NULL)
                    {
                        contadorDeAfichesPorCliente+=arrayAfiche[j].cantidadAfiche;
                    }
                }
                arrayCantidadAfichesPorCliente[i] = contadorDeAfichesPorCliente;
            }
            if(!arrayCliente[i].isEmpty && arrayCantidadAfichesPorCliente[i] > mayorCantidadAfiches)
            {
                mayorCantidadAfiches = arrayCantidadAfichesPorCliente[i];
            }
        }
        for(i=0; i < lenCliente; i++)
        {
            if(!arrayCliente[i].isEmpty && mayorCantidadAfiches == arrayCantidadAfichesPorCliente[i])
            {
                cliente_mostrarTodo(&arrayCliente[i], 1);
            }
        }
        retorno = 0;
    }
    return retorno;
}

/**
* \brief    esta funcion sirve para encontrar el cliente con mas afiches a cobrar recorriendo los dos array.
* \param    arrayAfiche Es el array que se recorre
* \param    arrayAfiche Es el segundo array a recorrer
* \param    lenAfiche Es el limite de afiches vendidos que puede guardar el array
* \param    lenCliente Es el limite de clientes del array.
* \return   retorna -1 en caso de error y 0 en el caso que este todo correcto
*
*/

int informar_clienteConMasAfichesAcobrar(Afiche* arrayAfiche, int lenAfiche,Cliente* arrayCliente, int lenCliente)
{
    int arrayCantidadAfichesPorCliente[lenCliente];
    int retorno=-1;
    int i;
    int j;
    int mayorCantidadAfichesAcobrar = 0;
    int contadorDeAfichesPorCliente;
    if(arrayAfiche != NULL && lenAfiche > 0 && arrayCliente != NULL && lenCliente > 0)
    {
        for(i=0; i < lenCliente; i++)
        {
            if(!arrayCliente[i].isEmpty)
            {
                contadorDeAfichesPorCliente = 0;
                for(j=0;j<lenAfiche; j++)
                {
                    if(afiche_getByIdCliente(&arrayAfiche[j], 1, arrayCliente[i].id) != NULL)
                    {
                        if(arrayAfiche[j].estado == 1)
                        {
                            contadorDeAfichesPorCliente+=arrayAfiche[j].cantidadAfiche;
                        }

                    }
                }
                arrayCantidadAfichesPorCliente[i] = contadorDeAfichesPorCliente;
            }
            if(!arrayCliente[i].isEmpty && arrayCantidadAfichesPorCliente[i] > mayorCantidadAfichesAcobrar)
            {
                mayorCantidadAfichesAcobrar = arrayCantidadAfichesPorCliente[i];
            }
        }
        for(i=0; i < lenCliente; i++)
        {
            if(!arrayCliente[i].isEmpty && mayorCantidadAfichesAcobrar == arrayCantidadAfichesPorCliente[i])
            {
                cliente_mostrarTodo(&arrayCliente[i], 1);
            }
        }
        retorno = 0;
    }
    return retorno;
}

