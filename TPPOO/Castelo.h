#pragma once
#include "Territorio.h"
using namespace std;
class Castelo : public Territorio
{
	static int sequencia;
	string nome;

public:
	Castelo();
	virtual ~Castelo();
	Territorio* duplica()const override;
};