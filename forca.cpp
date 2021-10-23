#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <map>
#include <vector>
#include "forca.hpp"

using namespace std;

const string PALAVRA_SECRETA = escolhePalavra();
map<char, bool> chutes;
vector<char> erros;

void imprimeCabecalho() {
    cout << "        .-'''-.       " << endl;
    cout << "        /       \\    " << endl;
    cout << "        \\       /    " << endl;
    cout << ".-'''-.-`.-.-.<  _    " << endl;
    cout << "/      _,-\\ ()()_/:) ";
    cout << "  Jogo da forca"        << endl;
    cout << "\\     / ,  `     `|   ";
    cout << "  BY MICHEL FILHO"      << endl;
    cout << "'-..-| \\-.,___,  /    " << endl;
    cout << "    \\ `-.__/  /       " << endl;
    cout << "      `-.__.-'`       " << endl;
    cout << endl << endl;
}

bool comecaJogo() {
    cout << "Quer começar?? (S/N) ";
    char resposta;
    cin >> resposta;
    return (resposta == 'S' ? true : false);
}

bool acabou() {
    return false;
}

string escolhePalavra() {
    return "sofia";
}

void imprimePalavra() {
    for(char letra : PALAVRA_SECRETA) {
        if(chutes[letra]) {
            cout << letra;
        } else {
            cout << "_";
        }
        cout << " ";
    } cout << endl;
}

void imprimeErros() {
    cout << "Chutes errados: ";
    for(char erro : erros) {
        cout << erro << ", ";
    } cout << endl;
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
    system("clear");
    imprimeCabecalho();
    if(!comecaJogo()) return 0;
    do {
        system("clear");
        imprimeCabecalho();
        imprimePalavra();
        imprimeErros();
        chuta();
    } while (!acabou());
}