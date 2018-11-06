#include "Employee.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


static int isValidNombre(char *pBuffer, int limite)
{
    int retorno = 0;
    int cantidadEspacios = 0;
    int i;
    if( pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0 &&
        pBuffer[0]>='A' && pBuffer[0]<='Z')

    {
        retorno = 1;
        for(i=1; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(pBuffer[i]==' ' && cantidadEspacios == 0)
            {
                cantidadEspacios++;
            }
            else if(!(pBuffer[i] >= 'a' && pBuffer[i] <= 'z' && pBuffer[i-1] != ' ') &&
                    !(pBuffer[i] >= 'A' && pBuffer[i] <= 'Z' && pBuffer[i-1] == ' '))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

static int isValidEnteroSoloNumeros(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    if (pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0)
    {
        retorno = 1;
        for(i=0; i < limite && pBuffer[i] != '\0'; i++)
        {
            if (!(pBuffer[i]>='0' && pBuffer[i]<='9'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

static int isValidFloatPositivo(char *pBuffer, int limite)
{
    int retorno = 0;
    int i;
    int contadorDePuntos = 0;
    if  ((pBuffer != NULL && limite > 0 && strlen(pBuffer) > 0) &&
            (( pBuffer[0] == '+' && pBuffer[1] != '.') ||
            (pBuffer[0]>='0' && pBuffer[0]<='9')))
    {
        retorno = 1;
        for(i=1; i < limite && pBuffer[i] != '\0'; i++)
        {
            if(pBuffer[i]=='.' && contadorDePuntos==0)
            {
                contadorDePuntos++;
            }
            else if (!(pBuffer[i]>='0' && pBuffer[i]<='9'))
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}



Employee* Employee_new()
{
    Employee* this;
    this=malloc(sizeof(Employee));
    return this;
}

void Employee_delete(Employee* this)
{
    free(this);
}

Employee* Employee_newConParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo)
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

int Employee_mostrarEmpleado(Employee* this)
{
    int retorno = -1;

    char nombre[64];
    int id;
    int horasTrabajadas;
    int sueldo;

    Employee_getNombre(this,nombre);
    Employee_getId(this,&id);
    Employee_getSueldo(this,&sueldo);
    Employee_getHorasTrabajadas(this,&horasTrabajadas);

    printf("\nEl ID del empleado es: %d",id);
    printf("\nEl nombre del empleado es: %s",nombre);
    printf("\nEl sueldo del empleado es: %d",sueldo);
    printf("\nLas horas trabajadas del empleado fueron: %d",horasTrabajadas);
    printf("\n\n");

    retorno = 0;

    return retorno;
}

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
