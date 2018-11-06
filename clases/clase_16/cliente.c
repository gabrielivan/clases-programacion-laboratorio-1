#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

static int isValidNombre(char* nom)
{
    //utn.h
    return 1;
}

int cliente_getNombre(Cliente* this,char* nom)
{
    if(this!=NULL && nom!=NULL)
    {
        strncpy(nom,this->nombre,sizeof(this->nombre));
        return 0;
    }
    return 1;
}



Cliente* cliente_newCliente(void)
{
    return (Cliente*)malloc(sizeof(Cliente));
}

//Cliente* cliente_newClienteParametros(char* nombre, char* apellido, int* id)
//{
//    Cliente* p;
//    cliente_newCliente();
//    if(p!=NULL)
//    {
//        if( setNombre(p,nombre)==-1 ||
//            setApellido(p,apellido)==-1 ||
//            serId(p,id)==-1)
//            {
//                //mal!
//                cliente_deleteCliente(p);
//                p = NULL;
//            }
//    }
//    return p;
//}

int cliente_setNombre(Cliente* this,char* nom)
{
    if(this != NULL && isValidNombre(nom))
    {
        strncpy(this->nombre,nom,sizeof(this->nombre));
        return 0;
    }
    return 1;
}

int cliente_buscarLugarVacio(Cliente* array[],int len)
{
    int i;
    int retorno = -1;

    if(array!=NULL)
    {
        for(i=0; i<len; i++)
        {
            if(array[i] == NULL)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int cliente_inicializarArray(Cliente* array[],int len)
{
    int i;
    int retorno = -1;

    if(array!=NULL)
    {
        retorno = 0;
        for(i=0; i<len; i++)
        {
            array[i] = NULL;
        }

    }
    return retorno;
}

int cliente_buscarPorId(Cliente* array[],int len,int id)
{
    int i;
    int retorno = -1;
    Cliente* aux;
    for(i=0; i<len; i++)
    {
       aux = array[i];
       if(aux!=NULL && aux->id == id)
       {
            retorno = i;
            break;
       }
    }
    return retorno;
}

int cliente_deleteCliente(Cliente* this)
{
    int retorno = -1;
    if(this!=NULL)
    {
        free((void*)this);
        retorno = 0;
    }
    return retorno;
}
