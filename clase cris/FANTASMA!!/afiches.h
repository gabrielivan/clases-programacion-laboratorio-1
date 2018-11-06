typedef struct
{
    int cantidadAfiche;
    char nombreArchivo[50];
    int zona;
    int estado;
    int venta;
    //********************
    int id;
    int clienteId;
    int isEmpty;
}Afiche;

int afiche_init(Afiche* array, int len);
int afiche_alta(Afiche* array,Cliente* arrayCliente, int len,int lenCliente);
int afiche_modificar(Afiche* array, int len,Cliente* arrayCliente, int lenCliente);
int afiche_Cobrar(Afiche* array, int len, Cliente* arrayCliente, int lenCliente);
Afiche* afiche_getByCliente(Afiche* array,int len,int clienteId);
void afiche_mostrarTodo(Afiche* array, int len);
void afiche_mostrarByCuit(Afiche* array, int len,char cuit[]);
int afiche_ordenar(Afiche* array, int len);
void afiche_mostrar(Afiche* array, int len);
//int cont_altaForzada(Archivo* arrayAfiche,int lenArrayAfiche,
//                     Pantalla* arrayPantallas, int lenPantallas,
//                     int idPantalla,char* nombreVideo,char* cuit,int dias);

