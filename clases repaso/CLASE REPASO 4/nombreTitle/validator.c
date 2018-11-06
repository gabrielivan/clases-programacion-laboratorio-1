#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define LEN 500

int getNombre(char*nombre)
{
    int retorno;
    int i;
    int is_not_valid_name;
    char auxiliar[LEN];

    do {
        fgets(auxiliar,LEN,stdin);
        for (i=0;i<strlen(auxiliar)-1;i++)
        {
            auxiliar[i] = tolower(auxiliar[i]);
            if ((auxiliar[i]<'a' || auxiliar[i]>'z') && auxiliar[i] != ' ')
            {
                is_not_valid_name = -1;
                printf("\nError en formato, ingrese solo letras y espacios: ");
                break;
            }
            else
            {
                if (i == 0 || auxiliar[i-1] == ' ')
                {
                    auxiliar[i] = toupper(auxiliar[i]);
                }
                is_not_valid_name = 0;
                retorno = 0;
            }
        }
    } while (is_not_valid_name);

    strcpy(nombre, auxiliar);
    return retorno;
}
