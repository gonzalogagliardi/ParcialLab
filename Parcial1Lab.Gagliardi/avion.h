#include "aerolinea.h"
#include "tipo.h"
#ifndef AVION_H_INCLUDED
#define AVION_H_INCLUDED

typedef struct{
    int id;
    int idAerolinea;
    int idTipo;
    int capacidad;
    int isEmpty;
}eAvion; //Almuerzos ?


#endif // AVION_H_INCLUDED
int menu();

int inicializarAvion(eAvion aviones[], int tam);

int buscarLibreAvion(eAvion aviones[], int tam);
/*
int altaAlmuerzo(eAlmuerzo almuerzos[], int tamA ,ePersona lista[], int tam, eLocalidad localidades[], int tamLoc, eComida comidas[], int tamC, int* pIdAlmuerzo);

void mostrarAlmuerzo(eAlmuerzo unAlmuerzo, eComida comidas[], int tamC, ePersona lista[], int tam);

int mostrarAlmuerzos(eAlmuerzo almuerzos[],int tamA, ePersona lista[], int tam, eLocalidad localidades[], int tamLoc, eComida comidas[],int tamC);
*/
int altaAvion(eAvion aviones[], int tam, eAerolinea aerolinea[], int tamA, eTipo tipo[],int tamT, int* pId);

void mostrarAvion(eAvion aviones, eTipo tipo[],int tamT, eAerolinea aerolineas[],int tamAero);

int mostrarAviones(eAvion aviones[], int tamA, eTipo tipo[], int tamT, eAerolinea aerolineas[],int tamAero);
