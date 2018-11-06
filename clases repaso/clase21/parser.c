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
    int flagOnce=1;
    Employee * pEmpleado;


    if(pFile != NULL)
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
            //printf("\n%s",bufferNombre);

            pEmpleado = employee_newConParametros(
                                        bufferInt,
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
            pEmpleado = employee_new();
            fread(pEmpleado,sizeof(Employee),1,pFile);
            printf("----%s*****",pEmpleado->nombre);
            //ll_add(pArrayListEmployee,pEmpleado);
        }

    }
    return retorno;
}
