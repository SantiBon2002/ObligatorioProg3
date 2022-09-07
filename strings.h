#ifndef STRINGS_H_INCLUDED
#define STRINGS_H_INCLUDED
#include "boolean.h"
#include "constantes.h"

typedef char strings[S];

void scan(strings &cadena);  //Cargar strings
void print(strings cadena);  //Desplegar strings
int strlar(strings cadena);  //Determina largo del strings
boolean strmen(strings cadena,strings cadena2); //Despliega True si el primer strings es menor alfabeticamente
boolean streq(strings cadena,strings cadena2); //Devuelve True si los strings son iguales
void strcop(strings &cadena,strings cadena2); //Copia la segunda cadena en el primero
void strcon(strings &cadena,strings cadena2); //Concatena el segundo strings al final del primero
void strswp(strings &cadena,strings &cadena2); //Intercambi el strings
#endif // STRINGS_H_INCLUDED
