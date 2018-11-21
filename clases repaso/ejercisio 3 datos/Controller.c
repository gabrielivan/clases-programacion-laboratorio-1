#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empleado.h"
#include "parser.h"
#include "utn.h"


/** \brief Listar empleados
 *
 * \param listaEmpleados Es la LinkedList del cual se desea listar los empleados
 * \return retorna 0 si la LinkedList es diferente a NULL sino retorna -1
 *
 */
int controller_ListarEmpleados(LinkedList* listaEmpleados)
{
    int retorno = -1;
    int i;
    char nombre[128];
    char apellido[128];
    char isEmpty[128];
    int id;
    int sueldo;
    Empleado* auxPunteroEmpleado;

    if(listaEmpleados != NULL)
    {
        retorno = 0;
        for(i=0;i < ll_len(listaEmpleados);i++)
        {
            auxPunteroEmpleado = ll_get(listaEmpleados,i);
            Empleado_getNombre(auxPunteroEmpleado,nombre);
            Empleado_getApellido(auxPunteroEmpleado,apellido);
            Empleado_getIsEmpty(auxPunteroEmpleado,isEmpty);
            Empleado_getId(auxPunteroEmpleado,&id);
            Empleado_getSueldo(auxPunteroEmpleado,&sueldo);

            printf("\nEl id del empleado es: %d",id);
            printf("\nEl nombre del empleado es: %s",nombre);
            printf("\nEl apellido del empleado es: %s",apellido);
            printf("\nEl sueldo del empleado es: %d",sueldo);
            printf("\nEl isEmpty del empleado es :%s",isEmpty);
            printf("\n\n");
        }
    }
    return retorno;
}


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* lista donde se va a guardar el archivo
 * \return [0] Exito y [-1] Error
 */

int controller_loadFromText(char* path , LinkedList* listaEmpleados)
{
    FILE* pArchivo;
    int retorno = -1;
    pArchivo = fopen(path,"r");
    if(!parser_EmployeeFromText(pArchivo,listaEmpleados))
    {
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char* ruta del archivo
 * \param pArrayListEmployee LinkedList* lista que se va a guardar
 * \return [0] Exito y [-1] Error
 */

int controller_saveAsText(char* path , LinkedList* listaEmpleados)
{
    FILE* pArchivo = fopen(path,"w");
    int retorno = -1;

    if(pArchivo != NULL && !parser_SaveToText(pArchivo,listaEmpleados))
    {
        retorno = 0;
    }
    fclose(pArchivo);
    return retorno;
}
