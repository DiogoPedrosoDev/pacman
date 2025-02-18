#include <iostream>
#include <vector>

#ifndef BASEENTIDADES_H
#define BASEENTIDADES_H

using namespace std;

class BaseEntidades
{
    public:
        BaseEntidades();
        BaseEntidades(int, int);

        void CalcularPosicao();

        float GetPosicaoX();
        float GetPosicaoY();

        void SetPosicaoX(float x);
        void SetPosicaoY(float y);

        int GetPosicaoXMatriz();
        int GetPosicaoYMatriz();

        bool ColisaoEntidade(vector<vector<char>>& mapa);

        bool ColisaoCima(vector<vector<char>>& mapa);
        bool ColisaoBaixo(vector<vector<char>>& mapa);
        bool ColisaoDireita(vector<vector<char>>& mapa);
        bool ColisaoEsquerda(vector<vector<char>>& mapa);

        ~BaseEntidades();

    private:
        //Posicao Entidade Px
        float EntidadeX;
        float EntidadeY;

        //Entidade Matriz
        int EntidadeColisaoX;
        int EntidadeColisaoY;

        //Cima
        int CimaX, CimaY;
        int CimaAredondadoX, CimaAredondadoY;

        //Baixo
        int BaixoX, BaixoY;
        int BaixoAredondadoX, BaixoAredondadoY;

        //Direita
        int DireitaX, DireitaY;
        int DireitaAredondadoX, DireitaAredondadoY;

        //Esquerda
        int EsquerdaX, EsquerdaY;
        int EsquerdaAredondadoX, EsquerdaAredondadoY;
};
#endif
