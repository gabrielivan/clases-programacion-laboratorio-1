#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "informes.h"
#include "cliente.h"
#include "venta.h"
static int comparacionNombreApellido(Cliente* arrayUno, Cliente* arrayDos)
{
    int retorno=-1;
    if(arrayUno != NULL && arrayDos != NULL && !arrayUno->isEmpty && !arrayDos->isEmpty)
    {
        if(strcmp(arrayUno->apellido, arrayDos->apellido)> 0 ||
        (strcmp(arrayUno->apellido, arrayDos->apellido)== 0 && strcmp(arrayUno->nombre, arrayDos->nombre) > 0))
        {
            retorno = 0;
        }
    }
    return retorno;
}
int informar_sortClientePorApellidoNombre(void* arrayClientesVoid, int lenClientes)
{
    Cliente auxiliar;
    Cliente* arrayClientes = arrayClientesVoid;
    int retorno=-1;
    int i;
    int j;
    if(arrayClientes != NULL && lenClientes > 0 )
    {
        for(i=1; i < lenClientes; i++)
        {
            auxiliar = arrayClientes[i];
            j = i - 1;
            if(!auxiliar.isEmpty)
            {
                while ((j >= 0) && !comparacionNombreApellido(&arrayClientes[j], &auxiliar))
                {
                    arrayClientes[j + 1] = arrayClientes[j];
                    j--;
                }
                arrayClientes[j + 1] = auxiliar;
            }
        }
        retorno = 0;
    }
    return retorno;
}

