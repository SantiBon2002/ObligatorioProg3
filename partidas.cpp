#include "Partidas.h"

void crearPartidas(Partidas &P)
{
    P.tope = 0;
}

void insPartidas(Partida p, Partidas& P)
{
    P.part[P.tope] = p;
    P.tope++;
}

int getNroPartidas(Partidas P)
{
    return P.tope;
}

Partida getPartPartidas(Partidas P, int nropart)
{
    return P.part[nropart];
}

boolean isFullPartidas(Partidas P)
{
    return (P.tope < N)? False:True;
}

boolean isFinPartidas(Partidas P)
{
    boolean fin = True;
    int i = 0;

    do
    {
        if (!esFinPartida(P.part[i]))
            fin = False;
        else
            i++;
    }while(i<MAXPART && fin);
    return fin;
}
