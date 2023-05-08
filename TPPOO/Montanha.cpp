#include "Montanha.h"

int Montanha::sequencia = 1;

Montanha::Montanha():Territorio(6, 0, 0, 1,"montanha", "montanha" + to_string(sequencia)) {
	sequencia++;
	montanha_cont = 0;
}

Montanha::~Montanha()
{

}


int Montanha::getMontanha_conquistada(){
	return montanha_cont;
}

void Montanha::setMontanha_conquistada(int mont) {
	montanha_cont = mont;
}

Territorio* Montanha::duplica()const {
	return new Montanha(*this);
}