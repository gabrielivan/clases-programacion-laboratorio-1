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
    Empleado* pEmpleado;
    FILE* auxFile = fopen(fileName,"r");

    if(auxFile != NULL)
    {
        fgets(bufferFile,sizeof(bufferFile),auxFile);
        //printf("%s",bufferFile);

        if(bufferFile != NULL)
        {
            strtok(bufferFile,"\n");

            while(!feof(auxFile))
            {
                fgets(bufferFile,sizeof(bufferFile),auxFile);

                bufferId = strtok(bufferFile,",");
                //printf("%s\n",bufferId);
                bufferName = strtok(NULL,",");
               // printf("%s\n",bufferName);
                bufferHorasTrabajadas = strtok(NULL,";");
                //printf("%s\n",bufferHorasTrabajadas);

                pEmpleado = Empleado_newConParametros(bufferId,bufferName,bufferHorasTrabajadas,"1000");

                if(pEmpleado != NULL)
                {
                    ll_add(listaEmpleados,pEmpleado);
                    retorno = 0;
                }
            }
        }
        fclose(auxFile);
    }
    return retorno;

}


