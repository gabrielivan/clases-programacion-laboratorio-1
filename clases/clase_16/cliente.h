
#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
    char nombre[64];
    char apellido[64];
    int id;

}Cliente;

Cliente* cliente_newCliente(void);
int cliente_setNombre(Cliente* this,char* nom);
int cliente_getNombre(Cliente* this,char* nom);
int cliente_inicializarArray(Cliente* array[],int len);
int cliente_buscarLugarVacio(Cliente* array[],int len);
int cliente_buscarPorId(Cliente* array[],int len,int id);
#endif

