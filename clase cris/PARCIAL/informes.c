#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "afiches.h"
#define CABA 1
#define ZONA_SUR 2
#define ZONA_OESTE 3
#define VENTA_COBRAR 1
#define VENTA_COBRADA 2

static int comparacionNombreApellido(Cliente* arrayUno, Cliente* arrayDos)
{
    int retorno=-1;
    if(arrayUno != NULL && arrayDos != NULL && !arrayUno->isEmpty && !arrayDos->isEmpty)
    {
        if(strcmp(arrayUno->nombre, arrayDos->nombre)> 0 || strcmp(arrayUno->apellido, arrayDos->apellido) > 0)
        {
            retorno = 0;
        }
    }
    return retorno;
}

int informar_sortClientePorNombreApellido(Cliente* array, int len)
{
    Cliente auxiliar;
    int retorno=-1;
    int i;
    int j;
    if(array != NULL && len > 0 )
    {
        for(i=1; i < len; i++)
        {
            auxiliar = array[i];
            j = i - 1;
            while ((j >= 0) && !comparacionNombreApellido(&array[j], &auxiliar))
            {
                array[j + 1] = array[j];
                j--;
            }
            array[j + 1] = auxiliar;
        }
        retorno = 0;
    }
    return retorno;
}

int informar_ventasMayorMenorNumeroAfiches(Afiche* arrayAfiche, int lenAfiche, int* cantidadVentas,int mayorMenor, int numeroAfiches)
{
    int retorno=-1;
    int i;
    if(arrayAfiche != NULL && lenAfiche > 0)
    {
        for(i=0; i < lenAfiche; i++)
        {
            if(mayorMenor == 0 && !arrayAfiche[i].isEmpty && arrayAfiche[i].cantidadAfiche > numeroAfiches)
            {
                afiche_mostrar(&(arrayAfiche[i]),1);
                *cantidadVentas+=1;
            }
            else if(mayorMenor == 1 && !arrayAfiche[i].isEmpty && arrayAfiche[i].cantidadAfiche < numeroAfiches)
            {
                afiche_mostrar(&(arrayAfiche[i]), 1);
                *cantidadVentas+=1;
            }
        }
        retorno = 0;
    }
    return retorno;
}

int informar_cantidadTotalDeAfiches(Afiche* arrayAfiche, int lenAfiche, int *cantidadTotalAfiches)
{
    int retorno=-1;
    int i;
    if(arrayAfiche != NULL && lenAfiche > 0)
    {
        *cantidadTotalAfiches = 0;
        for(i=0; i < lenAfiche; i++)
        {
            if(!arrayAfiche[i].isEmpty)
            {
                *cantidadTotalAfiches+=arrayAfiche[i].cantidadAfiche;
            }
        }
        retorno = 0;
    }
    return retorno;
}

int informar_cantidadTotalDeVentas(Afiche* arrayAfiche, int lenAfiche, int *cantidadTotalVentas)
{
    int retorno=-1;
    int i;
    if(arrayAfiche != NULL && lenAfiche > 0)
    {
        *cantidadTotalVentas = 0;
        for(i=0; i < lenAfiche; i++)
        {
            if(!arrayAfiche[i].isEmpty)
            {
                *cantidadTotalVentas+=1;
            }
        }
        retorno = 0;
    }
    return retorno;
}

int informar_promedioAfichesPorVenta(Afiche* arrayAfiche, int lenAfiche, float *promedio)
{
    int retorno=-1;
    int cantidadTotalAfiches;
    int cantidadTotalVentas;
    if( arrayAfiche != NULL && lenAfiche > 0 &&
        !informar_cantidadTotalDeAfiches(arrayAfiche, lenAfiche, &cantidadTotalAfiches) &&
        !informar_cantidadTotalDeVentas(arrayAfiche, lenAfiche, &cantidadTotalVentas))
    {
        *promedio = (float)cantidadTotalAfiches/cantidadTotalVentas;
        retorno = 0;
    }
    return retorno;
}

int informar_VentasSuperaOrNoPromedioAfiches(Afiche* arrayAfiche,int lenAfiche,int *cantidadVentas,int SuperaNoSupera)
{
    int retorno=-1;
    float promedio;
    if( arrayAfiche != NULL && lenAfiche > 0 &&
        !informar_promedioAfichesPorVenta(arrayAfiche, lenAfiche, &promedio) &&
        !informar_ventasMayorMenorNumeroAfiches(arrayAfiche, lenAfiche, cantidadVentas, SuperaNoSupera, promedio))
    {
        retorno = 0;
    }
    return retorno;
}

int informar_mostrarVentaPorEstado(Afiche* arrayAfiche, int len, int estado)
{
    int retorno = -1;
    int i;
    if(arrayAfiche != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!arrayAfiche[i].isEmpty && arrayAfiche[i].estado == estado)
            {
                printf("El ID del afiche es: %d\n",arrayAfiche[i].id);
                printf("El ID del cliente es: %d\n",arrayAfiche[i].clienteId);
                printf("El nombre del archivo de imagen del afiche es: %s\n",arrayAfiche[i].nombreArchivo);
                printf("La cantidad de afiches son: %d\n",arrayAfiche[i].cantidadAfiche);

                if(arrayAfiche[i].zona == 3)
                {
                    printf("Zona: Zona Oeste\n");
                }
                else if(arrayAfiche[i].zona == 2)
                {
                    printf("Zona: Zona Sur\n");
                }
                else if(arrayAfiche[i].zona)
                {
                    printf("Zona: CABA\n");
                }
                if(arrayAfiche[i].estado == 2)
                {
                    printf("Estado: Cobrado\n\n");
                }
                else if(arrayAfiche[i].estado)
                {
                    printf("Estado: A cobrar\n\n");
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}

int informar_mostrarVentaPorZona(Afiche* arrayAfiche, int len, int zona)
{
    int retorno = -1;
    int i;
    if(arrayAfiche != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(!arrayAfiche[i].isEmpty && arrayAfiche[i].zona == zona)
            {
                printf("El ID del afiche es: %d\n",arrayAfiche[i].id);
                printf("El ID del cliente es: %d\n",arrayAfiche[i].clienteId);
                printf("El nombre del archivo de imagen del afiche es: %s\n",arrayAfiche[i].nombreArchivo);
                printf("La cantidad de afiches son: %d\n",arrayAfiche[i].cantidadAfiche);

                if(arrayAfiche[i].zona == 3)
                {
                    printf("Zona: Zona Oeste\n");
                }
                else if(arrayAfiche[i].zona == 2)
                {
                    printf("Zona: Zona Sur\n");
                }
                else if(arrayAfiche[i].zona)
                {
                    printf("Zona: CABA\n");
                }
                if(arrayAfiche[i].estado == 2)
                {
                    printf("Estado: Cobrado\n\n");
                }
                else if(arrayAfiche[i].estado)
                {
                    printf("Estado: A cobrar\n\n");
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}

