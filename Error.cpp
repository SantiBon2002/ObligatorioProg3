#include "Error.h"

void mostrarError(tipo_error T_err)
{
    switch(T_err)
    {
    case ERR_PARAMS:
        printf("\nCantidad de Parametros Incorrectos!\n");
        break;
    case ERR_REG_CI:
        printf("\nEsta Cedula YA esta Registrada!\n");
        break;
    case ERR_CI:
        printf("\nVerifique la Cedula Ingresada!\n");
        break;
    case ERR_PARTIDA:
        printf("\nPartida ya fue Iniciada!\n");
        break;
    case ERR_JUG1_INEX:
        printf("\nEl jugador 1 es inexistente!\n");
        break;
    case ERR_JUG2_INEX:
        printf("\nEl jugador 2 es inexistente!\n");
        break;
    case ERR_JUG_MISM:
        printf("\nNO se Puede Jugar con UNO Mismo!\n");
        break;
    case ERR_PART_INEX:
        printf("\nEl Numero de Partida NO Existe!\n");
        break;
    case ERR_PART_FIN:
        printf("\nEsta Partida YA fue Finalizada!\n");
        break;
    case ERR_CI_NOCOIN:
        printf("\nCedula de Identidad NO Coincide!\n");
        break;
    case ERR_COMNOENC:
        printf("\nERROR! Comando no Encontrado!\n");
        break;
    case ERR_PART_SIN_INIC:
        printf("\nHay partidas sin iniciar.\n");
        break;
    case ERR_PART_SIN_FIN:
        printf("\nHay partidas sin finalizar.\n");
        break;
     case ERR_OPC_INCORR:
        printf("\nError, opcion inexistente!\n");
        break;

    }
    PBorr();
    fflush(stdin);
}

void PBorr()
{
    printf("\n");
    system("pause");
    system("cls");
}

void Borr()
{
    system("cls");
}
