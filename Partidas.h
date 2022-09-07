#ifndef PARTIDAS_H_INCLUDED
#define PARTIDAS_H_INCLUDED
#include "partida.h"
#include "constantes.h"

typedef struct {
	Partida part[MAXPART];
	int tope;
} Partidas;

void crearPartidas(Partidas &P);

void insPartidas(Partida p, Partidas &P);

int getNroPartidas(Partidas P);

Partida getPartPartidas(Partidas P, int nropart);

boolean isFullPartidas(Partidas P);

boolean isFinPartidas(Partidas P);

#endif
