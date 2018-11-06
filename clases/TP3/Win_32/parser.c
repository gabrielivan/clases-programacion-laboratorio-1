#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char bufferInt[1024];
    char bufferNombre[1024];
    char bufferHorasTrabajadas[1024];
    char bufferSueldo[1024];
    int retorno = -1;
    int flagOnce = 1;
    Employee* pEmpleado;

    if(pFile!= NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce)
            {
               flagOnce = 0;
               fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                                                bufferInt,
                                                bufferNombre,
                                                bufferHorasTrabajadas,
                                                bufferSueldo);
            }
             fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",
                                                bufferInt,
                                                bufferNombre,
                                                bufferHorasTrabajadas,
                                                bufferSueldo);


            pEmpleado = Employee_newConParametros(  bufferInt,
                                                    bufferNombre,
                                                    bufferHorasTrabajadas,
                                                    bufferSueldo);

            if(pEmpleado != NULL)
            {
                retorno = 0;
                ll_add(pArrayListEmployee,pEmpleado);
            }

        }
    }
    return retorno;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* pEmpleado;

    if(pFile != NULL)
    {
        retorno = 0;
        while(!feof(pFile))
        {
            pEmpleado = Employee_new();
            fread(pEmpleado,sizeof(Employee),1,pFile);
            ll_add(pArrayListEmployee,pEmpleado);
        }

    }

    return retorno;
}

int parser_SaveToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Employee* auxEmployee;
    int len;
    int i;
    int bufferId;
    char bufferNombre[1000];
    int bufferHorasTrabajadas;
    int bufferSueldo;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);

        for(i=0;i<len;i++)
        {
            auxEmployee = ll_get(pArrayListEmployee,i);
            Employee_getAll(auxEmployee,bufferNombre,&bufferHorasTrabajadas,&bufferSueldo,&bufferId);
            fprintf(pFile,"%d,%s,%d,%d\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
            retorno = 0;
        }
    }
    return retorno;
}

int parser_SaveToBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    int i = 0;
    int len;
    Employee* auxEmployee;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);
        while(i != len)
        {
            auxEmployee = ll_get(pArrayListEmployee,i);
            fwrite(auxEmployee,sizeof(Employee*),1,pFile);
            retorno = 0;
            i++;
        }
    }
    return retorno;
}
