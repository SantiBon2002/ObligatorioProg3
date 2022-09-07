#include "DiccJugadores.h"

//funcion de hashing
int h(int ci)
{
    ci = ci/10; //descartamos el digito verificador
	return ci%N;
}

void crearDiccJugadores(DiccJugadores &dj)
{
    for (int i=0; i<N; i++)
        {
            dj[i]=NULL;
        }
}

boolean isInDiccJugadores(DiccJugadores dj, int ci)
{
    int bucket = h(ci);
    return isInLJugadores(ci, dj[bucket]);
}

//inserta un jugador en el hash, en la cubeta que corresponde y al frente de la lista
void insJugadorDiccJugadores(Jugador j, DiccJugadores &dj)
{
    int bucket = h(j->ci);
    insFLJugadores(j, dj[bucket]);
}

Jugador getJugadorDiccJugadores(DiccJugadores dj, int ci)
{
    int bucket = h(ci);
    return getJugadorLJugadores(ci, dj[bucket]);
}

void listarDiccJugadores(DiccJugadores dj)
{
    for (int i=0; i < N; i++)
    {
        if (dj[i])
            listarLJugadores(dj[i]);
    }
}

//obtiene en valor maximo de partidas ganadas en todo el dicc de jugadores
int getMaxPGDiccJugadores(DiccJugadores dj)
{
    int maxPG=0;

    for (int pg, bucket=0; bucket<N; bucket++)
    {
        if (dj[bucket]) //si hay algo en esta cubeta
        {
          pg = getMaxPGLJugadores(dj[bucket]);
          if (pg > maxPG)
            maxPG = pg; //si es mayor q el max lo cambio
        }
    }
    return maxPG;
}

//lista en pantalla los jugadores con nro de part ganadas igual a maxpgan
void listarGanadoresDiccJugadores(DiccJugadores dj, int maxpgan)
{
    for (int bucket=0; bucket<N; bucket++) //recorro todo el diccionario
    {
        if (dj[bucket]) //si hay algo en la cubeta
          listarGanLJugadores(dj[bucket], maxpgan); //listo los que tienen ese score
    }
}
