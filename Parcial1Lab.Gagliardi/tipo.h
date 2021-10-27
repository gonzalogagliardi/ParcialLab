#ifndef TIPO_H_INCLUDED
#define TIPO_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eTipo; //Localidad

#endif // TIPO_H_INCLUDED

int cargarDescripcionTipo( eTipo tipo[], int tam, int idTipo, char descripcion[] );

int mostrarTipos( eTipo tipo[], int tam );
// 0 si no existe el id o me devuelve 1 si existe el id
int validarIdTipos( int id, eTipo tipo[], int tam );
