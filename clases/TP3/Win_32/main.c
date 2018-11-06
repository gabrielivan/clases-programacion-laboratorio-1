#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        utn_getNumero(&option, "\n 01-Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n 02-Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n 03-Alta de empleado\n 04-Modificar datos de empleado\n 05-Baja de empleado\n 06-Listar empleados\n 07-Ordenar empleados\n 08-Guardar los datos de los empleados en el archivo data.csv(modo texto).\n 09-Guardar los datos de los empleados en el archivo data.csv(modo binario).\n 10-Salir\n","Ingrese un numero valido\n",1,10,1);
        switch(option)
        {
            case 1:
                printf("\nSize de la lista: %d \n",ll_len(listaEmpleados));
                controller_loadFromText("data.csv",listaEmpleados);
                printf("\nSize de la lista: %d \n",ll_len(listaEmpleados));
                break;
            case 2:
                printf("\nSize Linked List %d",ll_len(listaEmpleados));
                if(!controller_loadFromBinary("data.bin",listaEmpleados))
                {
                    printf("\nDatos cargados");
                }
                printf("\nSize Linked List %d",ll_len(listaEmpleados));
                break;
            case 3:
                if(!controller_addEmployee(listaEmpleados))
                {
                    printf("Empleado agregado correctamente!");
                }
                else{
                    printf("No se pudo agregar el empleado");
                }
                break;
            case 4:

                if(!controller_editEmployee(listaEmpleados))
                {
                    printf("Empleado modificado correctamente!");
                }
                else{
                    printf("No se pudo modificar el empleado");
                }
                break;
            case 5:
                if(!controller_removeEmployee(listaEmpleados))
                {
                    printf("El empleado se borro correctamente");
                }
                else
                {
                    printf("El empleado no se borro correctamente");
                }
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                printf("Ordenando por criterio....\n");
                if(!controller_sortEmployee(listaEmpleados))
                {
                    printf("Se ordeno correctamente");
                }
                else
                {
                    printf("No se pudo ordenar");
                }
                break;

            case 8:
                if(!controller_saveAsText("data.csv",listaEmpleados))
                {
                    printf("\nArchivo guardado.");
                }
                else
                {
                    printf("\nNo hay datos cargados");
                }
                break;

            case 9:
                if(!controller_saveAsBinary("data.bin",listaEmpleados))
                {
                    printf("\nArchivo guardado.");
                }
                else
                {
                    printf("\nNo se pudo guardar el archivo.");
                }
                break;
        }
     pause();
     limpiarPantalla();
    }while(option != 10);
    return 0;
}
