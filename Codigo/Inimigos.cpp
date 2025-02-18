#include "Inimigos.h"

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#include<time.h>

using namespace std;

Inimigos::Inimigos()
{
    inimigo = NULL;

    //Altura e Largura da Sprite
    Altura = 30;
    Largura = 30;

    //Variaveis de Direcao
    Cima = false;
    Direita = false;
    Baixo = false;
    Esquerda = false;

    lado = 0;

    Instrucao = 0;

}

Inimigos::Inimigos(int x, int y, ALLEGRO_BITMAP* bmpInimigo):BaseEntidades(x, y)
{
    inimigo = bmpInimigo;

    //Altura e Largura da Sprite
    Altura = 30;
    Largura = 30;

    //Variaveis de Direcao
    Cima = false;
    Direita = false;
    Baixo = false;
    Esquerda = false;

    lado = 0;

    Instrucao = 0;


}

void Inimigos::CalcularPosicaoInimigos() {
    BaseEntidades::CalcularPosicao();
}

float Inimigos::GetInimigosX() {
    return BaseEntidades::GetPosicaoX();
}
float Inimigos::GetInimigosY() {
    return BaseEntidades::GetPosicaoY();
}
void Inimigos::SetInimigosX(float x) {
    BaseEntidades::SetPosicaoX(x);
}
void Inimigos::SetInimigosY(float y) {
    BaseEntidades::SetPosicaoY(y);
}

bool Inimigos::ColisaoInimigos(vector<vector<char>>& mapa) {
    return BaseEntidades::ColisaoEntidade(mapa);
}

bool Inimigos::ColisaoInimigosCima(vector<vector<char>>& mapa) {
    return BaseEntidades::ColisaoCima(mapa);
}
bool Inimigos::ColisaoInimigosBaixo(vector<vector<char>>& mapa) {
    return BaseEntidades::ColisaoBaixo(mapa);
}
bool Inimigos::ColisaoInimigosDireita(vector<vector<char>>& mapa) {
    return BaseEntidades::ColisaoDireita(mapa);
}
bool Inimigos::ColisaoInimigosEsquerda(vector<vector<char>>& mapa) {
    return BaseEntidades::ColisaoEsquerda(mapa);
}

void Inimigos::SorteioDirecao(vector<vector<char>>& mapa, float PacmanX, float PacmanY) {
 
}

void Inimigos::ComandosInimigos(vector<vector<char>>& mapa) {
    //Cima
    if (Instrucao == ALLEGRO_KEY_UP && ColisaoInimigosCima(mapa) == true && Baixo != true && Cima != true)
    {
        Cima = true;
        Baixo = false;
        Esquerda = false;
        Direita = false;
        lado = 2;
    }
    //Baixo
    if (Instrucao == ALLEGRO_KEY_DOWN && ColisaoInimigosBaixo(mapa) == true && Cima != true && Baixo != true)
    {
        Baixo = true;
        Cima = false;
        Esquerda = false;
        Direita = false;
        lado = 3;
    }
    //Esquerda
    if (Instrucao == ALLEGRO_KEY_LEFT && ColisaoInimigosEsquerda(mapa) == true && Direita != true && Esquerda != true)
    {
        Esquerda = true;
        Cima = false;
        Baixo = false;
        Direita = false;
        lado = 1;
    }
    //Direita
    if (Instrucao == ALLEGRO_KEY_RIGHT && ColisaoInimigosDireita(mapa) == true && Esquerda != true && Direita != true)
    {
        Direita = true;
        Cima = false;
        Baixo = false;
        Esquerda = false;
        lado = 0;
    }
}

void Inimigos::MovimentacaoInimigos(vector<vector<char>>& mapa, bool status) {

    if (status == false)
    {
        //Executa a movimentacao

        //Movimetacao para Cima
        if (Cima == true && ColisaoInimigosCima(mapa) == true) { 
            SetInimigosY(GetInimigosY() - 1.5);
        }

        //Movimentacao para Baixo
        if (Baixo == true && ColisaoInimigosBaixo(mapa) == true) { 
            SetInimigosY(GetInimigosY() + 1.5);
        }

        //Movimentacao para Esquerda
        if (Esquerda == true && ColisaoInimigosEsquerda(mapa) == true) { 
            SetInimigosX(GetInimigosX() - 1.5);
        }

        //Movimentacao para Direita
        if (Direita == true && ColisaoInimigosDireita(mapa) == true) { 
            SetInimigosX(GetInimigosX() + 1.5);
        }
    }
}

void Inimigos::DesenhaInimigos(int sprite, int tipo) {
    al_draw_bitmap_region(inimigo, tipo * Largura, 0 * Altura, Largura, Altura, BaseEntidades::GetPosicaoX(), BaseEntidades::GetPosicaoY(), 0);
}


Inimigos::~Inimigos()
{
    al_destroy_bitmap(inimigo); //Destroi a tela
}


