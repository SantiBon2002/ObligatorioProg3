#include "Jugador.h"

void creaJugador(Jugador &j)
{
    j = new jugador;
}
//Destructor
void elimJugador(Jugador &j)
{
    delete j;
}
//Selectoras y acceso a miembros
void setCiJugador(int ci, Jugador &j)
{
    j->ci = ci;
}
//PreCondicion: nrojugador < N
void setNroJugador(int nrojugador, Jugador &j)
{
    j->nrojugador = nrojugador;
}
//PreCondicion: nombre/apellido NOT NULL
void setNomApeJugador(strings nombre, strings apellido, Jugador &j)
{
    strcop(j->nombre, nombre);
    strcop(j->apellido, apellido);
}
//PreCondicion: locproc NOT NULL
void setLocProcJugador(strings locproc, Jugador &j)
{
    strcop(j->locproc, locproc);
}
//PreCondicion: partdisp < N-1
void setPartDispJugador(int partdisp, Jugador &j)
{
    j->partdisp = partdisp;
}
//PreCondicion: partgan < N-1
void setPartGanJugador(int partgan, Jugador &j)
{
    j->partgan = partgan;
}

int getCiJugador(Jugador j)
{
    return j->ci;
}
int getNroJugador(Jugador j)
{
    return j->nrojugador;
}
void getNombreJugador(Jugador j,strings &nombre)
{
    strcop(nombre, j->nombre);
}
void getApellidoJugador(Jugador j,strings &apellido)
{
    strcop(apellido, j->apellido);
}
void getLocProcJugador(Jugador j, strings &locproc)
{
    strcop(locproc, j->locproc);
}
int getPartDispJugador(Jugador j)
{
    return j->partdisp;
}
int getPartGanJugador(Jugador j)
{
    return j->partgan;
}

void addPartDispJugador(Jugador &j)
{
    j->partdisp++;
}

void addPartGanJugador(Jugador &j)
{
    j->partgan++;
}

void mostrarJugador(Jugador j)
{
    strings nombre, apellido, locproc;

    getNombreJugador(j, nombre);
    getApellidoJugador(j, apellido);
    getLocProcJugador(j, locproc);
    printf("\n-------------<Jugador NRO %i>-------------", getNroJugador(j));
    printf("\nCI: %i", getCiJugador(j));
    printf("\nNombre: ");
    print(nombre);
    printf("\nApellido: ");
    print(apellido);
    printf("\nLocalidad de procedencia: ");
    print(locproc);
    printf("\nCantidad de partidas disputadas: %i", getPartDispJugador(j));
    printf("\nCantidad de partidas ganadas: %i\n", getPartGanJugador(j));

}
