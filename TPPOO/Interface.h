#pragma once
#include <cstdio>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include "Jogo.h"


using namespace std;
using std::cout;

class Jogo;
class Interface
{
	string nome;
	
	
public:
	Interface();
	~Interface();
	void begin();
	void Comando_Grava();
	void Comando_Ativa();
	void Comando_Apaga();
	void Comando_Lista2();
	void Comando_Lista(string token);
	void Comando_Avanca();
	void Comando_Passa();
	void Fase_Configuracao();
	void Fase_Conquistar_Passa();
	void Fase_Recolha_Prod_Ouro();
	void Fase_Militar_Tecnologias();
	void Fase_Evento();

	vector<string>split(const string& s, char separa);

};