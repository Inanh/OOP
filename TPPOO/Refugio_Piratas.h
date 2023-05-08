#pragma once
#include "Territorio.h"
using namespace std;
class Refugio_Piratas : public Territorio
{
	static int sequencia;
	string nome;
public:
	Refugio_Piratas();
	virtual ~Refugio_Piratas();
	Territorio* duplica()const override;
};