#ifndef INFORMES_H_INCLUDED
#define INFORMES_H_INCLUDED

int informar_sortClientePorNombreApellido(Cliente* array, int len);
int informar_ventasMayorMenorNumeroAfiches(Afiche* arrayAfiche, int lenAfiche, int* cantidadVentas,int mayorMenor, int numeroAfiches);
int informar_promedioAfichesPorVenta(Afiche* arrayAfiche, int lenAfiche, float *promedio);
int informar_cantidadTotalDeVentas(Afiche* arrayAfiche, int lenAfiche, int *cantidadTotalVentas);
int informar_cantidadTotalDeAfiches(Afiche* arrayAfiche, int lenAfiche, int *cantidadTotalAfiches);
int informar_VentasSuperaOrNoPromedioAfiches(Afiche* arrayAfiche,int lenAfiche,int *cantidadVentas,int SuperaNoSupera);
int informar_mostrarVentaPorEstado(Afiche* arrayAfiche, int len, int estado);
int informar_mostrarVentaPorZona(Afiche* arrayAfiche, int len, int zona);



#endif
