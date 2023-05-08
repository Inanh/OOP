 #include "Refugio_Piratas.h"

int Refugio_Piratas::sequencia = 1;

Refugio_Piratas::Refugio_Piratas():Territorio(9, 0, 1, 2,"refugio","refugio" + to_string(sequencia)) {
	sequencia++;
}

Refugio_Piratas::~Refugio_Piratas(){
}


Territorio* Refugio_Piratas::duplica()const {
	return new Refugio_Piratas(*this);
}