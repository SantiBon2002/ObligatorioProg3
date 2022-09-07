#include "torneo.h"

void crearTorneo(Torneo &T)
{
    for (int i=0; i<N; ++i)
        for (int j=0; j<N; ++j)
            T[i][j].existe = False;
}

void insPartida(int j1, int j2, int nropartida, Torneo &T)
{
    T[j1][j2].existe = True;
    T[j1][j2].nropartida = nropartida;
    T[j2][j1].existe = True;
    T[j2][j1].nropartida = nropartida;
 }

boolean existePartida(int j1, int j2, Torneo T)
{
    return T[j1][j2].existe;
}

int getNroPartidaTorneo(int j1, int j2, Torneo T)
{
    return T[j1][j2].nropartida;
}

