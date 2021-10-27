#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "vuelo.h"
#include "tipo.h"
#include "fecha.h"
#include "destino.h"
#include "avion.h"
#include "aerolinea.h"
#include "dataWarehouse.h"
#include "getIO.h"

#define TAM_AER 5
#define TAM_T 4
#define TAM_A 10

int main()
{
    char seguir = 's';
    char salir;
    char ProbandoGet[20];
    int idAvion = 2000;
    //int idAerolinea = 1000;
    //int idTipos = 5000;

    eAvion aviones[TAM_A];


        eAerolinea aerolinea[TAM_AER] =
    {
        { 1000, "Lan" },
        { 1001, "Iberia" },
        { 1002, "Norwegian" },
        { 1003, "American" },
        { 1004, "Amsterdam" }
    };



        eTipo tipo[TAM_T] =
    {
        { 1000, "Jet" },
        { 1001, "Helice" },
        { 1002, "Planeador" },
        { 1003, "Carga" }
    };





        if ( !inicializarAvion(aviones,TAM_A))
        {
            printf("Error al inicializar aviones\n");
        }


        hardcodearAviones(aviones, TAM_A, 10, &idAvion);




        do
        {
            switch (menu())
            {
            case 1:
                        system("cls");
                        if(!altaAvion(aviones, TAM_A, aerolinea, TAM_AER, tipo, TAM_T, &idAvion))
                        {
                            printf("No se pudo realizar el alta\n");
                        }
                        else
                        {
                            printf("Alta exitosa\n");
                        }
                        break;

            case 2:
                        //mostrarAviones(eAvion aviones[], int tamA, eTipo tipo[], int tamT, eAerolinea aerolineas[],int tamAero);
                        system("cls");
                        if ( !mostrarAviones(aviones, TAM_A, tipo, TAM_T, aerolinea, TAM_AER) )
                        {
                            printf("Error. No se puede mostrar los aviones.\n");
                        }

         case 20:
            printf("\nEsta seguro que quiere salir? (S/N)\n");
            fflush(stdin);
            scanf("%c", &salir);
            salir = toupper(salir);
            if (salir == 'S')
            {
                seguir = 'n';
            }
            else
            {
                break;
            }
            break;
        default:
            printf("Opcion invalida\n");
        }
        system("pause");


        }
        while(seguir == 's');

    return 0;
}
