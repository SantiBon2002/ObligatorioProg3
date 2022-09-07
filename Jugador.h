#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

#include "strings.h"

typedef struct {
				int ci;
				int nrojugador;
				strings nombre;
				strings apellido;
				strings locproc;
				int partdisp;
				int partgan;
				} jugador;
typedef jugador* Jugador;


//Constructor
//Crea una variable Jugador dinámicamente
//queda SIN INICIALIZAR
void creaJugador(Jugador &j);
//Destructor
void elimJugador(Jugador &j);
//Selectoras y acceso a miembros
void setCiJugador(int ci, Jugador &j);
//PreCondicion: nrojugador < N
void setNroJugador(int nrojugador, Jugador &j);
//PreCondicion: nombre/apellido NOT NULL
void setNomApeJugador(strings nombre, strings apellido, Jugador &j);
//PreCondicion: locproc NOT NULL
void setLocProcJugador(strings locproc, Jugador &j);
//PreCondicion: partdisp < N-1
void setPartDispJugador(int partdisp, Jugador &j);
//PreCondicion: partgan < N-1
void setPartGanJugador(int partgan, Jugador &j);


int getCiJugador(Jugador j);
int getNroJugador(Jugador j);
void getNombreJugador(Jugador j,strings &nombre);
void getApellidoJugador(Jugador j,strings &apellido);
void getLocProcJugador(Jugador j, strings &locproc);
int getPartDispJugador(Jugador j);
int getPartGanJugador(Jugador j);

void addPartDispJugador(Jugador &j);
void addPartGanJugador(Jugador &j);

void mostrarJugador(Jugador j);

#endif // JUGADOR_H_INCLUDED
