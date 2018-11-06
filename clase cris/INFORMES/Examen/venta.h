#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#define CABA 1
#define ZONA_SUR 2
#define ZONA_OESTE 3
#define A_COBRAR 1
#define COBRADA 2
typedef struct
{
    int idCliente;
    int cantidadAfiches;
    char archivoImagen[51];
    int zona;
    int estado;
    int idVenta;
    int isEmpty;
}Venta;
int venta_init(Venta* arrayVentas, int lenVentas);
Venta* venta_getById(Venta* arrayVentas, int lenVentas, int id);
Venta* venta_getByIdCliente(Venta* arrayVentas, int lenVentas, int idCliente);
Venta* venta_getByIdClienteAndZona(Venta* arrayVentas, int lenVentas, int idCliente, int zona);
int venta_alta(Venta* arrayVentas, int lenVentas, void* arrayClientesVoid, int lenClientes);
int venta_modificar(Venta* arrayVentas, int lenVentas, int reintentos);
int venta_cobrar(Venta* arrayVentas, int lenVentas, void *arrayClientesVoid, int lenClientes, int reintentos);
int venta_ingresoForzado(Venta* arrayVentas, int lenVentas, int idCliente, int afiches, char *archivo, int zona, int estado);
int venta_mostrar(Venta* arrayVentas, int lenVentas);
#endif
