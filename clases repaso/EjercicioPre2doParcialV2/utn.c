#include <stdio.h>
//#include <stdio_ext.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "utn.h"
#define BUFFER_STR 4096
#define STRINGLEN 1000


void limpiarMemoria()
{
     fflush(stdin);  //WINDOWS
    //__fpurge(stdin); //LINUX
}

void limpiarPantalla()
{
    system("cls"); //WINDOWS
    //system("clear"); //LINUX
}

void pause()
{
    printf("\nIngrese cualquier tecla para continuar...");
    limpiarMemoria();
    getchar();
}

/////////////////////////////////////////////////////VALIDACIONES

/**
* \brief El usuario ingresa una cadena con fgets
* \param pBuffer Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 0, si no -1
*
*/

static int getString(char* pBuffer, int limite)
{
    int retorno = -1;
    char bufferStr[BUFFER_STR];
    int len;
    if(pBuffer != NULL && limite > 0)
    {
        limpiarMemoria();
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
* \brief    Evalua si es un nombre, solo puede tener un espacio y cada nombre
*           debe empezar por mayuscula y el resto minusculas (Jose)(Jose Maria)(Lopez)(Lopez Gomez)
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*
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
* \brief Evalua si se trata de un entero
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el numero maximo de cifras
* \return En caso de exito retorna 1, si no 0
*
*/

static int isValidEntero(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if  ((pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0) &&
        (pBuffer[0] == '-' || pBuffer[0] == '+' ||
        (pBuffer[0]>='0' && pBuffer[0]<='9')))
    {
        retorno = 1;
        for(i=1; i < limite && pBuffer[i] != '\0'; i++)
        {
            if (!(pBuffer[i]>='0' && pBuffer[i]<='9'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
*\brief valida que sea una descripcion valida
*\param pBuffer Puntero a la variable Description
*\param size es el tamaño del string
*\return en caso de exito retorna 0 y en caso de error -1
*
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
* \brief Evalua si es un Dni (XX.XXX.XXX) o (X.XXX.XXX)
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*
*/

static int isValidDni(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if( pBuffer != NULL && limite > 0 && strlen(pBuffer) == 10 &&
            pBuffer[2] == '.' && pBuffer[6] == '.')
    {
        retorno = 1;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
        {
            if((pBuffer[i] < '0' || pBuffer[i] > '9') && i!=2 && i != 6)
            {
                retorno = 0;
                break;
            }
        }
    }
    else if(pBuffer != NULL && limite > 0 && strlen(pBuffer) == 9 &&
            pBuffer[1] == '.' && pBuffer[5] == '.')
    {
        retorno = 1;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
        {
            if((pBuffer[i] < '0' || pBuffer[i] > '9') && i!=1 && i!=5)
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
* \brief Evalua si es un telefono fijo (4XXX-XXXX)
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*
*/

static int isValidTelefonoFijo(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if( pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0 &&
        strlen(pBuffer) == 9 && pBuffer[4] == '-' && pBuffer[0] == '4')
    {
        retorno = 1;
        for(i=1; i < limite && pBuffer[i] != '\0'; i++)
        {
            if((pBuffer[i] < '0' || pBuffer[i] > '9') && i!=4)
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}


/**
* \brief Evalua si se trata de un celular (XX-XXXX-XXXX)
* \param pBuffer Es la cadena que evaluamos
* \param limite Es el tamano maximo del string
* \return En caso de exito retorna 1, si no 0
*
*/

static int isValidCelularArgentino(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if( pBuffer != NULL && limite > 0 && strlen(pBuffer) == 12 &&
            pBuffer[2] == '-' && pBuffer[7] == '-')
    {
        retorno = 1;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
        {
            if((pBuffer[i] < '0' || pBuffer[i] > '9') && i!=2 && i!=7)
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/**
* \brief Evalua si es una fecha valida
* \param dia Toma el dia
* \param mes Toma el mes
* \param anio Toma el anio
* \return En caso de exito retorna 1, si no 0
*
*/

static int isValidFecha(int dia, int mes, int anio)
{
    int retorno = 0;
    if(dia > 0 && mes > 0 &&  anio > 0)
    {
        if(((mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12) &&
                (dia > 0 && dia <= 31)) ||
                ((mes == 4 || mes == 6 || mes == 9 || mes == 11) &&
                 (dia > 0 && dia <= 30)) ||
                ((mes == 2 && (anio % 4) == 0) &&
                 (dia > 0 && dia <= 29)) ||
                ((mes == 2 && (anio % 4) != 0) &&
                 (dia > 0 && dia <= 28)))
        {
            retorno = 1;
        }
    }
    return retorno;
}


/////////////////////////////////////////////////////TOMA DE DATOS

/**
*\brief solicita un nombre al usuario,valida y devuelve el resultado
*\param pResultado Puntero a la variable resultado
*\param mensaje es el mensaje a ser mostrado
*\param mensajeError es el mensaje a ser mostrado en caso de error
*\param reintentos es la cantidad de reintentos que tiene el usuario
*\return en caso de exito retorna 0 y en caso de error -1
*
*/

int utn_getNombre(  char* pNombre, int limite, char* msg,
                    char* msgErr, int reintentos)

{
    int retorno=-1;
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
        limpiarMemoria();
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
*\param pDescription Puntero a la variable Description
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
        limpiarMemoria();
        fgets(stringIngresado, STRINGLEN, stdin);//pido un string con limite de caracters (STRINGLEN)

        for (int j=0; j<strlen(stringIngresado)-1; j++)//recorro caracter por caracter
        {
            if (stringIngresado[j] < '0' || stringIngresado[j] > '9')//no esta en rango
            {
                //soy NaN
                if(j > 0 || stringIngresado[j] != 45)
                {
                    validado = 0;
                    printf("%s",mensajeError);
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
        limpiarMemoria();
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

/**
* \brief Toma una cadena y evalua si es un Dni (XX.XXX.XXX) o (X.XXX.XXX)
* \param pDocumento Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/

int utn_getDni( char *pDocumento, int limite, char *mensaje,
                char *mensajeError, int reintentos)
{
    int retorno=-1;
    char buffer[4096];
    if( pDocumento != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(buffer, limite) == 0 &&
                isValidDni(buffer, limite))
            {
                strncpy(pDocumento, buffer, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

/**
* \brief Toma una cadena y evalua si es un telefono fijo (4XXX-XXXX)
* \param pTelefono Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/

int utn_getTelefonoFijo(char *pTelefono, int limite, char *mensaje,
                        char *mensajeError, int reintentos)
{
    int retorno=-1;
    char buffer[4096];
    if( pTelefono != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(buffer, limite) == 0 &&
                isValidTelefonoFijo(buffer, limite))
            {
                strncpy(pTelefono, buffer, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

/**
* \brief Toma una cadena y evalua si puede ser un celular argentino (XX-XXXX-XXXX)
* \param pCelular Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/

int utn_getCelularArgentino(char *pCelular, int limite, char *mensaje,
                            char *mensajeError, int reintentos)
{
    int retorno=-1;
    char buffer[4096];
    if( pCelular != NULL && limite > 0 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            if( getString(buffer, limite) == 0 &&
                isValidCelularArgentino(buffer, limite))
            {
                strncpy(pCelular, buffer, limite);
                retorno = 0;
                break;
            }
            else
            {
                printf("\n%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}

/**
* \brief Toma una cadena y evalua si es una fecha valida (dd/mm/aaaa)
* \param pFecha Recibe el texto ingresado en caso de exito
* \param limite Es el tamano maximo del string
* \param mensaje Es el mensaje que se muestra al usuario antes de introducir datos
* \param mensajeError Es el mensaje que se muestra en caso de error
* \param reintentos Veces que el usuario podra volver a introducir el dato
* \return En caso de exito retorna 0, si no -1
*
*/

int utn_getFecha(   char *pFecha, int limite, char *mensaje,
                    char *mensajeError, int reintentos)
{
    int retorno=-1;
    char bufferDia[512];
    char bufferMes[512];
    char bufferAnio[512];
    int dia;
    int mes;
    int anio;
    if( pFecha != NULL && limite >= 11 && mensaje != NULL &&
        mensajeError != NULL && reintentos>=0)
    {
        do
        {
            reintentos--;
            printf("\n%s", mensaje);
            printf("\nIntroduzca Dia(dd): ");
            if( getString(bufferDia, limite) == 0 &&
                    strlen(bufferDia) == 2 &&
                    isValidEntero(bufferDia, limite))
            {
                dia = atoi(bufferDia);
            }
            else
            {
                continue;
            }
            printf("\nIntroduzca Mes(mm): ");
            if( getString(bufferMes, limite) == 0 &&
                    strlen(bufferMes) == 2 &&
                    isValidEntero(bufferMes, limite))
            {
                mes = atoi(bufferMes);
            }
            else
            {
                continue;
            }
            printf("\nIntroduzca Anio(aaaa): ");
            if( getString(bufferAnio, limite) == 0 &&
                    strlen(bufferAnio) == 4 &&
                    isValidEntero(bufferAnio, limite))
            {
                anio = atoi(bufferAnio);
            }
            else
            {
                continue;
            }
            if (isValidFecha(dia, mes, anio))
            {
                strncpy(pFecha, bufferDia,4);
                pFecha[2] = '/';
                strcat(pFecha, bufferMes);
                pFecha[5] = '/';
                strcat(pFecha, bufferAnio);
                pFecha[10] = '\0';
                retorno = 0;
                break;
            }
            else
            {
                printf("%s", mensajeError);
            }
        }
        while(reintentos>=0);
    }
    return retorno;
}





