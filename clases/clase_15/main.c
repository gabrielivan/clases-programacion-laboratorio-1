#include <stdio.h>
#include <stdlib.h>

int* newArray(int size);
int initArray(int* arrayInt,int limite,int valor);
int showArray(int* arrayInt,int limite);
int delete_array(int* arrayInt);
int* editSize(int* arrayInt,int size);


int main()
{
    int* arrayEnteros;
    arrayEnteros = newArray(100);
    initArray(arrayEnteros,100,1024);
    showArray(arrayEnteros,100);
    arrayEnteros = editSize(arrayEnteros,200);
    showArray(arrayEnteros,200);
    delete_array(arrayEnteros);

    return 0;

}

int* newArray(int size)
{
    int* retorno = NULL;
    int* auxInt;

    if(size > 0)
    {
        auxInt = (int*) malloc(sizeof(int)*size);
        if(auxInt != NULL)
        {
            retorno = auxInt;
        }

    }
     return retorno;
}

int initArray(int* arrayInt,int limite,int valor)
{
    int retorno = -1;
    int i;

    if(arrayInt != NULL && limite > 0)
    {
      for(i=0;i<limite;i++)
      {
        *(arrayInt + i) = valor;
      }
      retorno = 0;

    }
    return retorno;
}

int showArray(int* arrayInt,int limite)
{
    int retorno = -1;
    int i;

    if(arrayInt != NULL && limite > 0)
    {
      for(i=0;i<limite;i++)
      {
        printf("%p - [%d] - %d\n",(arrayInt + i),i,*(arrayInt + i));
      }
      retorno = 0;

    }
    return retorno;
}
int delete_array(int* arrayInt)
{
    int retorno = -1;

    if(arrayInt != NULL)
    {
        free(arrayInt);
        retorno = 0;
    }
    return retorno;
}

int* editSize(int* arrayInt,int size)
{
    int* retorno = NULL;
    int* auxInt;

    if(arrayInt && size > 0)
    {
        auxInt = (int*) realloc (arrayInt,sizeof(int)*size);
        if(auxInt != NULL)
        {
            retorno = auxInt;
        }

    }
     return retorno;
}


