#ifndef UTN_H_INCLUDED
#define UTN_H_INCLUDED
#define STRINGLEN 51


int utn_getNumero(  int* pResultado,
                char mensaje[],
                char mensajeError[],
                int  minimo,
                int  maximo,
                int  reintentos);

int utn_getNombre(char* pResultado,
                    char mensaje[],
                    char mensajeError[],
                    int  reintentos);

int utn_getNombreTitle(char*pNombre,
                       char mensaje[],
                       char mensajeError[]);


int utn_getNumeroConComa(float* pResultado,
                    char mensaje[],
                    char mensajeError[],
                    float  minimo,
                    float  maximo,
                    int  reintentos);

int getEmail(char*email);


int utn_getCuit(char* pResultado,
                char mensaje[],
                char mensajeError[],
                int  reintentos);

int validacion_DNI(char* array,int size);

int input_getDNI(char input[],int size,char mensaje[],char msjError[]);

int input_getString(char mensaje[],int size,char input[]);

#endif // UTN_H_INCLUDED
