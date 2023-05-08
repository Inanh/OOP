#include "Mina.h"

int Mina::sequencia = 1;

Mina::Mina() :Territorio(5, 1, 1, 1,"mina", "mina" + to_string(sequencia)) {
	sequencia++;
}

Mina::~Mina()
{

}

Territorio* Mina::duplica()const {
	return new Mina(*this);
}
