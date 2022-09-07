#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include "DiccJugadores.h"
#include "Partidas.h"
#include "Torneo.h"
#include "Error.h"

void inicio();

void menu(DiccJugadores &dj, Partidas &partAct, Torneo &torneo);

void iniciarPartida(DiccJugadores dj, Partidas &partAct, Torneo &torneo);

void finalizarPartida(DiccJugadores dj, Partidas partAct); //podria ir en partidaACT.h

void listarPartidas(Partidas partAct); //podria ir en partidaACT.h

void listarJugadores(DiccJugadores dj); //podria ir en DiccJugadores.h

void listarJugYRival(DiccJugadores dj, Partidas partAct, Torneo torneo);

void cargarDicc(DiccJugadores &dj);

void finalTorneo(DiccJugadores dj, Torneo t, Partidas partAct);

void resultadoTorneo(DiccJugadores dj, Partidas partAct, Torneo torneo);

void dispJugador(DiccJugadores dj);

#endif // MENUS_H_INCLUDED
