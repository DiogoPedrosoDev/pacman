#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "Pacman.h"

using namespace std;

Pacman::Pacman()
{
    Placar = 0;

    //Altura e Largura
    PacmanAltura = 30;
    PacmanLargura = 30;

    //Direçoes
    up = false;
    right = false;
    down = false;
    left = false;

    //Lado
    lado = 0;

}

Pacman::Pacman(int x, int y):BaseEntidades(x, y)
{
    Placar = 0;

    //Altura e Largura
    PacmanAltura = 30;
    PacmanLargura = 30;

    //Direçoes
    up = false;
    right = false;
    down = false;
    left = false;

    //Lado
    lado = 0;

}

void Pacman::PosicaoPacman() {
    BaseEntidades::CalcularPosicao();
}

bool Pacman::ColisaoPacman(vector<vector<char>>& mapa) {
    return BaseEntidades::ColisaoEntidade(mapa);
}
void Pacman::PacmanPegaPirula(vector<vector<char>>& mapa) {
    if (mapa[getPacmanYMatriz()][getPacmanXMatriz()] == 'P')
    {
        mapa[getPacmanYMatriz()][getPacmanXMatriz()] = 'E';
        Placar++;
    }

}

int Pacman::getPlacar() {
    return Placar;
}

bool Pacman::ColisaoPacmanCima(vector<vector<char>>& mapa) {
    return BaseEntidades::ColisaoCima(mapa);
}
bool Pacman::ColisaoPacmanBaixo(vector<vector<char>>& mapa) {
    return BaseEntidades::ColisaoBaixo(mapa);
}
bool Pacman::ColisaoPacmanDireita(vector<vector<char>>& mapa) {
    return BaseEntidades::ColisaoDireita(mapa);
}
bool Pacman::ColisaoPacmanEsquerda(vector<vector<char>>& mapa) {
    return BaseEntidades::ColisaoEsquerda(mapa);
}

int Pacman::getPacmanXMatriz() {
    return BaseEntidades::GetPosicaoXMatriz();
}
int Pacman::getPacmanYMatriz() {
    return BaseEntidades::GetPosicaoYMatriz();
}

float Pacman::getPacmanX() {
    return BaseEntidades::GetPosicaoX();
}
float Pacman::getPacmanY() {
    return BaseEntidades::GetPosicaoY();
}
void Pacman::setPacmanX(float X) {
    return BaseEntidades::SetPosicaoX(X);
}
void Pacman::setPacmanY(float Y) {
    return BaseEntidades::SetPosicaoY(Y);
}

void Pacman::ComandosPacman(int Comando, vector<vector<char>>& mapa) {
    // Cima
    if (Comando == ALLEGRO_KEY_UP && ColisaoPacmanCima(mapa) == true)
    {
        up = true;
        down = false;
        right = false;
        left = false; 
    }
    //Baixo
    if (Comando == ALLEGRO_KEY_DOWN && ColisaoPacmanBaixo(mapa) == true)
    {
        up = false;
        down = true;
        right = false;
        left = false; 
    }
    //Direita
    if (Comando == ALLEGRO_KEY_RIGHT && ColisaoPacmanDireita(mapa) == true)
    {
        up = false;
        down = false;
        right = true;
        left = false;

        lado = 1;
    }
    //Esquerda
    if (Comando == ALLEGRO_KEY_LEFT && ColisaoPacmanEsquerda(mapa) == true)
    {
        up = false;
        down = false;
        right = false;
        left = true;

        lado = 0;
    }
}

void Pacman::MovimentacaoPacman(vector<vector<char>>& mapa) {

    //Movimentação
    
    // Cima
    if (up == true && ColisaoPacmanCima(mapa) == true) 
    { 
        setPacmanY(getPacmanY() - 2.0);
    }
    //Baixo
    if (down == true && ColisaoPacmanBaixo(mapa) == true)
    { 
        setPacmanY(getPacmanY() + 2.0);
    }
    //Direita
    if (right == true && ColisaoPacmanDireita(mapa) == true)
    {
        setPacmanX(getPacmanX() + 2.0);
    }
    //Esquerda
    if (left == true && ColisaoPacmanEsquerda(mapa) == true) 
    { 
        setPacmanX(getPacmanX() - 2.0);
    }  
}

void Pacman::DesenhaPacman(int sprite, ALLEGRO_BITMAP* ImgPacman) {
    al_draw_bitmap_region(ImgPacman, sprite * PacmanLargura, lado * PacmanAltura, PacmanLargura, PacmanAltura, getPacmanX(), getPacmanY(), 0);
}

Pacman::~Pacman()
{

}

