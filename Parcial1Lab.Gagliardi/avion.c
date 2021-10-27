#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "avion.h"
#include "getIO.h"

#include "aerolinea.h"
#include "tipo.h"

int menu()
{
    int opcion = 0;
    system("cls");
    printf("     *** ABM Personas ***\n");
    printf("1- Alta Avion\n");
    printf("2- Modificar avion\n");
    printf("3- Baja avion\n");
    printf("4- Listar aviones\n");
    printf("5- Listar aerolineas\n");
    printf("6- Listar tipos\n");
    printf("7- Listar destinos\n");
    printf("8- Alta vuelo\n");
    printf("9- Listar vuelos\n");
    printf("20- Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);
    //printf("\n");
    return opcion;
}


int inicializarAvion(eAvion aviones[], int tam)
{
    int todoOk = 0;
    if (aviones != NULL && tam > 0)
    {
        todoOk = 1;
        for (int i = 0; i < tam; i++)
        {
            aviones[i].isEmpty = 1;
        }
    }
    return todoOk;
}

int buscarLibreAvion(eAvion aviones[], int tam)
{
    int indice = -1;
    if(aviones != NULL && tam > 0)
    {
        for (int i = 0; i < tam; i++)
        {
            if (aviones[i].isEmpty)
            {
                indice = i;
                break;
            }
        }
    }

    return indice;
}


int altaAvion(eAvion aviones[], int tam, eAerolinea aerolinea[], int tamA, eTipo tipo[],int tamT, int* pId)
{
    int todoOk = 0;
    int indice;
    eAvion auxAvion;
    if (aviones != NULL && tam > 0 && pId != NULL)
    {
        system("cls");
        printf("  ***Alta Avion*** \n\n");
        indice = buscarLibreAvion(aviones, tam);
        if (indice == -1)
        {
            printf("No hay lugar\n");
        }
        else
        {
            auxAvion.id = *pId;
            (*pId)++;

            //Aerolineas
            system("cls");
            mostrarAerolineas(aerolinea, tamA);
            auxAvion.idAerolinea = getInt("\nIngrese el id de la aerolinea: ");
            while ( !validarIdAerolineas(auxAvion.idAerolinea, aerolinea, tamA) )
            {
                printf("\nError, ingrese id de aerolinea valido: ");
                scanf("%d", &auxAvion.idAerolinea);
            }

            system("cls");
            //Tipos
            mostrarTipos(tipo, tamT);
            auxAvion.idTipo = getInt("\nIngrese el id Tipo de avion: ");
            while ( !validarIdTipos(auxAvion.idTipo, tipo, tamT) )
            {
                printf("\nError, ingrese id de Tipo de avion valido: ");
                scanf("%d", &auxAvion.idTipo);
            }

            system("cls");
            //Capaciadad
            auxAvion.capacidad = Get_IntMinMax ("\nIngrese la capacidad entre 10 y 300 pasajeros: ",
                                               "\nError. Reingrese la capacidad entre 10 y 300 pasajeros: "
                                               ,10,300);



            auxAvion.isEmpty = 0;

            aviones[indice] = auxAvion;

            todoOk = 1;
        }
    }
    return todoOk;
}
//void mostrarAvion(eAvion aviones, eTipo tipo[],int tamT, eAerolinea aerolineas[],int tamAero);
void mostrarAvion(eAvion aviones, eTipo tipo[],int tamT, eAerolinea aerolineas[],int tamAero)
{
    char descAerolinea[20];
    char descTipo[20];
//int cargarDescripcionTipo( eTipo tipo[], int tam, int idTipo, char descripcion[] );
    if ( cargarDescripcionAerolinea( aerolineas, tamAero, aviones.idAerolinea, descAerolinea) == 1 &&
       cargarDescripcionTipo(tipo, tamT, aviones.idTipo, descTipo ) == 1 )
    {
        printf(" %d     %-10s      %-10s       %d \n",
               aviones.id,
               descAerolinea,
               descTipo,
               aviones.capacidad );
    }

}





//int mostrarAviones(eAvion aviones, int tamA, eTipo tipo[], int tamT, eAerolinea aerolineas[],int tamAero);
int mostrarAviones(eAvion aviones[], int tamA, eTipo tipo[], int tamT, eAerolinea aerolineas[],int tamAero)
{
    int todoOk = 0;
    int flag = 1;
    if (aviones != NULL && tamA > 0 && tipo != NULL && tamT > 0 && aerolineas != NULL && tamAero > 0)
    {
        //system("cls");
        printf("            ***Lista de Aviones  ***\n");
        printf("------------------------------------------------------------\n");
        printf(" ID        Aerolinea       Tipo de avion         Capacidad\n");
        printf("------------------------------------------------------------\n");
        for (int i = 0; i < tamA; i++)
        {
            if (!aviones[i].isEmpty)
            {
                mostrarAvion( aviones[i],  tipo, tamT,  aerolineas, tamAero);
                flag = 0;
            }
        }
        if (flag)
        {
            printf("No hay aviones para mostrar.\n");

        }
        todoOk = 1;
    }
    return todoOk;
}
