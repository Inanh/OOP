#pragma once
#include <vector>
#include <string>
#include <cstdio>
#include <list>
#include "Jogador.h"
#include "Jogo.h"
#include "Imperio.h"

using namespace std;

class Territorio;
class Imperio;
class Mundo
{
	string nome;
	vector<Territorio *> t;

public:
	Mundo();
	virtual~Mundo();

	void adicionaTerritorio(string tipo, int quantia);
	string getAsString() ;
	vector<Territorio*> getTerritorios();
	vector<int> getContaTerritorios();
	bool verificaTerritorio(string territorio, Imperio* imp);
	void Ouro_Produtos_Troca(int turn,Imperio * imp);
	void Verifica_Conta_Conquistado(int turn, Imperio* imp);
	bool Verfica_Turno(int turn, int turn2);
	Territorio* getTerritorio(string territorio);
	
};