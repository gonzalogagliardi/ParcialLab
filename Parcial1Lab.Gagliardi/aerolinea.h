
#ifndef AEROLINEA_H_INCLUDED
#define AEROLINEA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];
}eAerolinea; //Localidad

#endif // AEROLINEA_H_INCLUDED

int cargarDescripcionAerolinea( eAerolinea aerolineas[], int tam, int idAerolinea, char descripcion[]);

int mostrarAerolineas( eAerolinea aerolineas[], int tam);
// 0 si no existe el id o me devuelve 1 si existe el id
int validarIdAerolineas( int id, eAerolinea aerolineas[], int tam);

