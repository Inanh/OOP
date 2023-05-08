#pragma once
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <list>
#include "Jogador.h"

using namespace std;

class Tecnologia
{
	string tipo;
	int custoOuro;

public:
	Tecnologia();
	virtual~Tecnologia();

	// -------------------- GETTERS ----------------------

	 virtual string getTipo();
	 virtual int getCustOuro();

	 // --------------------- SETTERS ----------------------

	 virtual void setTipo(int t);
	 virtual void setCustOuro(int o);


	virtual Tecnologia* duplica()const = 0;
	
};

