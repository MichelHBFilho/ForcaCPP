#ifndef _FORCA_HPP_
#define _FORCA_HPP_
#include <string>

void imprimeCabecalho();
bool comecaJogo();
bool acabou();
std::string escolhePalavra();
void imprimePalavra();
void chuta();
bool verificaChute(char chute);

#endif