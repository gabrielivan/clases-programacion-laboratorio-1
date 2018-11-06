
typedef struct
{
    char nombre[50];
    char apellido[50];
    char cuit[14];
    int id;
    int isEmpty;
}Cliente;

int cliente_init(Cliente* array, int len);
int cliente_alta(Cliente* array, int len);
int cliente_modificar(Cliente* array, int len);
int cliente_baja(Cliente* array, int len);
Cliente* cliente_getById(Cliente* array, int len,int id);
int cliente_buscarPorId(Cliente* array,int len, int id);
void cliente_mostrarTodo(Cliente* array, int len);
int cliente_altaForzada(Cliente* array,int len,char* nombre,char* apellido, char* cuit);
void cliente_ordenarId(Cliente array[],int len);
void cliente_ordenar(Cliente* array, int len);











