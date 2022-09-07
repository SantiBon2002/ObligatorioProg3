#include "ListaJugadores.h"

//insfront en lista Jugadores
void insFLJugadores(Jugador j, LJugadores &LJ)
{
    LJugadores nodo = new Nodo;
    nodo->j = j;
    nodo->sig = LJ;
    LJ = nodo;
}

boolean isInLJugadores(int ci, LJugadores LJ)
{
    boolean esta = False;
    while(LJ && !esta)
    {
        //if (LJ->j->ci == ci)
        if (getCiJugador(LJ->j) == ci)
            esta = True;
        else
            LJ = LJ->sig;
    }
    return esta;
}
//PreCondicion: isInLJugadores(ci,LJ) == True
Jugador getJugadorLJugadores(int ci, LJugadores LJ)
{
    boolean encontre = False;
    do
    {
        //if (LJ->j->ci == ci)
        if (getCiJugador(LJ->j) == ci)
            encontre = True; //si esta en la 1era posicion lo devuelvo, sino voy al siguiente hasta encontrarlo
        else
            LJ = LJ->sig;
    }
    while(LJ && !encontre);

    return LJ->j;
}

//Lista por pantalla una lista de objetos Jugador
void listarLJugadores(LJugadores LJ)
{
    while (LJ)
    {
        mostrarJugador(LJ->j);
        LJ = LJ->sig;
    }
}

//devuelve el valor maximo de partidas ganadas en una lista de Jugadores
int getMaxPGLJugadores(LJugadores LJ)
{
    int maxPG = 0;
    while (LJ)
    {
        int pg = getPartGanJugador(LJ->j);
        if (pg > maxPG)
           maxPG = pg;
        LJ = LJ->sig;
    }
    return maxPG;
}

//Lista en pantalla los jugadores que tengan un nro de partidas ganadas exactamente igual a maxpgan
void listarGanLJugadores(LJugadores LJ, int maxpgan)
{
    while (LJ) //recorro la lista
    {
        if (getPartGanJugador(LJ->j) == maxpgan) //si el score es max
            mostrarJugador(LJ->j); //lo muestro en pantalla
        LJ = LJ->sig;
    }
}
