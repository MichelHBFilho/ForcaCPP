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

void imprimeErros(vector<char> erros) {
    cout << "Chutes errados: ";
    for(char erro : erros) {
        cout << erro << " ";
    } cout << endl;
}

void imprimePalavra(string palavra, map<char, bool> chutes) {
    for(char letra : palavra) {
        if(chutes[letra]) {
            cout << letra;
        } else {
            cout << "_";
        }
        cout << " ";
    } cout << endl;
}

void imprimeBoneco(vector<char> erros) {
    if(erros.size() >= 4) {
        cout << " +---+   " << endl;
        cout << " |   |   " << endl;
        cout << " O   |   " << endl;
        cout << "/|\\  |   " << endl;
        cout << "/ \\  |   " << endl;
        cout << "     |   " << endl;
        cout << "=========" << endl;
    } else if(erros.size() >= 3) {
        cout << " +---+   " << endl;
        cout << " |   |   " << endl;
        cout << " O   |   " << endl;
        cout << "/|\\  |   " << endl;
        cout << "     |   " << endl;
        cout << "     |   " << endl;
        cout << "=========" << endl;
    } else if(erros.size() >= 2) {
        cout << " +---+   " << endl;
        cout << " |   |   " << endl;
        cout << " O   |   " << endl;
        cout << " |   |   " << endl;
        cout << "     |   " << endl;
        cout << "     |   " << endl;
        cout << "=========" << endl;
    } else if(erros.size() >= 1) {
        cout << " +---+   " << endl;
        cout << " |   |   " << endl;
        cout << " O   |   " << endl;
        cout << "     |   " << endl;
        cout << "     |   " << endl;
        cout << "     |   " << endl;
        cout << "=========" << endl;
    } else if(erros.size() >= 0) {
        cout << " +---+   " << endl;
        cout << " |   |   " << endl;
        cout << "     |   " << endl;
        cout << "     |   " << endl;
        cout << "     |   " << endl;
        cout << "     |   " << endl;
        cout << "=========" << endl;
    }
}

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
    cout << endl << "--------------------------------------" << endl;
    cout << endl << endl;
}

void informacoes(vector<char> erros, string palavra, map<char, bool> chutes) {
    imprimeCabecalho();
    imprimeErros(erros);
    imprimeBoneco(erros);
    imprimePalavra(palavra, chutes);
}

void mensagemVitoria() {
    cout << col::yellow << "PARABENS!!! Você venceu" << col::off << endl << endl;
    cout << col::green;
    cout << "░░░░░░░░░░░░░░░▄▄" << endl;
    cout << "░░░░░░░░░░░░░░▐▓▓▌" << endl;
    cout << "░░░░░░░░░░░░░▐▓▓▓▌" << endl;
    cout << "░░░░░░░░░░░░▐▓▓▓▓▌" << endl;
    cout << "▄▄▄▄▄▄▄▄▄▄▄█▓▓▓▓▓█▄▄▄▄▄" << endl;
    cout << "▓▓▓▓▓▓▓▓█░░░░░░░░░░░▓▓▓▌" << endl;
    cout << "▓▓▓▓▓▓▓▓█░░░░▓▓▓░░░░▓▓▓▌" << endl;
    cout << "▓▓▓▓▓▓▓▓█░░░░▓▓▓░░░░▓█▀" << endl;
    cout << "▓▓▓▓▓▓▓▓█░░░░▓▓▓░░░░▓▌" << endl;
    cout << "▓▓▓▓▓▓▓▓█░░░░░░░░░░░▓▌" << endl;
    cout << "▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀" << endl;
    cout << col::off;
}

void mensagemDerrota() {
    cout << col::red << "Você perdeu, tente novamente" << col::off << endl << endl;

    cout << "HAHAHA PERDEDOR" << endl;
    cout << "──────▄▀▄─────▄▀▄" << endl;
    cout << "─────▄█░░▀▀▀▀▀░░█▄" << endl;
    cout << "─▄▄──█░░░░░░░░░░░█──▄▄" << endl;
    cout << "█▄▄█─█░░▀░░┬░░▀░░█─█▄▄█" << endl;
}