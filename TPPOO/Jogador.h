#pragma once
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <list>
#include "Tecnologia.h"
#include "Imperio.h"


using namespace std;
class Jogador
{
	
	vector<string> tecnologias;
	

public:
	Jogador();
	~Jogador();

	vector<string> getTecnologias();
	void adquireTecnologias(string nome);
};

