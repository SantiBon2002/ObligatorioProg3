#ifndef BOOLEAN_H_INCLUDED
#define BOOLEAN_H_INCLUDED
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef enum {False,True} boolean;

void cargar_boolean(boolean &b);

void desplegar_boolean(boolean b);

#endif // BOOLEAN_H_INCLUDED
