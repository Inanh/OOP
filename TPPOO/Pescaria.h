#pragma once
#include "Territorio.h"
using namespace std;
class Pescaria : public Territorio
{
	static int sequencia;
	string nome;

public:
	Pescaria();
	virtual ~Pescaria();
	Territorio* duplica()const override;
};