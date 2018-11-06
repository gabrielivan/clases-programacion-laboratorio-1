#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED
int informar_sortClientePorApellidoNombre(void* arrayClientesVoid, int lenClientes);
int informar_sortClientePorCuit(void* arrayClientesVoid, int lenClientes);
int informar_ventasMayorMenorAfichesNumero(void *arrayVentasVoid, int lenVentas, int *cantidadVentas,int mayorMenor, int numeroAfiches);
int informar_cantidadTotalDeAfiches(void* arrayVentasVoid, int lenVentas, int *cantidadTotalAfiches);
int informar_cantidadTotalDeVentas(void* arrayVentasVoid, int lenVentas, int *cantidadTotalVentas);
int informar_promedioAfichesPorVenta(void* arrayVentasVoid, int lenVentas, float *promedio);
int informar_ventasSuperaOrNoPromedioAfiches(void* arrayVentasVoid,int lenVentas,int *cantidadVentas,int SuperaOrNo);
int informar_mostrarVentaPorEstado(void* arrayVentasVoid, int len, int estado);
int informar_mostrarVentaPorZona(void* arrayVentasVoid, int len, int zona);
int informar_mostrarVentaPorEstadoAndZona(void* arrayVentasVoid, int len, int estado ,int zona);
int informar_ventaConMasAfiches(void* arrayVentasVoid, int lenVentas);
int informar_clienteConMasVentas(void* arrayVentasVoid, int lenVentas,void* arrayClientesVoid, int lenClientes);
int informar_clienteConMasAfiches(void* arrayVentasVoid, int lenVentas,void* arrayClientesVoid, int lenClientes);
int informar_mostrarClientesPorZona(void* arrayClientesVoid, int lenClientes, void* arrayVentasVoid, int lenVentas, int zona);
int informar_afichesPorZona(void* arrayVentasVoid, int lenVentas, int zona);
#endif
