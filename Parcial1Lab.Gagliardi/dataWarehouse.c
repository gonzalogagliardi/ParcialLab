#include "dataWarehouse.h"
#include <string.h>


int idTipo[10] = {5002, 5003, 5001, 5000, 5002, 5000, 5002, 5003, 5001, 5002};

int capacidad[10] = {62, 150, 236, 114, 96, 282, 222, 50, 120, 180 };

int idAerolinea[10] = {1004, 1000, 1002, 1000, 1000, 1003, 1004, 1001, 1002, 1001};


int hardcodearAviones(eAvion aviones[], int tam, int cant, int* pId)
{
    int contador = -1;
    if (aviones != NULL && tam > 0 && cant >= 0 && cant <= tam && pId != NULL)
    {
        contador = 0;
        for (int i = 0; i < cant;  i++)
        {
            aviones[i].id = *pId;
            (*pId)++;
            aviones[i].idAerolinea = idAerolinea[i];
            aviones[i].capacidad = capacidad[i];
            aviones[i].idTipo = idTipo[i];
            aviones[i].isEmpty = 0;
            contador++;
        }
    }
    return contador;
}
