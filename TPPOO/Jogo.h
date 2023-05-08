#pragma once
#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "mundo.h"
#include "Imperio.h"
#include "Jogador.h"
#include "Territorio.h"
#include "Evento.h"


using namespace std;

class Mundo;
class Imperio;
class Jogador;
class Evento;

class Jogo
{
	Mundo *m=nullptr;
	Imperio* i = nullptr;
	Jogador* jog = nullptr;
	Evento* env = nullptr;
	int turno;
	int pontuacao;

public:
	Jogo();
	~Jogo();

	int getPontuacao();
	void setPontuacao(int p);
	int Turno();
	int getTurno();
	void setTurno(int t);
	int Fator_Sorte();
	bool Verifica_Forca_Militar(Territorio* t);

	Mundo* getMundo() {
		return m;
	}
	Imperio* getImperio() {
		return i;
	}

	Jogador* getJogador() {
		return jog;
	}

	Evento* getEvento() {
		return env;
	}

	void createMundo();
	void createImperio();
	void createJogador();
	void createEvento();
	void verificaTerritorio_Incrementa_Ouro_Produto(Imperio* imp);
	void Pontuacao();
	
};