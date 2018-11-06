#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pantalla.h"
#include "utn.h"
#include "contrataciones.h"


static int getNextId()// anda barbaro
{
    static int ultimoId=-1;
    ultimoId++;
    return ultimoId;
}

static int contratacion_getLugarLibre(Contratacion* array, int len)// anda barbaro
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            if(array[i].isEmpty)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}


int contratacion_init(Contratacion* array, int len)//inicializa todas las contrataciones en 1
{
    int retorno = -1;
    int i;
    if(array != NULL && len > 0)
    {
        for(i=0;i<len;i++)
        {
            array[i].isEmpty = 1;
        }
        retorno = 0;
    }
    return retorno;
}

void contratacion_mostrarByCuit(Contratacion* array, int len,char cuit[])
{
    int i;
    if(array != NULL && len > 0)//si el array que te mandaron de contrataciones tiene algo (por que es distinto de NULL)
    {
             fflush(stdin);
        //__fpurge(stdin);
        for(i=0;i<len;i++)//recorro todo el array de contrataciones hasta su largo.
        {
            if(!array[i].isEmpty && strncmp(array[i].cuit,cuit,14) == 0)//si el array de contrataciones que te mandaron en la posicion que esta i no esta en empty y el cuit es igual al cuit que le mandaste, entro.
            {
                printf("El ID de la contratacion es: %d \n",array[i].id);
                printf("El nombre de archivo de video de la contratacion es: %s \n",array[i].nombreVideo);
                printf("Los dias de la contratacion son: %d \n",array[i].dias);
                printf("El ID de la pantalla es: %d \n",array[i].pantallaId);
            }
                fflush(stdin);
            //__fpurge(stdin);
        }
    }

}

Contratacion* contratacion_getByPantalla(Contratacion* array,int len,int pantallaId)//supuestamente esto te devuelve un puntero de una contratacion pero por id de una pantalla??
{

    for(int i = 0; i < len; i++)
    {
        if(array[i].pantallaId == pantallaId)//pregunta si el array de contrataciones que vos le mandaste en el campo pantallaId es igual al id que vos le acabas de mandar de una pantalla
        {
//            printf("id contratacion es: %d esta vacio... %d dias %d nombre %s",array[i].id,array[i].isEmpty, array[i].dias,array[i].nombreVideo);

            return &array[i];//no estoy muy seguro pero creo que esto te retornaria una contratacion?
        }
    }
    return NULL;
}

int contratacion_alta(Contratacion* array,Pantalla* arrayPantalla, int len,int lenPantalla)//como el usuario antes de dar el alta de una contratacion tiene  que elejir la pantalla;se le pasa como parametro el array y el largo de la misma.
{
    int retorno = -1;
    int indice;
    char cuit[14];
    int dias;
    char nombreVideo[100];
    int idIngresado;//eto es para vincular la pantalla con la contratacion no ?

    if(utn_getNumero(&idIngresado,"Ingrese el id de la pantalla: ","Error,ingrese un id valido: ",0,10000,2)== -1)//le pedis el id de la pantalla la cual quiere hacer una contratacion
    {
        return retorno;
    }
    if(pantalla_getById(arrayPantalla,lenPantalla,idIngresado)!= NULL)//no me lo vas a creer pero no lo entendi muy bien....(estoy medio cansado igual)
    {
        if( array != NULL && len > 0 )
        {
           if(
                !utn_getCuit(cuit,"Ingrese cuit del cliente: ","\nNo es un cuit valido,reingrese: ",2) &&
                !utn_getNombre(nombreVideo,100,"Ingrese el nombre del archivo de video: ","\nNombre no valido,reingre el nombre:\n",2) &&
                !utn_getNumero(&dias,"Ingrese la duracion de la publicidad en dias: ","\nError reingrese el dia: ",1,365,2)
               )

            {
                indice = contratacion_getLugarLibre(array,len);//busca un lugar libre pero nose para que ? (estoy medio cansado igual)

               strncpy(array[indice].cuit,cuit,14);
                strncpy(array[indice].nombreVideo,nombreVideo,100);
                array[indice].dias = dias;
                array[indice].isEmpty = 0;
                array[indice].id = getNextId();
                array[indice].pantallaId = idIngresado;
                retorno = 0;

            }

        }

    }
    return retorno;
}

