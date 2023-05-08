#include "Fortaleza.h"

int Fortaleza::sequencia = 1;

Fortaleza::Fortaleza() :Territorio(8, 0, 0, 1,"fortaleza", "fortaleza" + to_string(sequencia)) {
	sequencia++;
}

Fortaleza::~Fortaleza()
{

}

Territorio* Fortaleza::duplica()const {
	return new Fortaleza(*this);
}