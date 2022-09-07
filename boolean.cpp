#include "boolean.h"

void cargar_boolean(boolean &b)
{
    int i;
    printf("'0'=Falso -> '1'=Verdad:");
    scanf("%i",&i);
    if(i==0)
        b=False;
    else
        b=True;
}

void desplegar_boolean(boolean b)
{
    if(b)
        printf("Verdad");
    else
        printf("Falso");
}

