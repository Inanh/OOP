#pragma once
#include "Territorio.h"
using namespace std;
class Fortaleza : public Territorio
{
	static int sequencia;
	string nome;
public:
	Fortaleza();
	virtual ~Fortaleza();
	Territorio* duplica()const override;
};