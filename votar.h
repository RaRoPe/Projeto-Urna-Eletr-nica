#include <stdbool.h>

#ifndef INTERFACE_H

void votar_estadual(int8_t estado, char CPF[12]);
void votar_federal(int32_t codigo_candidato_regional, int8_t partido_regional, int8_t estado, char CPF[12]);
void votar(char CPF[12]);

#endif
