#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Empleado.h"
#include "utn.h"

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

    do
    {
        printf("\nComienzo%d\n",ll_len(listaEmpleados));
        utn_getNumero(&option, "\n 01- .\n 02- .\n 03-Alta de empleado\n 04-Modificar datos de empleado\n 05-Baja de empleado\n 06-Listar empleados\n 07-Ordenar empleados\n 08- .\n 09- .\n 10-Salir\n","Ingrese un numero valido\n",1,12,1);
        switch(option)
        {
        case 1:
            listaNuevaEmpleados = controller_clonarLista(listaEmpleados);
            printf("\n%d",listaNuevaEmpleados->size);
            break;
        case 2:
            printf("\n%d",listaNuevaEmpleados->size);
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
            controller_ListarEmpleados(listaEmpleados);
            if(!controller_editarEmpleado(listaEmpleados))
            {
                printf("Empleado modificado correctamente!");
            }
            else
            {
                printf("No se pudo modificar el empleado");
            }
            break;
        case 5:
            controller_ListarEmpleados(listaEmpleados);
            if(!controller_borrarEmpleado(listaEmpleados))
            {
                printf("El empleado se borro correctamente");
            }
            else
            {
                printf("El empleado no se borro correctamente");
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
            if(!controller_ordenarEmpleados(listaEmpleados))
            {
                printf("Se ordeno correctamente");
            }
            else
            {
                printf("No se pudo ordenar");
            }
            break;

        case 8:
            controller_borrarTodosLosEmpleados(listaEmpleados);
            break;

        case 9:
            controller_borrarTodaLaLista(listaEmpleados);
            break;
        case 10:
            controller_ListarEmpleados(listaNuevaEmpleados);
            break;

        case 11:
            controller_existeEmpleado(listaEmpleados);
            break;
        }
        pause();
    }
    while(option != 12);
    return 0;
}

//    LinkedList* listaEmpleados;
//    listaEmpleados = ll_newLinkedList();
//
//    if(parser_parseEmpleados("data.csv",listaEmpleados)== 0)
//    {
//        ll_map(listaEmpleados,Empleado_calcularSueldo);
//        ll_map(listaEmpleados,Empleado_mostrar);
//    }
//    else
//    {
//       printf("Error leyendo empleados\n");
//    }
