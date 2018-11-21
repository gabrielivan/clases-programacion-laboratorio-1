#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  char apellido[128];
  char isEmpty[128];
  int sueldo;
};
typedef struct S_Empleado Empleado;

Empleado* Empleado_new();
int Empleado_delete();

Empleado* Empleado_newConParametros(char* id,char* nombre,char* apellido,char* sueldo,char* isEmpty);

int Empleado_setId(Empleado* this,int id);
int Empleado_getId(Empleado* this,int* id);

int Empleado_setNombre(Empleado* this,char* nombre);
int Empleado_getNombre(Empleado* this,char* nombre);

int Empleado_setApellido(Empleado* this,char* Apellido);
int Empleado_getApellido(Empleado* this,char* Apellido);

int Empleado_setSueldo(Empleado* this,int sueldo);
int Empleado_getSueldo(Empleado* this,int* sueldo);

int Empleado_setIsEmpty(Empleado* this,char* isEmpty);
int Empleado_getIsEmpty(Empleado* this,char* isEmpty);

int Empleado_mostrar(void* pEmpleado);
int Empleado_getAll(Empleado* this,char* nombre,char* apellido,char* isEmpty,int* sueldo,int* id);

Empleado* Empleado_getById(void* listaEmpleados,int idIngresado);

#endif // EMPLEADO_H_INCLUDED
