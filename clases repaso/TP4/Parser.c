#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empleado.h"

/** \brief Parsea los datos de los empleados desde el archivo data.csv (modo texto).
 * \param FILE* pFile Puntero del tipo file al archivo para parsear
 * \param pArrayListEmployee LinkedList* lista donde se van a a guardar los empleados
 * \return en caso de exito retorna 0 y en caso de error retorna -1
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    char bufferId[1024];
    char bufferNombre[1024];
    char bufferApellido[1024];
    char bufferSueldo[1024];
    char bufferIsEmpty[1024];
    int retorno = -1;
    int flagOnce = 1;
    Empleado* pEmpleado;

    if(pFile!= NULL)
    {
        while(!feof(pFile))
        {
            if(flagOnce)
            {
               flagOnce = 0;
               fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
                                                bufferId,
                                                bufferNombre,
                                                bufferApellido,
                                                bufferIsEmpty,
                                                bufferSueldo);
            }
             fscanf(pFile,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",
                                                bufferId,
                                                bufferNombre,
                                                bufferApellido,
                                                bufferIsEmpty,
                                                bufferSueldo);

            pEmpleado = Empleado_newConParametros(  bufferId,
                                                    bufferNombre,
                                                    bufferApellido,
                                                    bufferIsEmpty,
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

/** \brief Parsea los datos del linked list al archivo data.csv (modo texto).
 *
 * \param pFile Es el puntero a archivo para escribir los datos
 * \param pArrayListEmployee Es la LinkedList de donde se toman los datos
 * \return Retorna 0 si existe el archivo y el LinkedList sino retorna -1
 *
 */

int parser_SaveToText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int retorno = -1;
    Empleado* auxEmployee;
    int len;
    int i;
    int bufferId;
    char bufferNombre[1000];
    char bufferApellido[1000];
    char bufferIsEmpty[1000];
    int bufferSueldo;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        len = ll_len(pArrayListEmployee);

        for(i=0;i<len;i++)
        {
            auxEmployee = ll_get(pArrayListEmployee,i);
            Empleado_getAll(auxEmployee,bufferNombre,bufferApellido,bufferIsEmpty,&bufferSueldo,&bufferId);
            fprintf(pFile,"%s,%s,%s,%d,%d\n",bufferNombre,bufferApellido,bufferIsEmpty,bufferSueldo,bufferId);
            retorno = 0;
        }
    }
    return retorno;
}

