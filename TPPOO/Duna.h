#pragma once
#include "Territorio.h"
using namespace std;
class Duna : public Territorio
{
	static int sequencia;
	string nome;

public:
	Duna();
	virtual ~Duna();
	Territorio* duplica()const override;
};

