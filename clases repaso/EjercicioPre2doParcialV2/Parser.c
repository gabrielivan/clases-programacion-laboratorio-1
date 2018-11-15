#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Empleado.h"

#define BUFFER 2000

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
    int retorno = -1;
    char* bufferId;
    char* bufferName;
    char* bufferHorasTrabajadas;
    char bufferFile[BUFFER];
    Empleado* Empleado;
    FILE* auxFile = fopen(fileName,"r");

    if(auxFile != NULL)
    {
        fgets(bufferFile,sizeof(bufferFile),auxFile);

        if(bufferFile != NULL)
        {
            strtok(bufferFile,"\n");
            while(!feof(auxFile))
            {
                bufferId = strtok(bufferFile,",");
                bufferName = strtok(NULL,",");
                bufferHorasTrabajadas = strtok(NULL,"\n");

                if(Empleado != NULL)
                {
                    Empleado = Empleado_newConParametros(bufferId,bufferName,bufferHorasTrabajadas,0);
                    ll_add(listaEmpleados,Empleado);
                    retorno = 0;
                }
            }
        }
    }
    return retorno;

}


