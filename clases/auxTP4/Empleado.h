#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;

Empleado* Empleado_new();
int Empleado_delete();

Empleado* Empleado_newConParametros(char* id,char* nombre,char* horasTrabajadas,char* sueldo);
Empleado* Empleado_new_AI(char* nombre,int horasTrabajadas,int sueldo);

int Empleado_setId(Empleado* this,int id);
int Empleado_getId(Empleado* this,int* id);

int Empleado_setNombre(Empleado* this,char* nombre);
int Empleado_getNombre(Empleado* this,char* nombre);

int Empleado_setHorasTrabajadas(Empleado* this,int horasTrabajadas);
int Empleado_getHorasTrabajadas(Empleado* this,int* horasTrabajadas);

int Empleado_setSueldo(Empleado* this,int sueldo);
int Empleado_getSueldo(Empleado* this,int* sueldo);


int Empleado_criterioSortNombre(void* thisA,void* thisB);
int Empleado_getAll(Empleado* this,char* nombre,int* horas,int* sueldo,int* id);

int Empleado_calcularSueldo(void* pEmpleado);
int Empleado_mostrar(void* pEmpleado);
Empleado* Empleado_getById(void* listaEmpleados,int idIngresado);

#endif // EMPLEADO_H_INCLUDED
