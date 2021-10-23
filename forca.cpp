#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <map>
#include <vector>
#include "forca.hpp"
#include "informacoes.hpp"
#include "color.hpp"

using namespace std;

const string PALAVRA_SECRETA = escolhePalavra();
map<char, bool> chutes;
vector<char> erros;

bool comecaJogo() {
    cout << "Quer começar?? (S/N) ";
    char resposta;
    cin >> resposta;
    return (resposta == 'S' ? true : false);
}

bool ganhou() {
    for(char letra : PALAVRA_SECRETA) {
        if(!chutes[letra]) return false;
    } return true;
}

bool enforcou() {
    if(erros.size() > 4) return true;
    return false;
}

string escolhePalavra() {
    ifstream f;
    int numeroPalavras;
    f.open("PALAVRAS.txt");

    f >> numeroPalavras;  

    string palavra;
    int numeroAleatorio = rand() % numeroPalavras;
    for(int i = 0; i <= numeroAleatorio; i++) {
        f >> palavra;
    }

    f.close();

    return palavra;
}

void chuta() {
    cout << "Qual o seu chute?: ";
    char chute;
    cin >> chute;
    if(!verificaChute(chute)) erros.push_back(chute);
    chutes[chute] = true;
}

bool verificaChute(char chute) {
    for(char letra : PALAVRA_SECRETA) {
        if(letra == chute) return true;
    }
    return false;
}

int main() {
    system(LIMPA);
    imprimeCabecalho();
    if(!comecaJogo()) return 0;
    do {
        system(LIMPA);
        informacoes(erros, PALAVRA_SECRETA, chutes);
        chuta();
    } while (!enforcou() && !ganhou());
    system(LIMPA);
    imprimeCabecalho();
    cout << "A palavra secreta era: " << PALAVRA_SECRETA << endl << endl;
    if(ganhou()) mensagemVitoria();
    else mensagemDerrota();
}