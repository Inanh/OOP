#include "Planicie.h"

int Planicie::sequencia = 1;

Planicie::Planicie():Territorio(5, 1, 1, 1,"planicie","planicie" + to_string(sequencia))
{
	sequencia++;
}

Planicie::~Planicie() {

}

Territorio* Planicie::duplica()const {
	return new Planicie(*this);
}
