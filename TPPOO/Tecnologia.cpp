#include "Tecnologia.h"

Tecnologia::Tecnologia()
{
}

Tecnologia::~Tecnologia() {

}

// -------------------- GETTERS ----------------------

string Tecnologia::getTipo() {
	return tipo;
}

int Tecnologia::getCustOuro() {
	return custoOuro;
}

// --------------------- SETTERS ----------------------

void Tecnologia::setTipo(int t) {
	tipo = t;
}

void Tecnologia::setCustOuro(int o) {
	custoOuro = o;
}

