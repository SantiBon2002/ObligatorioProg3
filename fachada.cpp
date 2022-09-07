#include "fachada.h"

void inicio(){
    DiccJugadores dj;
    Partidas partAct;
    Torneo torneo;

    crearDiccJugadores(dj);
    cargarDicc(dj);
    crearPartidas(partAct);
    crearTorneo(torneo);

    menu(dj, partAct, torneo);
}

void menu(DiccJugadores &dj, Partidas &partAct, Torneo &torneo) {
    int op;

    do{
        system("cls");
        printf("===============[ OPCIONES ]===============");
        printf("\n\n1 -> Iniciar partida entre Jugadores\n2 -> Finalizar partida\n3 -> Listar partidas\n4 -> Listar jugadores\n5 -> Mostrar jugador\n6 -> Resultados del Torneo\n0 -> Salir\n\n");
        printf("==========================================\n\n");
        scanf("%i", &op);
        Borr();
        switch (op){
        case 1:
            printf("===========[ Iniciar partida ]===========\n\n");
            iniciarPartida(dj, partAct, torneo);
            break;
        case 2:
            printf("==========[ Finalizar partida ]==========\n\n");
            finalizarPartida(dj, partAct);
            break;
        case 3:
            printf("=========[ Partidas registradas ]=========\n\n");
            listarPartidas(partAct);
            PBorr();
            break;
        case 4:
            printf("========[ Jugadores registrados ]========\n");
            listarDiccJugadores(dj);
            PBorr();
            break;
        case 5:
            printf("========[ Jugador y sus rivales ]========\n\n");
            listarJugYRival(dj, partAct, torneo);
            break;
        case 6:
            printf("=============[ Resultados ]=============\n");
            finalTorneo(dj, torneo, partAct);
            break;
        case 0:
            break;
        default:
            mostrarError(ERR_OPC_INCORR);
            break;
        }

    }while(op != 0);
}

void iniciarPartida(DiccJugadores dj, Partidas &actPart, Torneo &torneo)
{
    int ci1, ci2;
    Jugador j1, j2;
    printf("Ingrese la Cedula del Jugador 1: ");
    scanf("%i", &ci1);
    if (isInDiccJugadores(dj, ci1)) {
    printf("\nIngrese la Cedula del Jugador 2: ");
    scanf("%i", &ci2);
    if (ci1 != ci2) {
            if (isInDiccJugadores(dj, ci2)) {
                j1 = getJugadorDiccJugadores(dj, ci1);
                j2 = getJugadorDiccJugadores(dj, ci2);

                if (!existePartida(getNroJugador(j1), getNroJugador(j2), torneo))
                {
                    Partida p;
                    crearPartida(p);
                    setJugadoresPartida(ci1, ci2, p);
                    setNroPartida(getNroPartidas(actPart), p);//el nro de partida es el tope del act antes de la insercion
                    insPartida(getNroJugador(j1), getNroJugador(j2), getNroPartidas(actPart), torneo); //inserto en el grafo
                    insPartidas(p, actPart); //inserto en el ACT
                    addPartDispJugador(j1); //incremento contador de partidas disputadas
                    addPartDispJugador(j2);
                }
                else
                    mostrarError(ERR_PARTIDA);
            }
            else
                mostrarError(ERR_JUG2_INEX);
        }
        else
            mostrarError(ERR_JUG_MISM);
    }else
        mostrarError(ERR_JUG1_INEX);
}

void finalizarPartida(DiccJugadores dj, Partidas partAct)
{
    Partida p;
    int nropartida;
    printf("Ingrese el numero de partida a FINALIZAR: ");
    scanf("%i", &nropartida);

    if( (nropartida >= 0) &&(nropartida < getNroPartidas(partAct))) //siempre se cumple 0<=nropartida<tope
    {
        p = getPartPartidas(partAct, nropartida); //obtengo la partida solicitada
        if (!esFinPartida(p)) //si aun no fue marcada como finalizada
        {
            int ciwin, ci1, ci2;
            printf("\nIngrese la Cedula del GANADOR: ");
            scanf("%i", &ciwin);
            getCiJugadoresPartida(p, ci1, ci2); //obtengo las 2 ci
            if(ciwin == ci1 || ciwin == ci2)
            {
                Jugador j = getJugadorDiccJugadores(dj, ciwin);
                setFinalPartida(ciwin, p);
                addPartGanJugador(j);
            }
            else
                mostrarError(ERR_CI_NOCOIN);
        }
        else
            mostrarError(ERR_PART_FIN);
    }
    else
        mostrarError(ERR_PART_INEX);
}

