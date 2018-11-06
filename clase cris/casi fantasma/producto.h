typedef struct sProducto
{
    int id;
    char descripcion[100];
    char nombre[100];
    float precio;
    int isEmpty;

}Producto;

void producto_initArrayProducto(Producto arrayProducto[],int size,int valor);

int producto_altaArray(Producto arrayProducto[],int indice,int size);

int producto_bajaLogica(Producto arrayProducto[],int indice,int size);

int producto_modificar(Producto arrayProducto[],int indice,int size);

int producto_mostrarArray(Producto arrayProducto[],int indice,int size);

void producto_mostrarArrayCompleto(Producto arrayProducto[],int size);

int producto_buscarIndiceArray(Producto arrayProducto[],int size);

int producto_buscarIndiceArrayById(Producto arrayProducto[],int id, int size);



void limpiarPantalla(void);

void pararPantalla();

