#ifndef ERROR_H_INCLUDED
#define ERROR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>

typedef enum {ERR_PARAMS, ERR_REG_CI, ERR_CI, ERR_PARTIDA, ERR_JUG1_INEX, ERR_JUG2_INEX,
               ERR_CI_NOCOIN, ERR_JUG_MISM, ERR_PART_INEX, ERR_PART_FIN, ERR_COMNOENC,
               ERR_PART_SIN_INIC, ERR_PART_SIN_FIN, ERR_OPC_INCORR
             } tipo_error;

void mostrarError(tipo_error T_err);

void PBorr();

void Borr();
#endif // ERROR_H_INCLUDED
