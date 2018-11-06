#ifndef AFICHES_H_INCLUDED
#define AFICHES_H_INCLUDED

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
int afiche_baja(Afiche* array, int len,int idCliente);
Afiche* afiche_getById(Afiche* array,int len,int IdIngresado);
void afiche_mostrar(Afiche* array, int len);
int cliente_mostrarVentas(Cliente* array, int len, Afiche* arrayAfiche, int lenAfiche);
int afiche_altaForzada(Afiche* arrayAfiche,int lenArrayAfiche,
                     Cliente* arrayCliente, int lenCliente,
                     int idCliente,char* nombreArchivo,int cantidadAfiche,int zona,int estado);


#endif // UTN_H_INCLUDED
