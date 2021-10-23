#ifndef _INFO_HPP_
#define _INFO_HPP_
#include <string>
#include <map>
#include <vector>
void imprimeCabecalho();
void imprimePalavra(std::string palavra, std::map<char, bool> chutes);
void imprimeErros(std::vector<char> erros);
void informacoes(std::vector<char> erros, std::string palavra, std::map<char, bool> chutes);
void mensagemVitoria();
void mensagemDerrota();
void imprimeBoneco();
#endif