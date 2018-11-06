typedef struct sProducto
{
    char descripcion[100];
    char nombre[100];
    float precio;
    int isEmpty;
    int ID;

}Producto;

void producto_initArrayProducto(Producto arrayProducto[],int size,int valor);

int producto_altaArray(Producto arrayProducto[],int indice,int size);

int producto_mostrarArray(Producto arrayProducto[],int indice,int size);

int producto_buscarIndiceArray(Producto arrayProducto[],int size,int* indiceVacio);

int producto_IDproducto(Producto arrayProducto[],int size);

int producto_modificarProducto(Producto arrayProducto[],int size);

int producto_eliminarProducto(Producto arrayProducto[],int size);
