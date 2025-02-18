#include "BaseEntidades.h"

BaseEntidades::BaseEntidades()
{
	//Entidade
	EntidadeX = 30;
	EntidadeY = 30;

	//Entidade Matrix
	EntidadeColisaoX = 0;
	EntidadeColisaoY = 0;

	//Cima
	CimaX = 0;CimaY = 0;
	CimaAredondadoX = 0;CimaAredondadoY = 0;

	//Baixo
	BaixoX = 0;BaixoY = 0;
	BaixoAredondadoX = 0;BaixoAredondadoY = 0;

	//Direita
	DireitaX = 0;DireitaY = 0;
	DireitaAredondadoX = 0;DireitaAredondadoY = 0;

	//Esquerda
	EsquerdaX = 0;EsquerdaY = 0;
	EsquerdaAredondadoX = 0;EsquerdaAredondadoY = 0;
}

BaseEntidades::BaseEntidades(int x, int y)
{
	//Entidade
	EntidadeX = x;
	EntidadeY = y;

	//Entidade Matrix
	EntidadeColisaoX = 0;
	EntidadeColisaoY = 0;

	//Cima
	CimaX = 0; CimaY = 0;
	CimaAredondadoX = 0; CimaAredondadoY = 0;

	//Baixo
	BaixoX = 0; BaixoY = 0;
	BaixoAredondadoX = 0; BaixoAredondadoY = 0;

	//Direita
	DireitaX = 0; DireitaY = 0;
	DireitaAredondadoX = 0; DireitaAredondadoY = 0;

	//Esquerda
	EsquerdaX = 0; EsquerdaY = 0;
	EsquerdaAredondadoX = 0; EsquerdaAredondadoY = 0;
}

void BaseEntidades::CalcularPosicao()
{
	//Entidade
	EntidadeColisaoY = ((EntidadeY) / 30);
	EntidadeColisaoX = ((EntidadeX) / 30);

	//Cima
	CimaY = ceil(((EntidadeY) / 30));
	CimaX = ((EntidadeX) / 30);
	CimaAredondadoY = ceil(((EntidadeY) / 30));
	CimaAredondadoX = ceil(((EntidadeX) / 30));

	//Baixo
	BaixoY = (((EntidadeY) / 30));
	BaixoX = ceil(((EntidadeX) / 30));
	BaixoAredondadoY = (((EntidadeY) / 30));
	BaixoAredondadoX = (((EntidadeX) / 30));

	//Direita
	DireitaY = ceil(((EntidadeY) / 30));
	DireitaX = ((EntidadeX) / 30);
	DireitaAredondadoY = ((EntidadeY) / 30);
	DireitaAredondadoX = ((EntidadeX) / 30);

	//Esquerda
	EsquerdaY = ceil(((EntidadeY) / 30));
	EsquerdaX = ceil(((EntidadeX) / 30));
	EsquerdaAredondadoY = ((EntidadeY) / 30);
	EsquerdaAredondadoX = ceil(((EntidadeX) / 30));
}

float BaseEntidades::GetPosicaoX()
{
	return EntidadeX;
}

float BaseEntidades::GetPosicaoY()
{
	return EntidadeY;
}

void BaseEntidades::SetPosicaoX(float x)
{
	EntidadeX = x;
}

void BaseEntidades::SetPosicaoY(float y)
{
	EntidadeY = y;
}

int BaseEntidades::GetPosicaoXMatriz()
{
	return EntidadeColisaoX;
}

int BaseEntidades::GetPosicaoYMatriz()
{
	return EntidadeColisaoY;
}

bool BaseEntidades::ColisaoEntidade(vector<vector<char>>& mapa)
{
	if (mapa[EntidadeColisaoY][EntidadeColisaoX] != 'T')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BaseEntidades::ColisaoCima(vector<vector<char>>& mapa)
{
	if (mapa[CimaY - 1][CimaX] != 'T' && mapa[CimaAredondadoY - 1][CimaAredondadoX] != 'T')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BaseEntidades::ColisaoBaixo(vector<vector<char>>& mapa)
{
	if (mapa[BaixoY + 1][BaixoX] != 'T' && mapa[BaixoAredondadoY + 1][BaixoAredondadoX] != 'T')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BaseEntidades::ColisaoDireita(vector<vector<char>>& mapa)
{
	if (mapa[DireitaY][DireitaX + 1] != 'T' && mapa[DireitaAredondadoY][DireitaAredondadoX + 1] != 'T')
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool BaseEntidades::ColisaoEsquerda(vector<vector<char>>& mapa)
{
	if (mapa[EsquerdaY][EsquerdaX - 1] != 'T' && mapa[EsquerdaAredondadoY][EsquerdaAredondadoX - 1] != 'T')
	{
		return true;
	}
	else
	{
		return false;
	}
}

BaseEntidades::~BaseEntidades()
{
}


