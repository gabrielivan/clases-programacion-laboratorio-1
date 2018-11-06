#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define CUITSTRINGLEN 14



int utn_getCuit(char* pResultado,
                char mensaje[],
                char mensajeError[],
                int  reintentos);

int main()
{
    char cuitIngresado[CUITSTRINGLEN];
    if(utn_getCuit(cuitIngresado,"ingrese un cuit: ","ingrese un cuit valido",3) == 0)
        printf("el cuit ingresado es: %s",cuitIngresado);
    else printf("flaco no sabes ingresar un cuit, que verguenza");
    return 0;
}

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
