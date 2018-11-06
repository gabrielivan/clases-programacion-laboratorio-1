#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STRINGLEN 500
#include "func.h"

int main()
{
    char miNombre[STRINGLEN];
    char miEdad[STRINGLEN];
    int edad, i, validado = 1;

    //COMPARACION
    //strncpy(miString, "pepe", STRINGLEN);

    printf("Ingrese su nombre: ");
    fgets(miNombre, STRINGLEN, stdin);
    printf("Hola %s", miNombre);


    printf("Ingrese su edad: ");
    fflush(stdin);
    fgets(miEdad, STRINGLEN, stdin);

    for (i=0; i<strlen(miEdad)-1; i++) {
        if (miEdad[i] < '0' || miEdad[i] > '9'){
            validado = 0;
            break;
        }
    }

    if (validado) {
        edad = atoi(miEdad);
        printf("Mi edad es: %d", edad);
    } else {
        printf("Edad invalida!");
    }



    return 0;
}
