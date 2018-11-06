#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
int string_getString(char mensaje[],int size,char input[])
{
    int retorno = -1;
    char buffer[size];
    int length;

    do
    {
        limpiarMemoria();
        fgets(buffer,size,stdin);

        length = strlen(buffer);
        if(length != size-1 || buffer[size-2] == '\n')
        {
            buffer[length-1] = '\0';
        }
        strncpy(input,buffer,size);

        retorno = 0;
    }while(input == NULL && size < 0);

    return retorno;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int string_getStringLetras(char input[],int size,char mensaje[],char msjError[])
{
    char buffer[size];
    int retorno = 1;

    printf("%s",mensaje);
    //Se recibe variable a cargar por string
    if(string_getString(mensaje,size,buffer) == 0 && validacion_Letras(buffer) == 1)
    {
        strncpy(input,buffer,size);//Se copia string cargado a variable local
        retorno = 0;
    }
    else
    {
        printf("%s",msjError);
    }
    return retorno;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param size Es el tamaño del string recibido
 * \param minimo Es el minimo valor permitido para ingresar
 * \param maximo Es el maximo valor permitido para ingresar
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int string_getStringNumeros(char input[],int size,char mensaje[],char msjError[],int minimo,int maximo)
{
    char buffer[size];
    int retorno = 1;

    printf("%s",mensaje);

    if(string_getString(mensaje,size,buffer) == 0 && validacion_Int(buffer,size))
    {

        strncpy(input,buffer,size);//Se copia string cargado a variable local
        retorno = 0;

    }
    return retorno;
}


int string_getStringFloat(char input[],int size,char mensaje[],char msjError[],int minimo,int maximo)
{
    char buffer[size];
    int retorno = 1;

    printf("%s",mensaje);

    if(string_getString(mensaje,size,buffer) == 0 && validacion_Float(buffer,size))
    {
        strncpy(input,buffer,size);//Se copia string cargado a variable local
        retorno = 0;
    }
    else
    {
        printf("%s",msjError);
    }
    return retorno;
}

int string_getStringDNI(char input[],int size,char mensaje[],char msjError[],int minimo,int maximo)
{
    char buffer[size];
    int retorno = 1;

    printf("%s",mensaje);

    if(string_getString(mensaje,size,buffer) == 0 && validacion_DNI(buffer,size) && strlen(buffer) <= maximo)
    {
        strncpy(input,buffer,size);//Se copia string cargado a variable local
        retorno = 0;
    }
    else
    {
        printf("%s",msjError);
    }

    return retorno;
}


void string_inicializar(char array[],int size,char valor)
{
    char buffer[size];
    int i;

    for(i=0;i<size;i++)
    {
        buffer[i] = valor;
    }

    strncpy(array,buffer,size);

}
