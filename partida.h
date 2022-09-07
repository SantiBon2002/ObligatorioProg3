#ifndef PARTIDA_H_INCLUDED
#define PARTIDA_H_INCLUDED
#include "boolean.h"

typedef struct {
    int nropartida;
    int ci1;
    int ci2;
    int ciwin;
    boolean finalizada;
} partida;

typedef partida* Partida;

void crearPartida(Partida &p);
void elimPartida(Partida &p);
void setNroPartida(int nropartida, Partida &p);
void setJugadoresPartida(int ci1, int ci2, Partida &p);
//Setea la ci del ganador
//PreCondicion: ciwin pert {ci1,ci2}
//efecto colateral: pone finalizada en TRUE.
void setFinalPartida(int ciwin, Partida &p);

int getNroPartida(Partida p);
void getCiJugadoresPartida(Partida p, int &ci1, int &ci2);
int getGanadorPartida(Partida p);

boolean esFinPartida(Partida p);

#endif
