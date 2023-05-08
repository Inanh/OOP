#include "Duna.h"

int Duna::sequencia = 1;

Duna::Duna():Territorio(4, 1, 1, 1,"duna", "duna" + to_string(sequencia)) {
	sequencia++;
}

Duna::~Duna()
{

}

Territorio* Duna::duplica()const {
	return new Duna(*this);
}
