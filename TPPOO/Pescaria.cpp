#include "Pescaria.h"

int Pescaria::sequencia = 1;

Pescaria::Pescaria() :Territorio(9, 1, 0, 2,"pescaria", "pescaria" + to_string(sequencia)) {
	sequencia++;
}

Pescaria::~Pescaria()
{

}

Territorio* Pescaria::duplica()const {
	return new Pescaria (*this);
}