#pragma once
#include "Inimigos.h"

#ifndef MOVIMENTACAOINTELIGENTE_H
#define MOVIMENTACAOINTELIGENTE_H

class MovimentacaoInteligente : public Inimigos
{
	public:
		MovimentacaoInteligente();
		MovimentacaoInteligente(int, int, ALLEGRO_BITMAP*);

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

		~MovimentacaoInteligente();

	private:
		float bufferX;
		float bufferY;

};

#endif