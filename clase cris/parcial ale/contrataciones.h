typedef struct
{
    char cuit[100];
    char nombreVideo[500];
    int dias;
    int id;
    int idPantalla;
    int isEmpty;
}Contratacion;

int contratacion_init(Contratacion array[],int size,int valor);
Contratacion* contratacion_getByID(Contratacion array[],int size,int id);
int contratacion_IDproducto(Contratacion array[],int size);
int contratacion_alta(Contratacion array[],int size,int id);
int contratacion_modificar(Contratacion array[],int size);
int contratacion_eliminar(Contratacion array[],int size);
int contratacion_ordenarId(Contratacion array[],int size);
int contratacion_mostrar(Contratacion array[],int size);
int contratacion_listar(Contratacion array[],int size,char nombrePantalla[]);
int contratacion_ingresoForzado(Contratacion* array,int size,char* cuit,char* nombreVideo,int dias,int idPantalla);
