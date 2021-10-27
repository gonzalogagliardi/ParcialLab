#include "fecha.h"

#ifndef VUELO_H_INCLUDED
#define VUELO_H_INCLUDED

typedef struct{
    int id;
    int idAvion;
    int idDestino;
    eFecha fecha;
    int isEmpty;
}eVuelo; //Almuerzos ?



#endif // VUELO_H_INCLUDED
/*
int menu();
int inicializarPersonas(ePersona lista[], int tam);//VIAJE
int buscarLibre(ePersona lista[], int tam); // -1 si esta todo lleno o el indice de la primer estructura vacia //VIAJE
int altaPersona(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc, int* pId);//VIAJE
void mostrarPersona(ePersona unaPersona, eLocalidad localidades[], int tamLoc);//VIAJE
int mostrarPersonas(ePersona lista[], int tam, eLocalidad localidades[], int tamLoc);//VIAJE
*/
