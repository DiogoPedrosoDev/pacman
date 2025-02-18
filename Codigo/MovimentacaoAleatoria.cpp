#include "MovimentacaoAleatoria.h"

MovimentacaoAleatoria::MovimentacaoAleatoria()
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

MovimentacaoAleatoria::MovimentacaoAleatoria(int x, int y, ALLEGRO_BITMAP* bmp) : Inimigos(x, y, bmp) 
{
    inimigo = bmp;

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


void MovimentacaoAleatoria::CalcularPosicaoInimigos() {
    Inimigos::CalcularPosicao();
}

float MovimentacaoAleatoria::GetInimigosX() {
    return Inimigos::GetPosicaoX();
}
float MovimentacaoAleatoria::GetInimigosY() {
    return Inimigos::GetPosicaoY();
}
void MovimentacaoAleatoria::SetInimigosX(float x) {
    Inimigos::SetPosicaoX(x);
}
void MovimentacaoAleatoria::SetInimigosY(float y) {
    Inimigos::SetPosicaoY(y);
}

bool MovimentacaoAleatoria::ColisaoInimigos(vector<vector<char>>& mapa) {
    return Inimigos::ColisaoEntidade(mapa);
}

bool MovimentacaoAleatoria::ColisaoInimigosCima(vector<vector<char>>& mapa) {
    return Inimigos::ColisaoCima(mapa);
}
bool MovimentacaoAleatoria::ColisaoInimigosBaixo(vector<vector<char>>& mapa) {
    return Inimigos::ColisaoBaixo(mapa);
}
bool MovimentacaoAleatoria::ColisaoInimigosDireita(vector<vector<char>>& mapa) {
    return Inimigos::ColisaoDireita(mapa);
}
bool MovimentacaoAleatoria::ColisaoInimigosEsquerda(vector<vector<char>>& mapa) {
    return Inimigos::ColisaoEsquerda(mapa);
}

void MovimentacaoAleatoria::SorteioDirecao(vector<vector<char>>& mapa, float PacmanX, float PacmanY) {
    int flag = 0;
    int posibilidades = 0;

    int direcoes[4];

    for (int i = 0; i < 4; i++)
    {
        direcoes[i] = 0;
    }

    if (Esquerda == true)
    {

        //Esquerda
        if (ColisaoInimigosEsquerda(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_LEFT;
            posibilidades++;
        }
        //Cima
        if (ColisaoInimigosCima(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_UP;
            posibilidades++;
        }
        //Botton
        if (ColisaoInimigosBaixo(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_DOWN;
            posibilidades++;
        }

        srand(time(NULL));

        if (posibilidades > 0)
        {
            flag = rand() % posibilidades;

            Instrucao = direcoes[flag];
        }

        else if (posibilidades == 0)
        {
            Instrucao = ALLEGRO_KEY_RIGHT;
        }

    }

    else if (Direita == true)
    {

        //Direita
        if (ColisaoInimigosDireita(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_RIGHT;
            posibilidades++;
        }
        //Cima
        if (ColisaoInimigosCima(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_UP;
            posibilidades++;
        }
        //Botton
        if (ColisaoInimigosBaixo(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_DOWN;
            posibilidades++;
        }

        srand(time(NULL));

        if (posibilidades > 0)
        {
            flag = rand() % posibilidades;

            Instrucao = direcoes[flag];
        }

        else if (posibilidades == 0)
        {
            Instrucao = ALLEGRO_KEY_LEFT;
        }

    }

    else if (Cima == true)
    {

        //Esquerda
        if (ColisaoInimigosEsquerda(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_LEFT;
            posibilidades++;
        }
        //Direita
        if (ColisaoInimigosDireita(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_RIGHT;
            posibilidades++;
        }
        //Cima
        if (ColisaoInimigosCima(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_UP;
            posibilidades++;
        }

        srand(time(NULL));

        if (posibilidades > 0)
        {
            flag = rand() % posibilidades;

            Instrucao = direcoes[flag];
        }

        else if (posibilidades == 0)
        {
            Instrucao = ALLEGRO_KEY_DOWN;
        }

    }

    else if (Baixo == true)
    {

        //Esquerda
        if (ColisaoInimigosEsquerda(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_LEFT;
            posibilidades++;
        }
        //Direita
        if (ColisaoInimigosDireita(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_RIGHT;
            posibilidades++;
        }
        //Botton
        if (ColisaoInimigosBaixo(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_DOWN;
            posibilidades++;
        }

        srand(time(NULL));

        if (posibilidades > 0)
        {
            flag = rand() % posibilidades;

            Instrucao = direcoes[flag];
        }

        else if (posibilidades == 0)
        {
            Instrucao = ALLEGRO_KEY_UP;
        }

    }

    else
    {
        //Esquerda
        if (ColisaoInimigosEsquerda(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_LEFT;
            posibilidades++;
        }
        //Direita
        if (ColisaoInimigosDireita(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_RIGHT;
            posibilidades++;
        }
        //Cima
        if (ColisaoInimigosCima(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_UP;
            posibilidades++;
        }
        //Botton
        if (ColisaoInimigosBaixo(mapa) == true)
        {
            direcoes[posibilidades] = ALLEGRO_KEY_DOWN;
            posibilidades++;
        }

        srand(time(NULL));

        if (posibilidades > 0)
        {
            flag = rand() % posibilidades;

            Instrucao = direcoes[flag];
        }


    }
}

void MovimentacaoAleatoria::ComandosInimigos(vector<vector<char>>& mapa) {
    Inimigos::ComandosInimigos(mapa);
}

void MovimentacaoAleatoria::MovimentacaoInimigos(vector<vector<char>>& mapa, bool status) {

    Inimigos::MovimentacaoInimigos(mapa, status);
}

void MovimentacaoAleatoria::DesenhaInimigos(int sprite, int tipo) {
    Inimigos::DesenhaInimigos(sprite, tipo);
}

MovimentacaoAleatoria::~MovimentacaoAleatoria()
{
}
