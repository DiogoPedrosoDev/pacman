#pragma once
#include "BaseEntidades.h"

#include "allegro5/allegro.h"
#include "allegro5/allegro_image.h"

#ifndef INIMIGOS_H
#define INIMIGOS_H

class Inimigos :public BaseEntidades
{
	public:
		Inimigos();
		Inimigos(int, int, ALLEGRO_BITMAP*);

		void CalcularPosicaoInimigos();

		float GetInimigosX();
		float GetInimigosY();

		void SetInimigosX(float);
		void SetInimigosY(float);

		bool ColisaoInimigos(vector<vector<char>>&);

		bool ColisaoInimigosCima(vector<vector<char>>&);
		bool ColisaoInimigosBaixo(vector<vector<char>>&);
		bool ColisaoInimigosDireita(vector<vector<char>>&);
		bool ColisaoInimigosEsquerda(vector<vector<char>>&);

		virtual void SorteioDirecao(vector<vector<char>>&, float, float);

		void ComandosInimigos(vector<vector<char>>&);
		void MovimentacaoInimigos(vector<vector<char>>&, bool status);

		void DesenhaInimigos(int, int);

		~Inimigos();
	protected:
		ALLEGRO_BITMAP* inimigo;

		//Variaveis de Tamanho da Sprite
		int Altura;
		int Largura;

		//Variaveis de Direcao
		bool Cima, Direita, Baixo, Esquerda;
		int lado;

		int Instrucao;
};

#endif