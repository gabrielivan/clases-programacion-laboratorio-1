
#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Employee* employee_new()
{
    Employee* this;
    this=malloc(sizeof(Employee));
    return this;
}

void employee_delete(Employee* this)
{
    free(this);
}

Employee* employee_newConParametros(char* idStr,char* nombre,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* this;
    this=employee_new();

    //FALTA VALIDAR
    int id = atoi(idStr);
    int horasTrabajadas = atoi(horasTrabajadasStr);
    int sueldo = atoi(sueldoStr);
    //FALTA VALIDAR

    if(
    !employee_setId(this,id)&&
    !employee_setNombre(this,nombre)&&
    !employee_setHorasTrabajadas(this,horasTrabajadas) &&
    !employee_setSueldo(this,sueldo)
    )
    {
         return this;
    }

    employee_delete(this);
    return NULL;
}

int employee_setId(Employee* this,int id)
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

int employee_getId(Employee* this,int* id)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *id=this->id;
        retorno=0;
    }
    return retorno;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(this->nombre,nombre);
        retorno=0;
    }
    return retorno;
}

int employee_getNombre(Employee* this,char* nombre)
{
    int retorno=-1;
    if(this!=NULL && nombre!=NULL)
    {
        strcpy(nombre,this->nombre);
        retorno=0;
    }
    return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
        retorno=0;
    }
    return retorno;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        this->sueldo=sueldo;
        retorno=0;
    }
    return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
    int retorno=-1;
    if(this!=NULL)
    {
        *sueldo=this->sueldo;
        retorno=0;
    }
    return retorno;
}

int employee_criterioSortNombre(void* thisA,void* thisB)
{
    char nombreA[100];
    char nombreB[100];
    int retorno = 0;



    employee_getNombre(thisA,nombreA);
    employee_getNombre(thisB,nombreB);


    if(strcmp(nombreA,nombreB) > 0)
    {
       // printf("\nMAYOR");
        retorno = 1;
    }
    else if(strcmp(nombreA,nombreB) < 0)
    {
       // printf("\nMENOR");
        retorno = -1;
    }

    return retorno;
}


