#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;
    pArchivo = fopen(path,"r");
    if(!parser_EmployeeFromText(pArchivo,pArrayListEmployee))
    {
        printf("\nArchivo cargado correctamente!\n");
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo;
    int retorno = -1;
    pArchivo = fopen(path,"rb");
    if(!parser_EmployeeFromBinary(pArchivo,pArrayListEmployee))
    {
        printf("\nArchivo cargado");
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int sueldo;
    int horasTrabajadas;
    char nombre[64];
    if(!utn_getNumero(&sueldo,"Ingrese el sueldo: ","Error,reingrese el sueldo: ",0,99999,2)&&
    !utn_getNumero(&horasTrabajadas,"\nIngrese las horas: ","Error,reingrese las horas: ",0,99999,2)&&
    !utn_getNombre(nombre,64,"\nIngrese el nombre: ","Error,reingrese el nombre: ",2))
    {
        Employee* empleado = Employee_new_AI(nombre,horasTrabajadas,sueldo);
        if(empleado != NULL)
        {
            retorno = ll_add(pArrayListEmployee,empleado);
        }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int id, idAux;
    Employee* empleado;
     int sueldo;
    int horasTrabajadas;
    char nombre[64];

    if(pArrayListEmployee != NULL)
    {
        if(!utn_getNumero(&id,"Ingrese el ID del empleado a modificar: ","Error",0,99999,2))
        {
            for(i = 0;i< ll_len(pArrayListEmployee);i++)
            {
               empleado = ll_get(pArrayListEmployee,i);
               Employee_getId(empleado,&idAux);
               if(idAux == id)
               {
                    if(!utn_getNumero(&sueldo,"Ingrese el nuevo sueldo: ","Error",0,99999,2)&&
                    !utn_getNumero(&horasTrabajadas,"Ingrese las nuevas horas: ","Error",0,99999,2)&&
                    !utn_getNombre(nombre,64,"Ingrese el nuevo nombre: ","Error",2))
                    {
                        if(
                          !Employee_setNombre(empleado, nombre)&&
                          !Employee_setSueldo(empleado, sueldo)&&
                          !Employee_setHorasTrabajadas(empleado, horasTrabajadas))
                          {
                            retorno = 0;
                            break;
                          }

                    }
                    else{
                        break;
                    }
               }
            }
        }

    }
    return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    int id, idAux;
    Employee* empleado;

    if(pArrayListEmployee != NULL)
    {
        if(!utn_getNumero(&id,"Ingrese el ID del empleado a borrar: ","Error",0,99999,2))
        {
            for(i = 0;i< ll_len(pArrayListEmployee);i++)
            {
               empleado = ll_get(pArrayListEmployee,i);
               Employee_getId(empleado,&idAux);

               if(idAux == id)
               {
                    Employee_delete(empleado);
                    ll_remove(pArrayListEmployee,i);
                    retorno = 0;
                    break;
               }

            }
        }

    }
    return retorno;
}

/** \brief Listar empleados
 * \param pArrayListEmployee LinkedList* es el array a ser reccorrido
 * \return retorna -1 en caso de error sino retorna 0
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i;
    char nombre[128];
    int id;
    int sueldo;
    int horasTrabajadas;
    Employee* auxPunteroEmpleado;

    if(pArrayListEmployee != NULL)
    {
        retorno = 0;
        for(i=0;i < ll_len(pArrayListEmployee);i++)
        {
            auxPunteroEmpleado = ll_get(pArrayListEmployee,i);
            Employee_getNombre(auxPunteroEmpleado,nombre);
            Employee_getId(auxPunteroEmpleado,&id);
            Employee_getSueldo(auxPunteroEmpleado,&sueldo);
            Employee_getHorasTrabajadas(auxPunteroEmpleado,&horasTrabajadas);

            printf("\nEl nombre del empleado es: %s",nombre);
            printf("\nEl id del empleado es: %d",id);
            printf("\nEl sueldo del empleado es: %d",sueldo);
            printf("\nLas horas trabajadas del empleado son: %d",horasTrabajadas);
            printf("\n\n");

        }
    }
    return retorno;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int retorno = -1;

    if(pArrayListEmployee != NULL)
    {
        if(!ll_sort(pArrayListEmployee,Employee_criterioSortNombre,1))
        {
            retorno = 0;
        }
    }

    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = fopen(path,"w");
    int retorno = -1;

    if(pArchivo != NULL && !parser_SaveToText(pArchivo,pArrayListEmployee))
    {
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pArchivo = fopen(path,"wb");
    int retorno = -1;
    if(pArchivo != NULL && !parser_SaveToBinary(pArchivo,pArrayListEmployee))
    {
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

