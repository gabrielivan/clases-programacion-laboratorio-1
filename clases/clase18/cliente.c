
#include "cliente.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

static int isValidApellido(char* pBuffer,int limite)
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

Cliente* cliente_new()
{
    Cliente* this;
    this=malloc(sizeof(Cliente));
    return this;
}

void cliente_delete(Cliente* this)
{
    free(this);
}

Cliente* cliente_newConParametros(char* nombre,int lenNombre,char* apellido,int lenApellido,int id,int isEmpty)
{
    Cliente* this;
    this=cliente_new();

    if(
    !cliente_setNombre(this,nombre,lenNombre)&&
    !cliente_setApellido(this,apellido,lenApellido)&&
    !cliente_setId(this,id)&&
    !cliente_setIsEmpty(this,isEmpty))
        return this;

    cliente_delete(this);
    return NULL;
}

int cliente_setNombre(Cliente* this,char* nombre,int lenNombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL && isValidNombre(nombre,lenNombre))
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int cliente_getNombre(Cliente* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int cliente_setApellido(Cliente* this,char* apellido,int lenApellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL && isValidApellido(apellido,lenApellido))
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}

int cliente_getApellido(Cliente* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(apellido,this->apellido);
        retorno=0;
    }
    return retorno;
}

int cliente_setId(Cliente* this,int id)
{
    int retorno=-1;
    static int proximoId=-1;

    if(this!=NULL && id==-1)
    {
        proximoId++;
        this->id=proximoId;
        retorno=0;
    }
    else if(id>proximoId)
    {
        proximoId=id;
        this->id=proximoId;
        retorno=0;
    }
    return retorno;
}

int cliente_getId(Cliente* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int cliente_setIsEmpty(Cliente* this,int isEmpty)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->isEmpty=isEmpty;
        retorno=0;
    }
    return retorno;
}

int cliente_getIsEmpty(Cliente* this,int* isEmpty)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *isEmpty=this->isEmpty;
        retorno=0;
    }
    return retorno;
}

