//#include <stdio_ext.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 500
#include "utn.h"
#define CUITSTRINGLEN 14


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
        fflush(stdin);
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
*\brief solicita un nombre al usuario,valida y devuelve el resultado
*\param pResultado Puntero a la variable resultado
*\param mensaje es el mensaje a ser mostrado
*\param mensajeError es el mensaje a ser mostrado en caso de error
*\param reintentos es la cantidad de reintentos que tiene el usuario
*\return en caso de exito retorna 0 y en caso de error -1
*
*/

int utn_getNombre(char* pResultado,
                    char mensaje[],
                    char mensajeError[],
                    int  reintentos)
{
   char stringIngresado[STRINGLEN];
   int validado = 1;

   printf("%s",mensaje);

   for(int i = 0;i<reintentos;i++)
   {
       validado = 1;
       fflush(stdin);
       fgets(stringIngresado, STRINGLEN, stdin);

       for (int j=0; j<strlen(stringIngresado)-1; j++)
       {
            if (stringIngresado[j] < 'A' || stringIngresado[j] > 'z')
            {
                validado = 0;
                break;
            }

            if (stringIngresado[j] > 'Z' && stringIngresado[j] < 'a')
            {
                validado = 0;
                break;
            }

       }

       if(validado == 1)
       {
            strcpy(pResultado,stringIngresado);
            return 0;

       }
       else
       {
           printf("%s",mensajeError);
       }

   }

    return -1;

}


/**
*\brief solicita un nombre al usuario,valida y devuelve el resultado
*\param pResultado Puntero a la variable resultado
*\param mensaje es el mensaje a ser mostrado
*\param mensajeError es el mensaje a ser mostrado en caso de error
*\param reintentos es la cantidad de reintentos que tiene el usuario
*\return en caso de exito retorna 0 y en caso de error -1
*
*/


int utn_getNombreTitle(char*pNombre,
                       char mensaje[],
                       char mensajeError[])

{
    int retorno;
    int i;
    int is_not_valid_name;
    char auxiliar[LEN];

    printf("%s",mensaje);
    do {
        fgets(auxiliar,LEN,stdin);
        for (i=0;i<strlen(auxiliar)-1;i++)
        {
            auxiliar[i] = tolower(auxiliar[i]);
            if ((auxiliar[i]<'a' || auxiliar[i]>'z') && auxiliar[i] != ' ')
            {
                is_not_valid_name = -1;
                break;
            }
            else
            {
                if (i == 0 || auxiliar[i-1] == ' ')
                {
                    auxiliar[i] = toupper(auxiliar[i]);
                }
                is_not_valid_name = 0;
                retorno = 0;
            }
        }
    } while (is_not_valid_name);

    strcpy(pNombre, auxiliar);
    return retorno;
}

/**
*\brief solicita un mail al usuario,valida y devuelve el resultado
*\param email Puntero a la variable resultado
*\param mensaje es el mensaje a ser mostrado
*\param mensajeError es el mensaje a ser mostrado en caso de error
*\return en caso de exito retorna 0 y en caso de error -1
*
*/






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
        fflush(stdin);
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

int getEmail(char*email)
{
    int retorno = -1;
    int indexArroba = -1, i, indexPunto = -1;
    char auxiliar[STRINGLEN];

    fgets(auxiliar,STRINGLEN,stdin);

    if (email != NULL && strlen(auxiliar) <= STRINGLEN && strlen(auxiliar) > 0)
    {
        for (i=0; i<strlen(auxiliar)-1; i++)
        {
            if (auxiliar[i] == ' ')
            {
                retorno = -1;
                break;
            }
            if (i==0 && (auxiliar[i] == '@' || auxiliar[i] == '.'))
            {
                retorno = -1;
                break;
            }
            if (auxiliar[i] == '@')
            {
                if (indexArroba == -1)
                {
                    indexArroba = i;
                }
                else
                {
                    retorno = -1;
                    break;
                }
            }
            if (auxiliar[i] == '.' && indexArroba != -1)
            {
                indexPunto = i;
            }
            if (indexArroba != -1 && indexPunto == -1 && auxiliar[i] != '@')
            {
                if (auxiliar[i] < 'a' || auxiliar[i] > 'z')
                {
                    retorno = -1;
                    break;
                }
            }
        }
        if (indexArroba == -1 || indexPunto == -1)
        {
            retorno = -1;
        }
        else
        {
            strcpy(email, auxiliar);
            retorno = 0;
        }
    }

    return retorno;
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
    char stringIngresado[CUITSTRINGLEN];//aca se guarda lo que ingreso como string
    int validado = 1;//true

    printf("%s",mensaje);

     for(int i = 0;i<reintentos;i++)
    {
        validado = 1;
        fflush(stdin);
        fgets(stringIngresado, CUITSTRINGLEN + 2, stdin);//pido un string con limite de caracters para un cuit CUITSTRINGLEN
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
*\brief valida un dni y devuelve el resultado
*\param array Puntero a la variable,size el largo del array
*\return en caso de exito retorna 0 y en caso de error -1
*
*/

int validacion_DNI(char* array,int size)
{
   int i=0;
   int retorno = 0;
   int contadorSimbolos = 0;
   int digitosIngresados;

   digitosIngresados = strlen(array);

   if(array != NULL && size > 0)
   {
       retorno = 1;
       for(i=0;i < size && array[i] != '\0';i++)
       {
            if(array[i] < '0' || array[i] > '9'|| array[i] != '.')
            {
                if(array[2] != '.' || array[6] != '.' || contadorSimbolos > 2 || digitosIngresados < 10)
                {
                retorno = 0;
                break;
                }
            }

            if(array[i] == '.')
            {
                contadorSimbolos++;
            }
       }
   }
   return retorno;
}

/**
*\brief solicita un dni al usuario,valida y devuelve el resultado
*\param input array a validar,size el largo del array
*\param mensaje es el mensaje a ser mostrado
*\param mensajeError es el mensaje a ser mostrado en caso de error
*\param reintentos es la cantidad de reintentos que tiene el usuario
*\return en caso de exito retorna 0 y en caso de error -1
*
*/

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

/**
*\brief valida un string y devuelve el resultado
*\param input es el string a validar,size el largo del string
*\return en caso de exito retorna 0 y en caso de error -1
*
*/

int input_getString(char mensaje[],int size,char input[])
{
    int retorno = -1;
    char buffer[size];
    int length;

    do
    {
        fflush(stdin);
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
