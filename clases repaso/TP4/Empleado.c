#include "Empleado.h"
#include "LinkedList.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

/**
*\brief Reservar espacio en memoria para un elemento
*\param void
*\return Retorna el elemento si reserva memoria sino NULL
*/
Empleado* Empleado_new()
{
    Empleado* this;
    this=malloc(sizeof(Empleado));
    if(this!=NULL)
    {
        return this;
    }
    else
    {
        return NULL;
    }

}

/**
*\brief Libera espacio en memoria ocupado por elemento
*\param tihs Es el elemento
*\return Retorna 0 si logra liberar sino retorna -1
*/

int Empleado_delete(Empleado* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this);
        retorno = 0;
    }
    return retorno;
}

/**
*\brief Se realiza el alta de un elemento desde consola
*\param pArrayListEmpleado Es el array para ingresar elemento
*\return Retorna 0 si logra agregar elemento sino retorna -1
*/

Empleado* Empleado_newConParametros(char* id,char* nombre,char* apellido,char* sueldo,char* isEmpty)//lee desde el archivo
{
    Empleado* this;
    this = Empleado_new();
    int idClienteInt;
    int sueldoInt;
    char auxApellido[1024];
    char auxNombre[1024];
    char auxIsEmpty[1024];

    if(EsEntero(id,1024)&& EsNombre(auxApellido,1024) && EsEntero(sueldo,1024)&& EsNombre(nombre,1024)&& EsNombre(isEmpty,1024))
    {
        idClienteInt = atoi(id);
        sueldoInt = atoi(sueldo);
        strcpy(auxNombre,nombre);
        strcpy(auxApellido,apellido);
        strcpy(auxIsEmpty,isEmpty);

        if(
        !Empleado_setId(this,idClienteInt)&&
        !Empleado_setNombre(this,auxNombre)&&
        !Empleado_setSueldo(this,sueldoInt)&&
        !Empleado_setApellido(this,auxApellido)&&
        !Empleado_setIsEmpty(this,isEmpty))
            return this;
    }

    Empleado_delete(this);
    return NULL;
}

/**
*\brief Se setea el ID del elemento
*\param this Es el elemento
*\param id Es el ID para setear
*\return Retorna 0 si setea sino -1
*/

int Empleado_setId(Empleado* this,int id)
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

/**
*\brief Se obtiene el ID del elemento
*\param this Es el elemento
*\param id Es el ID que se obtiene
*\return Retorna 0 si obtiene sino retorna -1
*/

int Empleado_getId(Empleado* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int Empleado_setNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_setApellido(Empleado* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(this->apellido,apellido);
        retorno=0;
    }
    return retorno;
}

int Empleado_setIsEmpty(Empleado* this,char* isEmpty)
{
    int retorno=-1;
    if(this!=NULL && isEmpty!=NULL)
    {
        strcpy(this->isEmpty,isEmpty);
        retorno=0;
    }
    return retorno;
}

int Empleado_getNombre(Empleado* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int Empleado_getApellido(Empleado* this,char* apellido)
{
    int retorno=-1;
    if(this!=NULL && apellido!=NULL)
    {
        strcpy(apellido,this->apellido);
        retorno=0;
    }
    return retorno;
}

int Empleado_getIsEmpty(Empleado* this,char* isEmpty)
{
    int retorno=-1;
    if(this!=NULL && isEmpty!=NULL)
    {
        strcpy(isEmpty,this->isEmpty);
        retorno=0;
    }
    return retorno;
}

int Empleado_setSueldo(Empleado* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se obtiene el sueldo del elemento
*\param this Es el elemento
*\param sueldo Es el sueldo que se obtiene
*\return Retorna 0 si setea elemento sino retorna -1
*/

int Empleado_getSueldo(Empleado* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se recorre array para encontrar elemento por ID
*\param pArrayListEmployee Es el array para recorrer
*\param idIngresado Es ID para encontrar
*\return Retorna el elemento sino retorna NULL
*/
Empleado* Empleado_getById(void* listaEmpleados,int idIngresado)
{
    Empleado* retorno = NULL;
    int i;
    Empleado* auxEmpleado;
    int auxID = 0;

    if(listaEmpleados != NULL)
    {
        for(i=0;i<ll_len(listaEmpleados);i++)//Recorro todo el array hasta el LEN
        {
            auxEmpleado = ll_get(listaEmpleados,i);//Obtengo el elemento del array en posicion index
            Empleado_getId(auxEmpleado,&auxID);//Obtengo el ID del elemento
            if(auxID == idIngresado)
            {
                retorno = auxEmpleado;
                break;
            }
        }
    }
    return retorno;
}

int Empleado_getAll(Empleado* this,char* nombre,char* apellido,char* isEmpty,int* sueldo,int* id)
{
    int retorno = -1;

    if(this != NULL)
    {
        Empleado_getNombre(this,nombre);
        Empleado_getApellido(this,apellido);
        Empleado_getIsEmpty(this,isEmpty);
        Empleado_getSueldo(this,sueldo);
        Empleado_getId(this,id);
        retorno = 0;
    }
    return retorno;
}
