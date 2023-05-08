#pragma once
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <list>
#include "Jogo.h"

using namespace std;

class Jogo;
class Imperio
{
	int produtos;
	int ouro;
	int militar;
	

	vector<string> territorios;

public:
	Imperio();
	~Imperio();


	int getProdutos();
	int getOuro();
	int getMilitar();

	void setProdutos(int p);
	void setOuro(int o);
	void setMilitar(int m);
	bool Verifica_Ouro_Jogador(int custo);
	bool Verifica_Produto_Jogador(int prod);
	int Verifica_Limites(Jogo* j);
	bool Verifica_Militar_Jogador(int mil);
	string getAsString();
	void conquistaTerritorio(string nome);
	vector<string> getTerritorios();
	void Apaga_Ultimo_Elemento();
};