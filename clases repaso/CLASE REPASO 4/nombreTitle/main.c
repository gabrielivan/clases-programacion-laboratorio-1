#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validator.h"

int main()
{
    char miNombre[500];

    printf("Carga de nombre:\n");
    if (!getNombre(miNombre)) {
        printf("%s", miNombre);
    }

    return 0;
}