int contratacion_modificar(Contratacion* array, int len, Pantalla* arrayPantallas, int lenPantallas)
{
    int auxDias;
    char cuitIngresado[14];
    int retorno = -1;
    int idIngresado;
    Contratacion* contratacionElegida;

    utn_getCuit(cuitIngresado,"Ingrese el cuit del cliente: ","\nError ingrese un cuit valido: ",2);
    printf("CONTATACIONES DEL CLIENTE: %s ",cuitIngresado);

    contratacion_mostrarByCuit(array,len,cuitIngresado);//las contrataciones que tiene el cliente

    utn_getNumero(&idIngresado,"Ingrese el id de la pantalla: ","\nError,ingrese un id valido: ",0,10000,2);//tengo el id de la pantalla...

    contratacionElegida = contratacion_getByPantalla(array,len,idIngresado);
    if(contratacionElegida != NULL)
    {
        if(!utn_getNumero(&auxDias,"Ingrese la cantidad de dias de contratacion: ","\nError reingrese el dia: ",1,365,2))
        {
            contratacionElegida->dias = auxDias;
            retorno = 0;
        }

    }
        else
        {
            printf("El id de la pantalla no pertence al cuit ingresado");
        }
    return retorno;
}


int contratacion_baja(Contratacion* array, int len,Pantalla* arrayPantallas, int lenPantallas)
{
    int retorno = -1;
    char cuitIngresado[14];
    int idIngresado;
    Contratacion* contratacionElegida;

    utn_getCuit(cuitIngresado,"Ingrese el cuit del cliente: ","\nError ingrese un cuit valido: ",2);//ya le tome el cuit....
    printf("CONTATACIONES DEL CLIENTE: %s ",cuitIngresado);

    contratacion_mostrarByCuit(array,len,cuitIngresado);

    utn_getNumero(&idIngresado,"Ingrese el id de la pantalla: ","\nError,ingrese un id valido: ",0,10000,2);

    contratacionElegida = contratacion_getByPantalla(array,len,idIngresado);

     if(contratacionElegida != NULL && contratacionElegida->isEmpty == 0)
    {
        contratacionElegida->isEmpty = 1;
    }
    else
    {
        printf("El id de la pantalla no pertence al cuit ingresado");
    }
    return retorno;
}


void contratacion_mostrar(Contratacion* array, int len)
{
    Contratacion* contratacion;
    int idIngresado;


    if(utn_getNumero(&idIngresado,"Ingrese el id de la pantalla que tiene su contratacion: ","\nError reingrese un id correcto: ",0,1000,2) == -1)
    {
        return;
    }

    contratacion = contratacion_getByPantalla(array,len,idIngresado);//no anda por que no me toma el id por lo tanto no me trae la pantalla

    if(contratacion != NULL)
    {
        if(array != NULL && len > 0)
        {
            printf("\n El nombre del archivo video es: %s",contratacion->nombreVideo);
            printf("\n Los dias de duracion de la contratacion es: %d",contratacion->dias);
            printf("\n\n");
        }
    }
    fflush(stdin);
    //__fpurge(stdin);
}

void contratacion_mostrarTodo(Contratacion* array, int len)
{
         fflush(stdin);
    //__fpurge(stdin);

    for(int i = 0; i < len; i++)
    {
        if(array[i].isEmpty == 0)
        {
            printf("El ID de la contratacion es: %d\n",array[i].id);
            printf("El ID de la pantalla es: %d\n",array[i].pantallaId);
            printf("El nombre del archivo de video de la contratacion es: %s\n",array[i].nombreVideo);
            printf("Los dias de la contratacion son: %d\n",array[i].dias);
            printf("El CUIT del cliente  de esta contratacion es: %s\n",array[i].cuit);
        }
         printf("\n\n");
         fflush(stdin);
    //__fpurge(stdin);
    }
}

int cont_altaForzada(Contratacion* arrayContratacion,int lenArrayContratacion,
                     Pantalla* arrayPantallas, int lenPantallas,
                     int idPantalla,char* nombreVideo,char* cuit,int dias)
{
    int retorno = -1;
    int i;
    int posPant;
    if(lenArrayContratacion > 0 && arrayContratacion != NULL)
    {
        i = contratacion_getLugarLibre(arrayContratacion,lenArrayContratacion);
        if(i >= 0)
        {
            posPant = pantalla_buscarPorId(arrayPantallas,lenPantallas,idPantalla);
            if(posPant>=0)
            {
                arrayContratacion[i].dias = dias;
                strcpy(arrayContratacion[i].cuit,cuit);
                strcpy(arrayContratacion[i].nombreVideo,nombreVideo);
                //TODO
                arrayContratacion[i].pantallaId = idPantalla; // relacion
                arrayContratacion[i].isEmpty = 0;
                arrayContratacion[i].id = getNextId();
            }
        }
        retorno = 0;
    }
    return retorno;
}

