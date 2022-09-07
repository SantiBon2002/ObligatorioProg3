#include "partida.h"

void crearPartida(Partida &p)
{
    p = new partida;
    p->finalizada = False;
}

void elimPartida(Partida &p)
{
    delete p;
    p = NULL;
}

void setNroPartida(int nropartida, Partida &p)
{
    p->nropartida = nropartida;
}

void setJugadoresPartida(int ci1, int ci2, Partida &p)
{
    p->ci1 = ci1;
    p->ci2 = ci2;
}

void setFinalPartida(int ciwin, Partida &p)
{
    p->ciwin = ciwin;
    p->finalizada = True;
}

int getNroPartida(Partida p)
{
    return p->nropartida;
}

void getCiJugadoresPartida(Partida p, int &ci1, int &ci2)
{
    ci1 = p->ci1;
    ci2 = p->ci2;
}

int getGanadorPartida(Partida p)
{
    return p->ciwin;
}

boolean esFinPartida(Partida p)
{
    return p->finalizada;
}
