#pragma once
#include "Territorio.h"
using namespace std;
class Montanha : public Territorio
{
	static int sequencia;
	string nome;
	int montanha_cont;
public:
	Montanha();
	virtual ~Montanha();

	int getMontanha_conquistada() override;
	void setMontanha_conquistada(int mont) override;
	Territorio* duplica()const override;
};