#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Empleado.h"
#include "utn.h"
#include "Parser.h"

/****************************************************
    Menu:
    01. Clonar lista
    02. Reingresar empleado
    03. Alta de empleado
    04. Modificar datos de empleado
    05. Baja de empleado
    06. Listar empleados
    07. Ordenar empleados
    08. Borrar todos los empleados
    09. Borrar toda la lista de empleados borrados
    10. Cargar archivo
    11. Verificar si existe el empleado
    12. Hacer una sub lista de empleados
    13. Guardar archivo
    14. Salir
*****************************************************/

int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        utn_getNumero(&option, "\n 01-Clonar lista\n 02-Reingresar empleado\n 03-Alta de empleado\n 04-Modificar datos de empleado\n 05-Baja de empleado\n 06-Listar empleados\n 07-Ordenar empleados\n 08-Borrar todos los empleados\n 09-Borrar toda la lista De Los Empleados Borrados\n 10-Cargar archivo\n 11-Verificar si existe el empleado\n 12-Hacer una sub lista de empleados\n 13-Guardar archivo\n 14-Salir\n","Ingrese un numero valido\n",1,14,1);
        switch(option)
        {
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            if(ll_isEmpty(listaEmpleados))
            {
                printf("No se puede listar el vacio!");
            }
            else if(ll_isEmpty(listaEmpleados)== 0)
            {
                controller_ListarEmpleados(listaEmpleados);
            }
            else
            {
                printf("Error al listar!");
            }
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            if(!controller_loadFromText("datos.csv",listaEmpleados))
            {
                printf("\nDatos cargados correctamente\n");
            }
            else
            {
                printf("No se puedo cargar el archivo!\n");
            }
            break;
        case 11:
            break;

        case 12:

            break;
        case 13:
            if(!controller_saveAsText("data.csv",listaEmpleados))
            {
                printf("\nArchivo guardado.");
            }
            else
            {
                printf("\nNo se pudo guardar los datos\n");
            }
           break;
        }
        pause();
    }
    while(option != 14);
    return 0;
}
