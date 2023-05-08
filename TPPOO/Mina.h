#pragma once
#include "Territorio.h"
using namespace std;
class Mina : public Territorio
{
	static int sequencia;
	string nome;

public:
	Mina();
	virtual ~Mina();
	Territorio* duplica()const override;
};