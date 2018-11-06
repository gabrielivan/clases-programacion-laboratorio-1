#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED
typedef struct
{
    char nombre[51];
    char apellido[51];
    char cuit[20];
    int idCliente;
    int isEmpty;
}Cliente;
int cliente_init(Cliente* arrayClientes, int lenClientes);
Cliente* cliente_getById(Cliente* arrayClientes, int lenClientes, int id);
int cliente_alta(Cliente* arrayClientes, int lenClientes);
int cliente_modificar(Cliente* arrayClientes, int lenClientes, int reintentos);
int cliente_baja(Cliente* arrayClientes, int lenClientes, void* arrayVentasVoid, int lenVentas, int reintentos);
int cliente_ingresoForzado(Cliente* arrayclientes, int lenClientes, char *nombre, char *apellido, char *cuit);
int cliente_mostrar(Cliente* arrayClientes, int lenClientes);
int cliente_mostrarVentas(Cliente* arrayClientes, int lenClientes, void* arrayVentasVoid, int lenVentas);
#endif

