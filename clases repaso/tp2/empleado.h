typedef struct
{
    char nombre[51];
    char apellido[51];
    float salario;
    int sector;
    //********************
    int id;
    int isEmpty;
}Empleado;

int empleado_init(Empleado* array, int len);
int empleado_alta(Empleado* array, int len);
int empleado_modificar(Empleado* array, int len);
int empleado_baja(Empleado* array, int len);
int empleado_mostrar(Empleado* array, int len);
void empleado_ordenarPorApellido(Empleado* array, int len);
void empleado_ordenarPorSector(Empleado* array, int len);
Empleado* empleado_getById(Empleado* array, int len,int id);
int empleado_listar(Empleado* array,int len);

