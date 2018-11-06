//#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#define BUFFER_STR 4096
#define STRINGLEN 1000

/**
 * \brief Solicita ingreso de un texto con solo letras
 * \param pBuffer Es la variable donde se cargará el texto ingresado
 * \param limite Es el tamaño maximo del string
 * \return Retorna 0 si lo carga en variable del main sino retorna -1
 */

static int isValidNombre(char* pBuffer,int limite)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && limite > 0)
    {
        retorno = 1;
        for(i=0;i < limite && pBuffer[i] != '\0';i++)
        {
            if((tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z') && pBuffer[i]!= ' ')
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Solicita ingreso de un texto con solo letras
 * \param pBuffer Es la variable donde se cargará el texto ingresado
 * \param size Es el tamaño maximo del string
 * \return Retorna 0 si lo carga en variable del main sino retorna -1
 */

static int isValidDescription(char* pBuffer,int size)
{
    int retorno = 0;
    int i;
    if(pBuffer != NULL && size > 0)
    {
        retorno = 1;
        for(i=0;i < size && pBuffer[i] != '\0';i++)
        {
            if((tolower(pBuffer[i]) < 'a' || tolower(pBuffer[i]) > 'z') && (pBuffer[i] < '0' || pBuffer[i] > '9') && pBuffer[i]!= ' ' )
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
 * \brief Ingreso de un texto al usuario y lo devuelve
 * \param pBuffer Es el string a validar
 * \param limite es el limite del string
 * \return retorna - 1, en caso de error y 0 ,si no hay error
 */

static int getString(char* pBuffer, int limite)
{
    int retorno = -1;
    char bufferStr[BUFFER_STR];
    int len;
    if(pBuffer != NULL && limite > 0)
    {
        //fflush(stdin);
        __fpurge(stdin);
        fgets(bufferStr,limite,stdin);
        len = strlen(bufferStr);
        if(len != limite-1 ||  bufferStr[limite-2] == '\n')
        {
            bufferStr[len-1] = '\0';
        }
        retorno = 0;
        strncpy(pBuffer,bufferStr,limite);
    }
    return retorno;
}

/**
*\brief solicita un nombre al usuario,valida y devuelve el resultado
*\param pNombre Puntero a la variable resultado
*\param msg es el mensaje a ser mostrado
*\param msgErr es el mensaje a ser mostrado en caso de error
*\param reintentos es la cantidad de reintentos que tiene el usuario
*\return en caso de exito retorna 0 y en caso de error -1
*
*/

int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char* msgErr, int reintentos)

{
    int retorno= -1;
    char bufferNombre[BUFFER_STR];

    if( pNombre != NULL && limite > 0 && msg != NULL &&
        msgErr != NULL && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getString(bufferNombre,limite) == 0 &&
                isValidNombre(bufferNombre,limite))
            {
                strncpy(pNombre,bufferNombre,limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}


/**
*\brief solicita un numero al usuario,valida y devuelve el resultado
*\param pResultado Puntero a la variable resultado
*\param mensaje es el mensaje a ser mostrado
*\param mensajeError es el mensaje a ser mostrado en caso de error
*\param minimo es el numero minimo aceptado
*\param maximo e el numero maximo aceptado
*\param reintentos es la cantidad de reintentos que tiene el usuario
*\return en caso de exito retorna 0 y en caso de error -1
*
*/

int utn_getNumeroConComa(float* pResultado,
                char mensaje[],
                char mensajeError[],
                float  minimo,
                float  maximo,
                int  reintentos)
{
    int validado = 1;
    int tienePunto = 0;
    int tieneMenos = 0;
    char stringIngresado[STRINGLEN];//aca se guarda lo que ingreso como string
    float numero;
    printf("%s",mensaje);

     for(int i = 0;i<reintentos;i++)
    {
        validado = 1;
        tienePunto = 0;
        tieneMenos = 0;
        //fflush(stdin);
        __fpurge(stdin);
        fgets(stringIngresado, STRINGLEN, stdin);//pido un string con limite de caracters (STRINGLEN)

        for (int j=0; j<strlen(stringIngresado)-1; j++)//recorro caracter por caracter
        {
            if (stringIngresado[j] < '0' || stringIngresado[j] > '9')
            {
                //NaN
                if(j > 0 && j < strlen(stringIngresado)-2)
                {
                    //no estoy en el primero ni en el ultimo caracter
                    //si o si tengo que ser un punto
                    if(stringIngresado[j] != 46 || tienePunto == 1)
                    {
                        validado = 0;
                        break;
                    }
                    tienePunto = 1;
                }
                else
                {
                    if(j > 0 || stringIngresado[j] != 45)//si es un menos en la primer posicion safa
                    {
                        validado = 0;
                        break;
                    }
                    tieneMenos++;
                }

            }
        }
        if(tieneMenos == 1 && strlen(stringIngresado)-1 == 1)
        {
            validado = 0;
        }
        if (validado)
        {
            numero = atof(stringIngresado);
            if(numero >= minimo && numero <= maximo)
            {
                *pResultado = numero;//aca se le asigna el valor de numero a la variable apuntada por pResultado
                return 0;
            }
            printf("%s",mensajeError);
        }
        else {
           printf("%s",mensajeError);
        }
    }

    return -1;
}

/**
*\brief solicita una descripcion al usuario,valida y devuelve el resultado
*\param pDescription Puntero a la variable resultado
*\param msg es el mensaje a ser mostrado
*\param msgErr es el mensaje a ser mostrado en caso de error
*\param reintentos es la cantidad de reintentos que tiene el usuario
*\return en caso de exito retorna 0 y en caso de error -1
*
*/


int utn_getDescription(  char* pDescription, int size, char* msg,
                    char* msgErr, int reintentos)

{
    int retorno=-1;
    char bufferDescription[BUFFER_STR];

    if( pDescription != NULL && size > 0 && msg != NULL &&
        msgErr != NULL && reintentos >= 0)
    {
        do
        {
            reintentos--;
            printf("%s",msg);
            if( getString(bufferDescription,size) == 0 &&
                isValidDescription(bufferDescription,size))
            {
                strncpy(pDescription,bufferDescription,size);
                retorno = 0;
                break;
            }
            else
            {
                printf("%s",msgErr);
            }
        }while(reintentos >= 0);
    }
    return retorno;
}

/**
*\brief solicita un numero al usuario,valida y lo guarda en el puntero recibido por parametro
*\param pResultado Puntero a la variable resultado
*\param mensaje es el mensaje a ser mostrado
*\param mensajeError es el mensaje a ser mostrado en caso de error
*\param minimo es el numero minimo aceptado
*\param maximo e el numero maximo aceptado
*\param reintentos es la cantidad de reintentos que tiene el usuario
*\return en caso de exito retorna 0 y en caso de error -1
*
*/

int utn_getNumero(int* pResultado,
                char mensaje[],
                char mensajeError[],
                int  minimo,
                int  maximo,
                int  reintentos)
{
    char stringIngresado[STRINGLEN];//aca se guarda lo que ingreso como string
    int numero;
    int validado = 1;
    int hayUnMenos = 0;

    printf("%s",mensaje);

     for(int i = 0;i<reintentos;i++)
    {
        validado = 1;
        //fflush(stdin);
        __fpurge(stdin);
        fgets(stringIngresado, STRINGLEN, stdin);//pido un string con limite de caracters (STRINGLEN)

        for (int j=0; j<strlen(stringIngresado)-1; j++)//recorro caracter por caracter
        {
            if (stringIngresado[j] < '0' || stringIngresado[j] > '9')//no esta en rango
            {
                //soy NaN
                if(j > 0 || stringIngresado[j] != 45)
                {
                    validado = 0;
                    break;
                }
                hayUnMenos = 1;
            }
        }
        if(hayUnMenos == 1 && strlen(stringIngresado)-1 == 1)
        {
            validado = 0;

        }
        if (validado)
        {
            numero = atoi(stringIngresado);
            if(numero >= minimo && numero <= maximo)
            {
                *pResultado = numero;//aca se le asigna el valor de numero a la variable apuntada por pResultado
                return 0;
            }
            if(numero < minimo || numero > maximo)
            {
                printf("%s",mensajeError);
            }
        }

    }

    return -1;
}

/**
*\brief solicita un cuit al usuario,valida y devuelve el resultado
*\param pResultado Puntero a la variable resultado
*\param mensaje es el mensaje a ser mostrado
*\param mensajeError es el mensaje a ser mostrado en caso de error
*\param reintentos es la cantidad de reintentos que tiene el usuario
*\return en caso de exito retorna 0 y en caso de error -1
*
*/

int utn_getCuit(char* pResultado,
                char mensaje[],
                char mensajeError[],
                int  reintentos)
{
    char stringIngresado[14];//aca se guarda lo que ingreso como string
    int validado = 1;//true

    printf("%s",mensaje);

     for(int i = 0;i<reintentos;i++)
    {
        validado = 1;
        //fflush(stdin);
        __fpurge(stdin);
        fgets(stringIngresado, 14 + 2, stdin);//pido un string con limite de caracters para un cuit CUITSTRINGLEN
//        printf("%d",strlen(stringIngresado));
//        return -1;
        if(strlen(stringIngresado) != 14)
        {
            printf("%s ",mensajeError);
            continue;
        }
        for (int j=0; j<strlen(stringIngresado)-2; j++)//recorro caracter por caracter (hasta el caracter numero 13 = posicion 12
        {
             if(j == 2 || j == 11)
             {
                //valido que sea un guion
                if(stringIngresado[j] != '-')
                {
//                    printf("no hay guion en la pos %d", j);
//                    return -1;
                    validado = 0;//false
                    break;
                }
             }
             else
             {
                 //valido que sea un numero
                if (stringIngresado[j] < '0' || stringIngresado[j] > '9')//no esta en rango
                {
                    //soy NaN
//                    printf("hay un nan en la pos %d",j);
                    validado = 0;//false
                    break;

                }
             }
        }

        if (validado)
        {
            strcpy(pResultado,stringIngresado);//aca se le asigna el valor del string como cuit a la variable apuntada por pResultado
            return 0;
        }
        else
        {
            printf("%s ",mensajeError);
        }

    }

    return -1;
}















