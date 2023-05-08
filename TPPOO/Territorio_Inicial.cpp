#include "Territorio_Inicial.h"

Territorio_Inicial::Territorio_Inicial() :Territorio(9,1,1,0,"territorio_inicial", "territorio_inicial")
{
	
}

Territorio_Inicial::~Territorio_Inicial() {

}

Territorio* Territorio_Inicial::duplica()const {
	return new Territorio_Inicial(*this);
}