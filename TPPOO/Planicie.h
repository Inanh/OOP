#pragma once
#include "Territorio.h"

using namespace std;

class Planicie: public Territorio
{
	static int sequencia;

public:
	Planicie();
	virtual ~Planicie();
	Territorio* duplica()const override;
};

