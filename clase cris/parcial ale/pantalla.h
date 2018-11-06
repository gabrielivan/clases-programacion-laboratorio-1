#define LCD 0
#define LED 1


typedef struct
{
    char nombre[100];
    char direccion[100];
    float precio;
    int tipo;
    int isEmpty;
    int id;

}Pantalla;

int pantalla_init(Pantalla array[],int size,int valor);
Pantalla* pantalla_getByID(Pantalla array[],int size,int id);
int pantalla_IDproducto(Pantalla array[],int size);
int pantalla_alta(Pantalla array[],int size);
int pantalla_modificar(Pantalla array[],int size);
int pantalla_eliminar(Pantalla array[],int size);
int pantalla_ordenarId(Pantalla array[],int size);
int pantalla_mostrar(Pantalla array[],int size);
int pantalla_listar(Pantalla array[],int size);
int pantalla_ingresoForzado(Pantalla* array,int size,char* nombre,char*direccion,int tipo,float precio);

