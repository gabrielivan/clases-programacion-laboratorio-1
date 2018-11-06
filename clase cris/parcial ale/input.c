#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

void limpiarMemoria()
{
    fflush(stdin);  //WINDOWS
    //__fpurge(stdin);  //LINUX
}
void limpiarPantalla()
{
    system("cls"); //WINDOWS
    //system("clear"); //LINUX
}



/**
 * \brief Solicita un número entero y lo retorna
 * \param *mensaje Es el mensaje para mostrar al usuario
 * \return Entero ingresado por el usuario
 */
int input_ScanInt(char* mensaje,int* numero)
{
    int retorno = -1;
    int auxiliarInt;
    printf("%s",mensaje);
    scanf("%d",&auxiliarInt);
    *numero = auxiliarInt;
    retorno = 0;
    return retorno;
}

/**
 * \brief Solicita un número flotante y lo retorna
 * \param *mensaje Es el mensaje para mostrar al usuario
 * \return Flotante ingresado por el usuario
 */

float input_ScanFloat(char* mensaje,float* numero)
{
    int retorno = -1;
    float auxiliarFloat;
    printf("%s",mensaje);
    scanf("%f",&auxiliarFloat);
    *numero = auxiliarFloat;
    retorno = 0;
    return retorno;
}


/**
 * \brief Solicita un caracter y lo retorna
 * \param *mensaje Es el mensaje para mostrar al usuario
 * \return Caracter ingresado por el usuario
 *
 */
char input_ScanChar(char* mensaje,char* caracter)
{
    int retorno = -1;
    char auxiliarChar;
    printf("%s",mensaje);
    scanf("%c",&auxiliarChar);
    *caracter = auxiliarChar;
    retorno = 0;
    return retorno;
}


/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
int input_getString(char mensaje[],int size,char input[])
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
int input_getLetras(char input[],int size,char mensaje[],char msjError[])
{
    char buffer[size];
    int retorno = 1;

    printf("%s",mensaje);
    //Se recibe variable a cargar por string
    if(input_getString(mensaje,size,buffer) == 0 && validacion_Letras(buffer,size) == 1)
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
int input_getNumeros(int* input,int size,char mensaje[],char msjError[],int minimo,int maximo)
{
    char buffer[size];
    int auxiliar;
    int retorno = 1;

    printf("%s",mensaje);

    if(input_getString(mensaje,size,buffer) == 0 && validacion_Int(buffer,size))
    {
        auxiliar = atoi(buffer);
        *input = auxiliar;
        retorno = 0;
    }
    return retorno;
}


int input_getFloat(float* input,int size,char mensaje[],char msjError[],int minimo,int maximo)
{
    char buffer[size];
    float auxiliar;
    int retorno = 1;

    printf("%s",mensaje);

    if(input_getString(mensaje,size,buffer) == 0 && validacion_Float(buffer,size))
    {
        auxiliar = atof(buffer);
        *input = auxiliar;
        retorno = 0;
    }
    else
    {
        printf("%s",msjError);
    }
    return retorno;
}

int input_getDNI(char input[],int size,char mensaje[],char msjError[])
{
    char buffer[size];
    int retorno = 1;

    printf("%s",mensaje);

    if(input_getString(mensaje,size,buffer) == 0 && validacion_DNI(buffer,size))
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

int input_getCuit(char input[],int size,char mensaje[],char msjError[])
{
    char buffer[size];
    int retorno = 1;

    printf("%s",mensaje);

    if(input_getString(mensaje,size,buffer) == 0 && validacion_Cuit(buffer,size))
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

int input_getAlfanumerico(char input[],int size,char mensaje[],char msjError[])
{
    char buffer[size];
    int retorno = 1;

    printf("%s",mensaje);
    //Se recibe variable a cargar por string
    if(input_getString(mensaje,size,buffer) == 0 && validacion_AlfaNumerico(buffer,size) == 1)
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
