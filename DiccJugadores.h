#ifndef DICCJUGADORES_H_INCLUDED
#define DICCJUGADORES_H_INCLUDED
#include "ListaJugadores.h"
#include "constantes.h"

typedef LJugadores DiccJugadores[N];

int h(int ci);

void crearDiccJugadores(DiccJugadores &dj);

boolean isInDiccJugadores(DiccJugadores dj, int ci);

void insJugadorDiccJugadores(Jugador j, DiccJugadores &dj);

Jugador getJugadorDiccJugadores(DiccJugadores dj, int ci);

void sustJugadorDiccJugadores(Jugador j_baja, Jugador j_alta, DiccJugadores &dj);

void listarDiccJugadores(DiccJugadores dj);

int getMaxPGDiccJugadores(DiccJugadores dj);

void listarGanadoresDiccJugadores(DiccJugadores dj, int maxpgan);

#endif
