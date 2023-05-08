#pragma once
#include "Territorio.h"

using namespace std;

class Territorio_Inicial : public Territorio
{
	string nome;
public:
	Territorio_Inicial();
	virtual ~ Territorio_Inicial();
	Territorio* duplica()const override;

};

