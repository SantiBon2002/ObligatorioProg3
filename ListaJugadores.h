#ifndef LISTAJUGADORES_H_INCLUDED
#define LISTAJUGADORES_H_INCLUDED
#include "Jugador.h"

typedef struct nodoL {
					  Jugador j;
					  nodoL *sig;
					  } Nodo;
typedef Nodo* LJugadores;

void insFLJugadores(Jugador j, LJugadores &LJ);

boolean isInLJugadores(int ci, LJugadores LJ);

Jugador getJugadorLJugadores(int ci, LJugadores LJ);

void sustJugadorDiccLJugadores(Jugador j, LJugadores LJ);

void listarLJugadores(LJugadores LJ);
int getMaxPGLJugadores(LJugadores LJ);
void listarGanLJugadores(LJugadores LJ, int maxpgan);
#endif // LISTAJUGADORES_H_INCLUDED
