#include "Territorio.h"
#include "Planicie.h"
#include "Montanha.h"
#include "Fortaleza.h"
#include "Mina.h"
#include "Duna.h"
#include "Castelo.h"
#include "Refugio_Piratas.h"
#include "Pescaria.h"
#include "Territorio_Inicial.h"



Territorio::Territorio(int rest, int criaP,int criaO,int PVit,string t,string nome) {
	this->nome = nome;
	tipo = t;
	resistencia = rest;
	criaProdutos = criaP;
	criaOuro = criaO;
	pVitoria = PVit;
}

Territorio::~Territorio() {
}



//---------------------------- GETTERS ------------------------

string Territorio::getNome() {
	return nome;
}
string Territorio::getTipo() {
	return tipo;
}
int Territorio::getResistencia() {
	return resistencia;
}
int Territorio::getCriaProdutos() {
	return criaProdutos;
}
int Territorio::getCriaOuro() {
	return criaOuro;
}
int Territorio::getVitoria() {
	return pVitoria;

}
//---------------------------- SETTERS (CASO FOR PRECISO) -----------------------

void Territorio::setResistencia(int r) {
	resistencia = r;
}
void Territorio::setCriaProtudo(int p) {
	criaProdutos = p;
}
void Territorio::setCriaOuro(int o) {
	criaOuro = o;
}
void Territorio::setVitoria(int v) {
	pVitoria = v;
}

Territorio* Territorio::criaTerritorio(string tipo)
{
	if (tipo == "territorio_inicial")
		return new Territorio_Inicial;

	else if (tipo == "planicie")
		return new Planicie;

	else if (tipo == "montanha")
		return new Montanha;

	else if (tipo == "fortaleza")
		return new Fortaleza;	

	else if (tipo == "mina")
		return new Mina;

	else if (tipo == "duna")
		return new Duna;

	else if (tipo == "castelo")
		return new Castelo;

	else if (tipo == "refugio")
		return new Refugio_Piratas;

	else if (tipo == "pescaria")
		return new Pescaria;

	return nullptr;
}


string Territorio::getAsString() const
{
	ostringstream os;
	os  << "\nNome:" << nome << "\nResistencia:" << resistencia << 
		"\nCriacao Produtos:" << criaProdutos << "\nCriacao Ouro:" << criaOuro <<
		"\nPontos Vitoria:" << pVitoria << endl;
	return os.str();
}
	

