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

void contratacion_mostrarByCuit(Contratacion* array, int len,char cuit[])//esto no lo entendi muy bien pero supongo que te retorna una contratacion apartir de un cuit que vos le mandas esto siempre y cuando el cuit coincidad con uno existente y halla algo en contrataciones
{
    int i;
    if(array != NULL && len > 0)//si el array que te mandaron de contrataciones tiene algo (por que es distinto de NULL)
    {
        for(i=0;i<len;i++)//recorro todo el array de contrataciones hasta su largo ...?
        {
            if(!array[i].isEmpty && strncmp(array[i].cuit,cuit,14) == 0)//si el array de contrataciones que te mandaron en la posicion que esta i no esta en empty y el cuit es igual al cuit que le mandaste entro.
            {
                printf("id contratacion es: %d esta vacio... %d dias %d nombre %s id de pantalla: %d",array[i].id,array[i].isEmpty, array[i].dias,array[i].nombreVideo, array[i].pantallaId);
            }
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

    utn_getCuit(cuitIngresado,"Ingrese el cuit del cliente: ","\nError ingrese un cuit valido: ",2);//ya le tome el cuit....
    printf("CONTATACIONES DEL CLIENTE %s ...",cuitIngresado);
    contratacion_mostrarByCuit(array,len,cuitIngresado);//las contrataciones que tiene el cliente

    utn_getNumero(&idIngresado,"Ingrese el id de la pantalla: ","\nError,ingrese un id valido: ",0,10000,2);//tengo el id de la pantalla...

    contratacionElegida = contratacion_getByPantalla(array,len,idIngresado);//no entendi muy bien esto.... sorry
    if(contratacionElegida != NULL)
    {
    //Luego de ingresar el ID de la pantalla,se permitirá modificar la cantidad de días contratados para la misma.
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


int contratacion_baja(Contratacion* array, int len, char cuit[], Pantalla* arrayPantallas, int lenPantallas)
{
    int retorno = -1;
    int idIngresado;
    char cuitIngresado[14];


    if(utn_getCuit(cuitIngresado,"Ingrese su cuit: ","\nError ingrese un cuit valido: ",2) == 0)//ya tengo el cuit..
    {
        //se listaran todas las pantallas de video que el cliente tiene contratadas mostrando todos sus campos.?????
    }
     utn_getNumero(&idIngresado,"Ingrese el id de la pantalla: ","\nError,ingrese un id valido",0,10000,2);//tengo el id de la pantalla...
        //ACA HAY UN PROBLEMA PORQUE CUANDO QUIERO DAR DE BAJA LA PANTALLA INGRESANDO MI CUIT Y EL ID DE LA PANTALLA
        //QUE YO TENGO CONTRATADA ME DICE QUE NO TENGO NINGUNA CONTRATACION HECHA,Y ES MENTIRA POR QUE ACABO DE HACER UNA.
        if(array != NULL && len > 0 &&
           array->isEmpty == 0)
        {
            array->isEmpty = 1;
            retorno = 0;
        }
        else
        {
            printf("\nNo hay contratacion.");
        }

        return retorno;

    }

//QUEDE CANSADICIMO SUFICIENTE POR EL DIA DE HOY ESPEREMOS QUE CRISTIAN NOS AYUDE EN ESTO POR QUE SINO VAMOS Y HACEMOS UN CURSO DE PASTELERIA .


void contratacion_mostrar(Contratacion* array, int len)//no funca por que no reconoce el id de la pantalla que le paso....
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
    for(int i = 0; i < len; i++)
    {
        if(array[i].isEmpty == 0)
        {
            printf("id contratacion es: %d esta vacio... %d dias %d nombre %s id de pantalla: %d",array[i].id,array[i].isEmpty, array[i].dias,array[i].nombreVideo, array[i].pantallaId);

        }
    }
}
