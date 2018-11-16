#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empleado.h"
#include "parser.h"
#include "utn.h"

/** \brief Alta de empleados
 *
 * \param pArrayListEmployee Es el LinkedList donde se agregara el empleado
 * \return Retorna 0 si se logra hacer el alta, sino retorna -1
 *
 */
int controller_agregarEmpleado(LinkedList* listaEmpleados)
{
    int retorno = -1;
    int sueldo;
    int horasTrabajadas;
    char nombre[64];
    if(!utn_getNumero(&sueldo,"Ingrese el sueldo: ","Error,reingrese el sueldo: ",0,99999,2)&&
    !utn_getNumero(&horasTrabajadas,"\nIngrese las horas: ","Error,reingrese las horas: ",0,99999,2)&&
    !utn_getNombre(nombre,64,"\nIngrese el nombre: ","Error,reingrese el nombre: ",2))
    {
        Empleado* empleado = Empleado_new_AI(nombre,horasTrabajadas,sueldo);
        if(empleado != NULL)
        {
            retorno = ll_add(listaEmpleados,empleado);
        }
    }
    return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param pArrayListEmployee Es el LinkedList del cual se va a editar un empleado
 * \return Retorna 0 si se logra editar sino retorna -1
 *
 */
int controller_editarEmpleado(LinkedList* listaEmpleados)
{
    int retorno = -1;
    int i;
    int id, idAux;
    Empleado* empleado;
    int sueldo;
    int horasTrabajadas;
    char nombre[64];

    if(listaEmpleados != NULL)
    {
        if(!utn_getNumero(&id,"Ingrese el ID del empleado a modificar: ","Error",0,99999,2))
        {
            for(i = 0;i< ll_len(listaEmpleados);i++)
            {
               empleado = ll_get(listaEmpleados,i);
               Empleado_getId(empleado,&idAux);
               if(idAux == id)
               {
                    if(!utn_getNumero(&sueldo,"Ingrese el nuevo sueldo: ","Error",0,99999,2)&&
                    !utn_getNumero(&horasTrabajadas,"Ingrese las nuevas horas: ","Error",0,99999,2)&&
                    !utn_getNombre(nombre,64,"Ingrese el nuevo nombre: ","Error",2))
                    {
                        if(
                          !Empleado_setNombre(empleado, nombre)&&
                          !Empleado_setSueldo(empleado, sueldo)&&
                          !Empleado_setHorasTrabajadas(empleado, horasTrabajadas))
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
 * \param pArrayListEmployee Es la LinkedList de empleados
 * \return Retorna 0 si se logra realizar la baja sino retorna -1
 *
 */
int controller_borrarEmpleado(LinkedList* listaEmpleados)
{
    int retorno = -1;
    int i;
    int id, idAux;
    Empleado* empleado;

    if(listaEmpleados != NULL)
    {
        if(!utn_getNumero(&id,"Ingrese el ID del empleado a borrar: ","Error",0,99999,2))
        {
            for(i = 0;i< ll_len(listaEmpleados);i++)
            {
               empleado = ll_get(listaEmpleados,i);
               Empleado_getId(empleado,&idAux);

               if(idAux == id)
               {
                    Empleado_delete(empleado);
                    ll_pop(listaEmpleados,i);
                    retorno = 0;
                    break;
               }

            }
        }

    }
    return retorno;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee Es la LinkedList del cual se desea listar los empleados
 * \return retorna 0 si la LinkedList es diferente a NULL sino retorna -1
 *
 */
int controller_ListarEmpleados(LinkedList* listaEmpleados)
{
    int retorno = -1;
    int i;
    char nombre[128];
    int id;
    int sueldo;
    int horasTrabajadas;
    Empleado* auxPunteroEmpleado;

    if(listaEmpleados != NULL)
    {
        retorno = 0;
        for(i=0;i < ll_len(listaEmpleados);i++)
        {
            auxPunteroEmpleado = ll_get(listaEmpleados,i);
            Empleado_getNombre(auxPunteroEmpleado,nombre);
            Empleado_getId(auxPunteroEmpleado,&id);
            Empleado_getSueldo(auxPunteroEmpleado,&sueldo);
            Empleado_getHorasTrabajadas(auxPunteroEmpleado,&horasTrabajadas);

            printf("\nEl nombre del empleado es: %s",nombre);
            printf("\nEl id del empleado es: %d",id);
            printf("\nEl sueldo del empleado es: %d",sueldo);
            printf("\nLas horas trabajadas del empleado son: %d",horasTrabajadas);
            printf("\n\n");

        }
    }
    return retorno;
}

/** \brief Ordenar empleados por criterio
 *
 * \param pArrayListEmployee Es la LinkedList que se desea ordenar
 * \return retorna 0 si se logra ordenar sino retorna -1
 *
 */
int controller_ordenarEmpleados(LinkedList* listaEmpleados)
{
    int retorno = -1;

    if(listaEmpleados != NULL)
    {
        if(!ll_sort(listaEmpleados,Empleado_criterioSortNombre,1))
        {
            retorno = 0;
        }
    }

    return retorno;
}

int controller_borrarTodosLosEmpleados(LinkedList* listaEmpleados)
{
    int retorno = -1;

    if(listaEmpleados != NULL && listaEmpleados->size > 0)
    {
        if(!ll_clear(listaEmpleados))
        {
            printf("\nSe borraron todos los empleados de la lista con existo!");
            retorno = 0;
        }
    }
    return retorno;
}
int controller_borrarTodaLaLista(LinkedList* listaEmpleados)
{
    int retorno = -1;
    if(listaEmpleados != NULL && listaEmpleados -> size >= 0)
    {
        if(!ll_deleteLinkedList(listaEmpleados))
        {
            printf("\nSe borro la lista con existo!");
            retorno = 0;
        }
    }
    return retorno;
}

LinkedList* controller_clonarLista(LinkedList* listaEmpleados)
{
    LinkedList* retornoAux = NULL;
    LinkedList* listaNuevaDeEmpleados = NULL;
    if(listaEmpleados != NULL && listaEmpleados -> size > 0)
    {
        listaNuevaDeEmpleados = ll_clone(listaEmpleados);
        printf("\nSe clono la lista con existo!");
        retornoAux = listaNuevaDeEmpleados;
    }
    return retornoAux;
}

int controller_existeEmpleado(LinkedList* listaEmpleados)
{
    int retorno = -1;
    Empleado* pEmpleado;
    int id;
    utn_getNumero(&id,"Ingrese el id del empleado a buscar.. ","Error! ",0,10000,2);
    pEmpleado = Empleado_getById(listaEmpleados,id);

    if(listaEmpleados != NULL && listaEmpleados -> size > 0)
    {
        if(ll_contains(listaEmpleados,pEmpleado))
        {
            printf("\nEl empleado se encuentra en la lista");
            printf("\nID: %d",pEmpleado->id);
            printf("\nNombre: %s",pEmpleado->nombre);
            printf("\nHoras-Trabajadas: %d",pEmpleado->horasTrabajadas);
            printf("\nSueldo: %d",pEmpleado->sueldo);
            retorno = 0;
        }
        else if(ll_contains(listaEmpleados,pEmpleado)==0)
        {
            printf("El empleado no se encuentra en la lista");
        }
    }
    return retorno;
}
