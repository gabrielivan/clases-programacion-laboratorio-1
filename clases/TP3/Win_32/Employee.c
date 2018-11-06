#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
*\brief Reservar espacio en memoria para un elemento
*\param void
*\return Retorna el elemento si reserva memoria sino NULL
*/
Employee* Employee_new()
{
    Employee* this;
    this=malloc(sizeof(Employee));
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

int Employee_delete(Employee* this)
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
*\param pArrayListEmployee Es el array para ingresar elemento
*\return Retorna 0 si logra agregar elemento sino retorna -1
*/

Employee* Employee_newConParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo)//lee desde el archivo
{
    Employee* this;
    this = Employee_new();

    int idClienteInt = atoi(id);
    int horasTrabajadasInt = atoi(horasTrabajadas);
    int sueldoInt = atoi(sueldo);

    if(
    !Employee_setId(this,idClienteInt)&&
    !Employee_setNombre(this,nombre)&&
    !Employee_setHorasTrabajadas(this,horasTrabajadasInt)&&
    !Employee_setSueldo(this,sueldoInt))
        return this;

    Employee_delete(this);
    return NULL;
}

/**
*\brief Se realiza el alta de un elemento desde consola
*\param pArrayListEmployee Es el array para ingresar elemento
*\return Retorna 0 si logra agregar elemento sino retorna -1
*/

Employee* Employee_new_AI(char* nombre,int horasTrabajadas,int sueldo)//este no lee de un archivo
{
    Employee* this;
    this = Employee_new();

    if(
    !Employee_setId(this,-1)&&
    !Employee_setNombre(this,nombre)&&
    !Employee_setHorasTrabajadas(this,horasTrabajadas)&&
    !Employee_setSueldo(this,sueldo))
        return this;

    Employee_delete(this);
    return NULL;
}

/**
*\brief Se setea el ID del elemento
*\param this Es el elemento
*\param id Es el ID para setear
*\return Retorna 0 si setea sino -1
*/

int Employee_setId(Employee* this,int id)
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

int Employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se setea el nombre del elemento
*\param this Es el elemento
*\param nombre Es el nombre para setear
*\return Retorna 0 si setea elemento sino retorna -1
*/

int Employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se obtiene el nombre del elemento
*\param this Es el elemento
*\param nombre Es el nombre que se obtiene
*\return Retorna 0 si obtiene elemento sino retorna -1
*/

int Employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se setea las horas trabajadas del elemento
*\param this Es el elemento
*\param horasTrabajadas Es la cantidad de horas para setear
*\return Retorna 0 si setea elemento sino retorna -1
*/

int Employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se obtienen las horas trabajadas del elemento
*\param this Es el elemento
*\param horasTrabajadas Es la cantidad de horas que se obtiene
*\return Retorna 0 si setea elemento sino retorna -1
*/

int Employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

/**
*\brief Se setea el sueldo del elemento
*\param this Es el elemento
*\param sueldo Es el sueldo para setear
*\return Retorna 0 si setea elemento sino retorna -1
*/

int Employee_setSueldo(Employee* this,int sueldo)
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

int Employee_getSueldo(Employee* this,int* sueldo)
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
*\brief Base de funcion criterio para comparar campos de dos elementos
*\param thisA Es el primer elemento
*\param thisB Es el segundo elemento
*\return Retorna 1 si el primer elemento es mayor al segundo,
*\       retorna -1 si el, sino retorna 0
*/

int Employee_criterioSortNombre(void* thisA,void* thisB)
{
    int retorno = 0;
    char nombreA[50];
    char nombreB[50];

   Employee_getNombre(thisA,nombreA);
   Employee_getNombre(thisB,nombreB);

   if(strcmp(nombreA,nombreB)>0)
   {
    retorno = 1;
   }
   else if(strcmp(nombreA,nombreB)< 0)
   {
    retorno = -1;
   }

    return retorno;
}

int Employee_getAll(Employee* this,char* nombre,int* horas,int* sueldo,int* id)
{
    int retorno = -1;

    if(this != NULL)
    {
        Employee_getNombre(this,nombre);
        Employee_getHorasTrabajadas(this,horas);
        Employee_getSueldo(this,sueldo);
        Employee_getId(this,id);
        retorno = 0;
    }
    return retorno;
}