int informar_sortClientePorCuit(void* arrayClientesVoid, int lenClientes)
{
    Cliente auxiliar;
    Cliente* arrayClientes = arrayClientesVoid;
    int retorno=-1;
    int i;
    int j;
    if(arrayClientes != NULL && lenClientes > 0 )
    {
        for(i=1; i < lenClientes; i++)
        {
            auxiliar = arrayClientes[i];
            j = i - 1;
            if(!auxiliar.isEmpty)
            {
                while ((j >= 0) && strcmp(arrayClientes[j].cuit, auxiliar.cuit) > 0)
                {
                    arrayClientes[j + 1] = arrayClientes[j];
                    j--;
                }
                arrayClientes[j + 1] = auxiliar;
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_ventasMayorMenorAfichesNumero(void *arrayVentasVoid, int lenVentas, int *cantidadVentas,int mayorMenor, int numeroAfiches)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno=-1;
    int i;
    if(arrayVentas != NULL && lenVentas > 0)
    {
        for(i=0; i < lenVentas; i++)
        {
            if(mayorMenor == 0 && !arrayVentas[i].isEmpty && arrayVentas[i].cantidadAfiches > numeroAfiches)
            {
                venta_mostrar(&(arrayVentas[i]), 1);
                *cantidadVentas+=1;
            }
            else if(mayorMenor == 1 && !arrayVentas[i].isEmpty && arrayVentas[i].cantidadAfiches < numeroAfiches)
            {
                venta_mostrar(&(arrayVentas[i]), 1);
                *cantidadVentas+=1;
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_cantidadTotalDeAfiches(void* arrayVentasVoid, int lenVentas, int *cantidadTotalAfiches)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno=-1;
    int i;
    if(arrayVentas != NULL && lenVentas > 0)
    {
        *cantidadTotalAfiches = 0;
        for(i=0; i < lenVentas; i++)
        {
            if(!arrayVentas[i].isEmpty)
            {
                *cantidadTotalAfiches+=arrayVentas[i].cantidadAfiches;
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_cantidadTotalDeVentas(void* arrayVentasVoid, int lenVentas, int *cantidadTotalVentas)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno=-1;
    int i;
    if(arrayVentas != NULL && lenVentas > 0)
    {
        *cantidadTotalVentas = 0;
        for(i=0; i < lenVentas; i++)
        {
            if(!arrayVentas[i].isEmpty)
            {
                *cantidadTotalVentas+=1;
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_promedioAfichesPorVenta(void* arrayVentasVoid, int lenVentas, float *promedio)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno=-1;
    int cantidadTotalAfiches;
    int cantidadTotalVentas;
    if( arrayVentas != NULL && lenVentas > 0 &&
        !informar_cantidadTotalDeAfiches(arrayVentas, lenVentas, &cantidadTotalAfiches) &&
        !informar_cantidadTotalDeVentas(arrayVentas, lenVentas, &cantidadTotalVentas))
    {
        *promedio = (float)cantidadTotalAfiches/cantidadTotalVentas;
        retorno = 0;
    }
    return retorno;
}
int informar_ventasSuperaOrNoPromedioAfiches(void* arrayVentasVoid,int lenVentas,int *cantidadVentas,int SuperaOrNo)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno=-1;
    float promedio;
    if( arrayVentas != NULL && lenVentas > 0 &&
        !informar_promedioAfichesPorVenta(arrayVentas, lenVentas, &promedio) &&
        !informar_ventasMayorMenorAfichesNumero(arrayVentas, lenVentas, cantidadVentas, SuperaOrNo, promedio))
    {
        retorno = 0;
    }
    return retorno;
}
int informar_mostrarVentaPorEstado(void* arrayVentasVoid, int len, int estado)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno = -1;
    int i;
    if(arrayVentas != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!arrayVentas[i].isEmpty && arrayVentas[i].estado == estado)
            {
                printf("\nIdcliente: %d\nAfiches: %d\nImagen: %s\nIDVenta: %d\n",
                arrayVentas[i].idCliente, arrayVentas[i].cantidadAfiches, arrayVentas[i].archivoImagen, arrayVentas[i].idVenta);
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
int informar_mostrarVentaPorZona(void* arrayVentasVoid, int len, int zona)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno = -1;
    int i;
    if(arrayVentas != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!arrayVentas[i].isEmpty && arrayVentas[i].zona == zona)
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
int informar_mostrarVentaPorEstadoAndZona(void* arrayVentasVoid, int len, int estado ,int zona)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno = -1;
    int i;
    if(arrayVentas != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!arrayVentas[i].isEmpty && arrayVentas[i].zona == zona && arrayVentas[i].estado == estado)
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
int informar_ventaConMasAfiches(void* arrayVentasVoid, int lenVentas)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno=-1;
    int i;
    int mayorCantidadAfiches;
    if(arrayVentas != NULL && lenVentas > 0)
    {
        mayorCantidadAfiches = arrayVentas[0].cantidadAfiches;
        for(i=1; i < lenVentas; i++)
        {
            if(!arrayVentas[i].isEmpty && arrayVentas[i].cantidadAfiches > mayorCantidadAfiches)
            {
                mayorCantidadAfiches = arrayVentas[i].cantidadAfiches;
            }
        }
        for(i=0; i < lenVentas; i++)
        {
            if(!arrayVentas[i].isEmpty && mayorCantidadAfiches == arrayVentas[i].cantidadAfiches)
            {
                venta_mostrar(&arrayVentas[i], 1);
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_clienteConMasVentas(void* arrayVentasVoid, int lenVentas,void* arrayClientesVoid, int lenClientes)
{
    Venta* arrayVentas = arrayVentasVoid;
    Cliente* arrayClientes = arrayClientesVoid;
    int arrayCantidadVentasPorCliente[lenClientes];
    int retorno=-1;
    int i;
    int j;
    int mayorCantidadVentas = 0;
    int contadorDeVentasCliente;
    if(arrayVentas != NULL && lenVentas > 0 && arrayClientes != NULL && lenClientes > 0)
    {
        for(i=0; i < lenClientes; i++)
        {
            if(!arrayClientes[i].isEmpty)
            {
                contadorDeVentasCliente = 0;
                for(j=0;j<lenVentas; j++)
                {
                    if(venta_getByIdCliente(&arrayVentas[j], 1, arrayClientes[i].idCliente) != NULL)
                    {
                        contadorDeVentasCliente++;
                    }
                }
                arrayCantidadVentasPorCliente[i] = contadorDeVentasCliente;
            }
            if(!arrayClientes[i].isEmpty && arrayCantidadVentasPorCliente[i] > mayorCantidadVentas)
            {
                mayorCantidadVentas = arrayCantidadVentasPorCliente[i];
            }
        }
        for(i=0; i < lenClientes; i++)
        {
            if(!arrayClientes[i].isEmpty && mayorCantidadVentas == arrayCantidadVentasPorCliente[i])
            {
                cliente_mostrar(&arrayClientes[i], 1);
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_clienteConMasAfiches(void* arrayVentasVoid, int lenVentas,void* arrayClientesVoid, int lenClientes)
{
    Venta* arrayVentas = arrayVentasVoid;
    Cliente* arrayClientes = arrayClientesVoid;
    int arrayCantidadAfichesPorCliente[lenClientes];
    int retorno=-1;
    int i;
    int j;
    int mayorCantidadAfiches = 0;
    int contadorDeAfichesCliente;
    if(arrayVentas != NULL && lenVentas > 0 && arrayClientes != NULL && lenClientes > 0)
    {
        for(i=0; i < lenClientes; i++)
        {
            if(!arrayClientes[i].isEmpty)
            {
                contadorDeAfichesCliente = 0;
                for(j=0;j<lenVentas; j++)
                {
                    if(venta_getByIdCliente(&arrayVentas[j], 1, arrayClientes[i].idCliente) != NULL)
                    {
                        contadorDeAfichesCliente+=arrayVentas[j].cantidadAfiches;
                    }
                }
                arrayCantidadAfichesPorCliente[i] = contadorDeAfichesCliente;
            }
            if(!arrayClientes[i].isEmpty && arrayCantidadAfichesPorCliente[i] > mayorCantidadAfiches)
            {
                mayorCantidadAfiches = arrayCantidadAfichesPorCliente[i];
            }
        }
        for(i=0; i < lenClientes; i++)
        {
            if(!arrayClientes[i].isEmpty && mayorCantidadAfiches == arrayCantidadAfichesPorCliente[i])
            {
                cliente_mostrar(&arrayClientes[i], 1);
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_mostrarClientesPorZona(void* arrayClientesVoid, int lenClientes, void* arrayVentasVoid, int lenVentas, int zona)
{
    Venta* arrayVentas = arrayVentasVoid;
    Cliente* arrayClientes = arrayClientesVoid;
    int retorno = -1;
    int i;
    if(arrayVentas != NULL && lenVentas > 0 && arrayClientes != NULL && lenClientes > 0)
    {
        for(i=0;i<lenClientes;i++)
        {
            if(!arrayClientes[i].isEmpty && venta_getByIdClienteAndZona(arrayVentas,lenVentas,arrayClientes[i].idCliente, zona)!=NULL)
            {
                printf("\nNombre: %s\nApellido: %s\nCuit: %s\nID: %d\n\n",
                arrayClientes[i].nombre, arrayClientes[i].apellido, arrayClientes[i].cuit, arrayClientes[i].idCliente);
            }
        }
        retorno = 0;
    }
    return retorno;
}
int informar_afichesPorZona(void* arrayVentasVoid, int lenVentas, int zona)
{
    Venta* arrayVentas = arrayVentasVoid;
    int retorno = -1;
    int i;
    int cantidadAfiches = 0;
    if(arrayVentas != NULL && lenVentas > 0 && zona > 0 && zona <=3)
    {
        for(i=0;i<lenVentas;i++)
        {
            if(!arrayVentas[i].isEmpty && arrayVentas[i].zona == zona)
            {
                cantidadAfiches+=arrayVentas[i].cantidadAfiches;
            }
        }
        printf("La cantidad de afiches es %d\n", cantidadAfiches);
        retorno = 0;
    }
    return retorno;
}
