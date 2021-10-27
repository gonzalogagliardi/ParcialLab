#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"

int cargarDescripcionTipo( eTipo tipo[], int tam, int idTipo, char descripcion[])
{
    int todoOk = 0;
    int flag = 1;
    if (tipo != NULL && tam > 0 && descripcion != NULL)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            if (tipo[i].id == idTipo)
            {
                strcpy(descripcion, tipo[i].descripcion);
                flag = 0;
                break;
            }
        }
        if (flag)
        {
            todoOk = -1; // no habia localidad con el id que le pasaron
        }
    }
    return todoOk;
}


int mostrarTipos(eTipo tipo[], int tam)
{
    int todoOk = 0;
    if (tipo != NULL && tam > 0 )
    {
        printf("      *** Tipos *** \n\n");
        printf("  Id         Descripcion\n");
        for (int i = 0; i < tam; i++)
        {
            printf("  %d       %-10s\n", tipo[i].id, tipo[i].descripcion);
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}

int validarIdTipos( int id, eTipo tipo[], int tam)
{
    int todoOk = 0;
    if (tipo != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (id == tipo[i].id)
            {
                todoOk = 1;
                break;
            }
        }
    }
    return todoOk;
}
