#ifndef TORNEO_H_INCLUDED
#define TORNEO_H_INCLUDED
#include "boolean.h"
#include "constantes.h"

typedef struct {
                boolean existe;
                int nropartida;
                } nodoT;

typedef nodoT Torneo[N][N];

//Inicializa la matriz sin adyacencias
void crearTorneo(Torneo &T);

//Inserta una partida, o sea una adyacencia entre dos vértices
//PreCondicion: j1,j2 < N && j1,j2>=0
void insPartida(int j1, int j2, int nropart, Torneo &T);

//Verifica si hay una partida en curso o terminada entre dos jugadores
boolean existePartida(int j1, int j2, Torneo T);

int getNroPartidaTorneo(int j1, int j2, Torneo T);


#endif // TORNEO_H_INCLUDED