void listarPartidas(Partidas partAct)
{
    Partida p;
    int ci1, ci2;
    for (int i=0; i<getNroPartidas(partAct); i++)
    {
        printf("-------------<Partida NRO %i>-------------\n", i);
        p = getPartPartidas(partAct, i);
        getCiJugadoresPartida(p, ci1, ci2);
        printf("CI Jugador 1: %i\n", ci1);
        printf("CI Jugador 2: %i\n", ci2);
        if (esFinPartida(p))
            printf("El ganador fue: Jugador %i\n\n", (ci1==getGanadorPartida(p))?1:2);
        else
            printf("Partida todavia en juego.\n");

        printf("\n");
    }
}

void listarJugYRival(DiccJugadores dj, Partidas partAct, Torneo torneo)
{
    int ci;
    Jugador j, j2;
    printf("Ingrese una Cedula de Jugador: ");
    scanf("%i", &ci);
    if (isInDiccJugadores(dj, ci))
    {
        j = getJugadorDiccJugadores(dj, ci);
        mostrarJugador(j);
        printf("\n===============[ Rivales ]===============\n");
        int jugador = getNroJugador(j);
        for (int rival = 0; rival < N; rival++)
        {
            if (rival != jugador)
                if (existePartida(jugador, rival, torneo))
                {
                    int nropart = getNroPartidaTorneo(jugador, rival, torneo);
                    Partida p = getPartPartidas(partAct, nropart);
                    int ci1, ci2;
                    getCiJugadoresPartida(p, ci1, ci2);
                    if (ci == ci1) {
                        j2 = getJugadorDiccJugadores(dj, ci2);
                        mostrarJugador(j2);
                    }
                    else {
                        j2 = getJugadorDiccJugadores(dj, ci1);
                        mostrarJugador(j2);
                    }
                }
        }
        PBorr();
    }
}

void cargarDicc(DiccJugadores &dj) {

    int ci;
    strings nombre;
    strings apellido;
	strings locproc;

    for(int i = 0; i < N; i++){
        ci = 0;
        boolean existe = True;
        do{
            fflush(stdin);
            printf("Ingrese cedula del jugador %i: \n", i);
            scanf("%i", &ci);\
            if (ci > 0)
                if (isInDiccJugadores(dj, ci))
                    mostrarError(ERR_REG_CI); //YA esta Registrada
                else
                    existe = False;
            else
                mostrarError(ERR_CI);
        }while(existe);

        printf("Ingrese nombre del jugador %i\n", i);
        scan(nombre);

        printf("Ingrese apellido del jugador %i\n", i);
        scan(apellido);

        printf("Ingrese localidad del jugador %i\n", i);
        scan(locproc);

        //cuando tengo todos los datos, creo y lleno el objeto jugador
        //luego lo inserto en el diccionario
        Jugador j;
        creaJugador(j);
        setCiJugador(ci, j);
        setNomApeJugador(nombre, apellido, j);
        setLocProcJugador(locproc, j);
        setNroJugador(i, j);
        setPartDispJugador(0, j);
        setPartGanJugador(0, j);
        insJugadorDiccJugadores(j, dj);
        system("cls");
    }

}

void finalTorneo(DiccJugadores dj, Torneo t, Partidas partAct)
{
    if (isFullPartidas(partAct)) //1ero veo si ya se iniciaron todas las partidas
      if (isFinPartidas(partAct)) //2do si todas las partidas ya finalizaron
      {
          int maxpgan = getMaxPGDiccJugadores(dj); //veo cual es el max score de partidas ganadas
          listarGanadoresDiccJugadores(dj, maxpgan); //listo en pantalla todos los que tienen esa cant de part ganadas
          PBorr();
      }
      else
        mostrarError(ERR_PART_SIN_FIN);
    else
      mostrarError(ERR_PART_SIN_INIC);
}

void dispJugador(DiccJugadores dj)
{
    int ci;
    printf("Introduzca la Cedula a Buscar: ");
    scanf("%i", &ci);
    if(isInDiccJugadores(dj, ci))
       mostrarJugador(getJugadorDiccJugadores(dj, ci));
    else
        mostrarError(ERR_CI_NOCOIN);
}
