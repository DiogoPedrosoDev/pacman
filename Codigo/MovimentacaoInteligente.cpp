#include "MovimentacaoInteligente.h"

MovimentacaoInteligente::MovimentacaoInteligente()
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

MovimentacaoInteligente::MovimentacaoInteligente(int x, int y, ALLEGRO_BITMAP* bmp) : Inimigos(x, y, bmp)
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


void MovimentacaoInteligente::CalcularPosicaoInimigos() {
    Inimigos::CalcularPosicao();
}

float MovimentacaoInteligente::GetInimigosX() {
    return Inimigos::GetPosicaoX();
}
float MovimentacaoInteligente::GetInimigosY() {
    return Inimigos::GetPosicaoY();
}
void MovimentacaoInteligente::SetInimigosX(float x) {
    Inimigos::SetPosicaoX(x);
}
void MovimentacaoInteligente::SetInimigosY(float y) {
    Inimigos::SetPosicaoY(y);
}

bool MovimentacaoInteligente::ColisaoInimigos(vector<vector<char>>& mapa) {
    return Inimigos::ColisaoEntidade(mapa);
}

bool MovimentacaoInteligente::ColisaoInimigosCima(vector<vector<char>>& mapa) {
    return Inimigos::ColisaoCima(mapa);
}
bool MovimentacaoInteligente::ColisaoInimigosBaixo(vector<vector<char>>& mapa) {
    return Inimigos::ColisaoBaixo(mapa);
}
bool MovimentacaoInteligente::ColisaoInimigosDireita(vector<vector<char>>& mapa) {
    return Inimigos::ColisaoDireita(mapa);
}
bool MovimentacaoInteligente::ColisaoInimigosEsquerda(vector<vector<char>>& mapa) {
    return Inimigos::ColisaoEsquerda(mapa);
}

void MovimentacaoInteligente::SorteioDirecao(vector<vector<char>>& mapa, float PacmanX, float PacmanY) {

    int direcoes[] = { ALLEGRO_KEY_LEFT, ALLEGRO_KEY_RIGHT ,ALLEGRO_KEY_UP, ALLEGRO_KEY_DOWN };
    
    int distanciaPacmanX = PacmanX - GetInimigosX();
    int distanciaPacmanY = PacmanY - GetInimigosY();

    if (distanciaPacmanX < distanciaPacmanY)
    {
        if (distanciaPacmanX > 0)
        {
            Instrucao = direcoes[1];
        }
        else if (distanciaPacmanX >= 0)
        {
            if (distanciaPacmanY >= 0)
            {
                Instrucao = direcoes[3];
            }
            else
            {
                Instrucao = direcoes[2];
            }
        }
        else
        {
            Instrucao = direcoes[0];
        }
    }
    else
    {
        if (distanciaPacmanY > 0)
        {
            Instrucao = direcoes[3];
        }
        else if (distanciaPacmanY == 0)
        {
            if (distanciaPacmanX >= 0)
            {
                Instrucao = direcoes[1];
            }
            else
            {
                Instrucao = direcoes[0];
            }
        }
        else
        {
            Instrucao = direcoes[2];
        }
    }

    if (bufferX == GetInimigosX() && bufferY == GetInimigosY())
    {
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

    bufferX = GetInimigosX();

    bufferY = GetInimigosY();
}

void MovimentacaoInteligente::ComandosInimigos(vector<vector<char>>& mapa) {
    Inimigos::ComandosInimigos(mapa);
}

void MovimentacaoInteligente::MovimentacaoInimigos(vector<vector<char>>& mapa, bool status) {

    Inimigos::MovimentacaoInimigos(mapa, status);
}

void MovimentacaoInteligente::DesenhaInimigos(int sprite, int tipo) {
    Inimigos::DesenhaInimigos(sprite, tipo);
}

MovimentacaoInteligente::~MovimentacaoInteligente()
{
}
