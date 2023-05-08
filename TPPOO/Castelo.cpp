#include "Castelo.h"

int Castelo::sequencia = 1;

Castelo::Castelo():Territorio(7, 1, 1, 1, "castelo", "castelo" + to_string(sequencia)) {
	sequencia++;
}

Castelo::~Castelo()
{

}

Territorio* Castelo::duplica()const {
	return new Castelo(*this);
}