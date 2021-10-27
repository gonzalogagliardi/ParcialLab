#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#ifndef GETIO_H_INCLUDED
#define GETIO_H_INCLUDED



#endif // GETIO_H_INCLUDED
int Validate_IntMinMax (char numero[], int min, int max);

int Get_IntMinMax (char message[], char errorMessage[], int min, int max);

int esSoloLetras(char str[]);

int getStringLetras(char mensaje[],char input[]);

void getString(char mensaje[],char input[]);

float getFloat(char mensaje[]);

int getInt(char mensaje[]);
