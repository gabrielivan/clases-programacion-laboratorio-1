#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Empleado.h"
#include "utn.h"
#include "Parser.h"

/****************************************************
    Menu:
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
    10. Salir
*****************************************************/

int main()
{
    int option;
    LinkedList* listaEmpleados = ll_newLinkedList();
    LinkedList* listaNuevaEmpleados;
    LinkedList* listaEmpleadosBorrados = ll_newLinkedList();
    LinkedList* subLista;

    do
    {
        utn_getNumero(&option, "\n 01-Clonar lista\n 02-Reingresar empleado\n 03-Alta de empleado\n 04-Modificar datos de empleado\n 05-Baja de empleado\n 06-Listar empleados\n 07-Ordenar empleados\n 08-Borrar todos los empleados\n 09-Borrar toda la lista De Los Empleados Borrados\n 10-Cargar archivo\n 11-Verificar si existe el empleado\n 12-Hacer una subLista De Empleados\n 13-Salir\n","Ingrese un numero valido\n",1,13,1);
        switch(option)
        {
        case 1:
            listaNuevaEmpleados = controller_clonarLista(listaEmpleados);
            printf("\nEl size de la nueva lista es: %d",listaNuevaEmpleados->size);
            break;
        case 2:
            if(!controller_reingresarEmpleado(listaEmpleados,listaEmpleadosBorrados))
            {
                printf("Se reingreso al empleado correctamente! \n");
            }
            else
            {
                printf("No hay empleado/s a reingresar! \n");
            }
            break;
        case 3:
            if(!controller_agregarEmpleado(listaEmpleados))
            {
                printf("Empleado agregado correctamente!");
            }
            else
            {
                printf("No se pudo agregar el empleado");
            }
            break;
        case 4:
            if(ll_isEmpty(listaEmpleados))
            {
                printf("No hay empleado/s a editar\n");
            }
            else
            {
                controller_ListarEmpleados(listaEmpleados);
                if(!controller_editarEmpleado(listaEmpleados))
                {
                    printf("Empleado modificado correctamente!");
                }
                else
                {
                    printf("No se pudo modificar el empleado");
                }
            }
            break;
        case 5:
            if(ll_isEmpty(listaEmpleados))
            {
                printf("No hay empleado/s a borrar\n");
            }
            else
            {
                controller_ListarEmpleados(listaEmpleados);
                if(!controller_borrarEmpleado(listaEmpleados,listaEmpleadosBorrados))
                {
                    printf("El empleado se borro correctamente\n");
                }
                else
                {
                    printf("El empleado no se borro correctamente");
                }
            }
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
            if(ll_isEmpty(listaEmpleados))
            {
                printf("No se puede ordenar el vacio!\n");
            }
            else
            {
                if(!controller_ordenarEmpleados(listaEmpleados))
                {
                    printf("Se ordeno correctamente");
                }
                else
                {
                    printf("No se pudo ordenar");
                }
            }
            break;
        case 8:
            controller_borrarTodosLosEmpleados(listaEmpleados);
            break;

        case 9:
            controller_borrarTodaLaLista(listaEmpleadosBorrados);
            break;
        case 10:
            if(parser_parseEmpleados("data.csv",listaEmpleados)== 0)
            {
                printf("Se cargo el archivo correctamente\n");
            }
            else
            {
                printf("Error al cargar el archivo\n");
            }
            break;
        case 11:
            controller_existeEmpleado(listaEmpleados);
            break;

        case 12:
            if(ll_isEmpty(listaEmpleados))
            {
                printf("No se puede hacer una sub lista,por que no hay empleados.\n");
            }
            else
            {
                subLista = controller_subLista(listaEmpleados);
                printf("Los Empleados Elegidos: \n");
                getchar();
                controller_ListarEmpleados(subLista);
            }
            break;
        }
        pause();
    }
    while(option != 13);
    return 0;
}
