//#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"
#include "cliente.h"
#include "afiches.h"
#include "infomes.h"
#define CANTIDAD_CLIENTES 10
#define CANTIDAD_AFICHES 10
#define CABA 1
#define ZONA_SUR 2
#define ZONA_OESTE 3
#define VENTA_COBRAR 1
#define VENTA_COBRADA 2

int main()
{
    int opcionMenu = 1;
    int id;


    Cliente arrayClientes[CANTIDAD_CLIENTES];
    Afiche arrayAfiche[CANTIDAD_AFICHES];

    cliente_init(arrayClientes,CANTIDAD_CLIENTES);
    afiche_init(arrayAfiche,CANTIDAD_AFICHES);


    cliente_altaForzada(arrayClientes,CANTIDAD_CLIENTES,"cris","saliba","40-91191191-5");
    cliente_altaForzada(arrayClientes,CANTIDAD_CLIENTES,"gaby","saliba","20-91191191-6");
    cliente_altaForzada(arrayClientes,CANTIDAD_CLIENTES,"pablo","Iraty","30-91191191-6");
    cliente_altaForzada(arrayClientes,CANTIDAD_CLIENTES,"damian","Hernandez","20-91191191-7");


    afiche_altaForzada(arrayAfiche,CANTIDAD_AFICHES,arrayClientes,CANTIDAD_CLIENTES,0,"RAMBO 1",20,1,1);
    afiche_altaForzada(arrayAfiche,CANTIDAD_AFICHES,arrayClientes,CANTIDAD_CLIENTES,1,"RAMBO 2",9,1,1);
    afiche_altaForzada(arrayAfiche,CANTIDAD_AFICHES,arrayClientes,CANTIDAD_CLIENTES,2,"RAMBO 2",15,1,2);
    afiche_altaForzada(arrayAfiche,CANTIDAD_AFICHES,arrayClientes,CANTIDAD_CLIENTES,2,"RAMBO 3",8,3,2);
    afiche_altaForzada(arrayAfiche,CANTIDAD_AFICHES,arrayClientes,CANTIDAD_CLIENTES,3,"RAMBO 1",10,1,2);
    afiche_altaForzada(arrayAfiche,CANTIDAD_AFICHES,arrayClientes,CANTIDAD_CLIENTES,3,"RAMBO 4",40,1,2);



    while(opcionMenu >= 1 && opcionMenu < 11)
    {
        utn_getNumero(&opcionMenu,"\n01 - ALTA CLIENTE \n02 - MODIFICAR DATOS DEL CLIENTE \n03 - BAJA CLIENTE \n04 - VENDER UN AFICHE \n05 - EDITAR VENTA \n06 - COBRAR VENTA \n07 - IMPRIMIR CLIENTES \n08 - MOSTRAR CLIENTE \n09 - MOSTRAR VENTAS \n10 - INFORMES \n11 - SALIR \n",
                      "Error,reingrese una opcion valilda: ",1,11,2);

        switch(opcionMenu)
        {
        case 1:
            cliente_alta(arrayClientes,CANTIDAD_CLIENTES);
            break;

        case 2:
            cliente_modificar(arrayClientes,CANTIDAD_CLIENTES);
            break;

        case 3:
            cliente_baja(arrayClientes,CANTIDAD_CLIENTES, &id);
            if (id != -1)
            {
                afiche_baja(arrayAfiche, CANTIDAD_AFICHES, id);
            }
            break;

        case 4:
            afiche_alta(arrayAfiche,arrayClientes,CANTIDAD_AFICHES,CANTIDAD_CLIENTES);
            break;

        case 5:
            afiche_modificar(arrayAfiche,CANTIDAD_AFICHES,arrayClientes,CANTIDAD_CLIENTES);
            break;

        case 6:
            afiche_Cobrar(arrayAfiche,CANTIDAD_AFICHES,arrayClientes,CANTIDAD_CLIENTES);
            break;


        case 7:
            cliente_mostrarVentas(arrayClientes,CANTIDAD_CLIENTES,arrayAfiche,CANTIDAD_AFICHES);
            break;

        case 8:
              cliente_mostrarTodo(arrayClientes,CANTIDAD_CLIENTES);
            break;

        case 9:
              afiche_mostrar(arrayAfiche,CANTIDAD_AFICHES);
            break;

        case 10:

              informar_clienteConMasVentas(arrayAfiche,CANTIDAD_AFICHES,arrayClientes,CANTIDAD_CLIENTES);
              informar_clienteConMasVentasAcobrar(arrayAfiche,CANTIDAD_AFICHES,arrayClientes,CANTIDAD_CLIENTES);
              informar_clienteConMasVentasCobradas(arrayAfiche,CANTIDAD_AFICHES,arrayClientes,CANTIDAD_CLIENTES);
              informar_clienteConMasAfichesComprados(arrayAfiche,CANTIDAD_AFICHES,arrayClientes,CANTIDAD_CLIENTES);
              informar_clienteConMasAfichesAcobrar(arrayAfiche,CANTIDAD_AFICHES,arrayClientes,CANTIDAD_CLIENTES);
            break;
        }

    }
    return 0;
}


