#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
    char nombre[50];
    char apellido[50];
    int id;
    int isEmpty;
}Cliente;

Cliente* cliente_new();
void cliente_delete();
Cliente* cliente_newConParametros(char* nombre,int lenNombre,char* apellido,int lenApellido,int id,int isEmpty);

int cliente_setNombre(Cliente* this,char* nombre,int lenNombre);
int cliente_getNombre(Cliente* this,char* nombre);

int cliente_setApellido(Cliente* this,char* apellido,int lenApellido);
int cliente_getApellido(Cliente* this,char* apellido);

int cliente_setId(Cliente* this,int id);
int cliente_getId(Cliente* this,int* id);

int cliente_setIsEmpty(Cliente* this,int isEmpty);
int cliente_getIsEmpty(Cliente* this,int* isEmpty);

#endif // CLIENTE_H_INCLUDED
