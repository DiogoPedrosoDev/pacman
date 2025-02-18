#pragma once
#include "Inimigos.h"

#ifndef MOVIMENTACAOALEATORIA_H
#define MOVIMENTACAOALEATORIA_H

class MovimentacaoAleatoria : public Inimigos
{

	public:
		MovimentacaoAleatoria();
		MovimentacaoAleatoria(int, int, ALLEGRO_BITMAP*);

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

		~MovimentacaoAleatoria();

};

#endif