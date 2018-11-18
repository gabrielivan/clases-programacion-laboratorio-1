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

Empleado* Empleado_newConParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo)//lee desde el archivo
{
    Empleado* this;
    this = Empleado_new();
    int idClienteInt;
    int horasTrabajadasInt;
    int sueldoInt;
    char auxNombre[1024];

    if(EsEntero(id,1024)&& EsEntero(horasTrabajadas,1024)&& EsEntero(sueldo,1024)&& EsNombre(nombre,1024))
    {
        idClienteInt = atoi(id);
        horasTrabajadasInt = atoi(horasTrabajadas);
        sueldoInt = atoi(sueldo);
        strcpy(auxNombre,nombre);
        if(
        !Empleado_setId(this,idClienteInt)&&
        !Empleado_setNombre(this,auxNombre)&&
        !Empleado_setHorasTrabajadas(this,horasTrabajadasInt)&&
        !Empleado_setSueldo(this,sueldoInt))
            return this;
    }

    Empleado_delete(this);
    return NULL;
}

/**
*\brief Se realiza el alta de un elemento desde consola
*\param pArrayListEmpleado Es el array para ingresar elemento
*\return Retorna 0 si logra agregar elemento sino retorna -1
*/

Empleado* Empleado_new_AI(char* nombre,int horasTrabajadas,int sueldo)//este no lee de un archivo
{
    Empleado* this;
    this = Empleado_new();

    if(
    !Empleado_setId(this,-1)&&
    !Empleado_setNombre(this,nombre)&&
    !Empleado_setHorasTrabajadas(this,horasTrabajadas)&&
    !Empleado_setSueldo(this,sueldo))
        return this;

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

/**
*\brief Se setea el nombre del elemento
*\param this Es el elemento
*\param nombre Es el nombre para setear
*\return Retorna 0 si setea elemento sino retorna -1
*/

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

/**
*\brief Se obtiene el nombre del elemento
*\param this Es el elemento
*\param nombre Es el nombre que se obtiene
*\return Retorna 0 si obtiene elemento sino retorna -1
*/

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

/**
*\brief Se setea las horas trabajadas del elemento
*\param this Es el elemento
*\param horasTrabajadas Es la cantidad de horas para setear
*\return Retorna 0 si setea elemento sino retorna -1
*/

int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas)
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

int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas)
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
*\brief Base de funcion criterio para comparar campos de dos elementos
*\param thisA Es el primer elemento
*\param thisB Es el segundo elemento
*\return Retorna 1 si el primer elemento es mayor al segundo,
*\       retorna -1 si el, sino retorna 0
*/

int Empleado_criterioSortNombre(void* thisA,void* thisB)
{
    int retorno = 0;
    char nombreA[50];
    char nombreB[50];

   Empleado_getNombre(thisA,nombreA);
   Empleado_getNombre(thisB,nombreB);

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

int Empleado_getAll(Empleado* this,char* nombre,int* horas,int* sueldo,int* id)
{
    int retorno = -1;

    if(this != NULL)
    {
        Empleado_getNombre(this,nombre);
        Empleado_getHorasTrabajadas(this,horas);
        Empleado_getSueldo(this,sueldo);
        Empleado_getId(this,id);
        retorno = 0;
    }
    return retorno;
}


int Empleado_calcularSueldo(void* pEmpleado)
{
    int retorno = -1;
    int cantidadHoras;
    int auxSueldo;
    int sueldo;

    if(pEmpleado != NULL)
    {
        Empleado_getHorasTrabajadas(pEmpleado,&cantidadHoras);

        if(cantidadHoras < 120)
        {
            auxSueldo = cantidadHoras * 180;
            sueldo = auxSueldo;
            Empleado_setSueldo(pEmpleado,sueldo);
        }
        else if(cantidadHoras > 120 && cantidadHoras < 160)
        {
            auxSueldo = cantidadHoras * 240;
            sueldo = auxSueldo;
            Empleado_setSueldo(pEmpleado,sueldo);
        }
        else if(cantidadHoras > 160 && cantidadHoras < 240)
        {
            auxSueldo = cantidadHoras * 350;
            sueldo = auxSueldo;
            Empleado_setSueldo(pEmpleado,sueldo);
        }
    }
    retorno = 0;

    return retorno;
}

/**
*\brief Se muestran los datos de todos los campos del elemento
*\param this Es el puntero al elemento
*\return Retorna 0 si el elemento es diferente a NULL sino retorna -1
*/

int Empleado_mostrar(void* pEmpleado)
{
    int retorno = -1;
    int auxId;
    char auxNombre[128];
    int auxHorasTrabajadas;
    int auxSueldo;

    if(pEmpleado != NULL)
    {
        Empleado_getId(pEmpleado,&auxId);
        if(auxId != -1)
        {
            Empleado_getNombre(pEmpleado,auxNombre);
            Empleado_getSueldo(pEmpleado,&auxSueldo);
            Empleado_getHorasTrabajadas(pEmpleado,&auxHorasTrabajadas);
            Empleado_getId(pEmpleado,&auxId);

            printf("\nID: %d",auxId);
            printf("\nNombre: %s",auxNombre);
            printf("\nSueldo: %d",auxSueldo);
            printf("\nHoras trabajadas: %d\n",auxHorasTrabajadas);
            retorno = 0;
        }
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
