typedef struct
{
    char cuit[14];//cuit del cliente
    int dias;//duracion de la publicacion
    char nombreVideo[100];//nombre del archivo de video
    //********************
    int id;
    int isEmpty;
    int pantallaId;
}Contratacion;


int contratacion_init(Contratacion* array, int len);
int contratacion_alta(Contratacion* array,Pantalla* arrayPantalla, int len,int lenPantalla);
int contratacion_modificar(Contratacion* array, int len,Pantalla* arrayPantallas, int lenPantallas);
int contratacion_baja(Contratacion* array, int len, char cuit[], Pantalla* arrayPantallas, int lenPantallas);
void contratacion_mostrar(Contratacion* array, int len);
int contratacion_ordenar(Contratacion* array, int len);
void contratacion_mostrarByCuit(Contratacion* array, int len,char cuit[]);
Contratacion* contratacion_getByPantalla(Contratacion* array,int len,int pantallaId);
void contratacion_mostrarTodo(Contratacion* array, int len);


