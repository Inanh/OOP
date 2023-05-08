#include "Mundo.h"
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
#include "Imperio.h"

using namespace std;

Mundo::Mundo() {

}

Mundo::~Mundo() {
}

void Mundo::adicionaTerritorio(string tipo, int quantia) {   
	
	for (int i = 0; i < quantia; i++) {
		
		if (tipo == "territorio_inicial")
			t.push_back(new Territorio_Inicial);
		else if (tipo == "planicie") 
			t.push_back(new Planicie); 
		else if(tipo=="montanha")
			t.push_back(new Montanha); 
		else if(tipo=="fortaleza")
			t.push_back(new Fortaleza);
		else if(tipo=="mina")
			t.push_back(new Mina);
		else if (tipo=="duna")
			t.push_back(new Duna);
		else if (tipo=="castelo")
			t.push_back(new Castelo);
		else if(tipo=="refugio")
			t.push_back(new Refugio_Piratas);
		else if(tipo== "pescaria")
			t.push_back(new Pescaria);
	}
	
}

vector<Territorio*> Mundo::getTerritorios() {
	return t;
};

vector<int> Mundo::getContaTerritorios() {  
	int contater=0, contam = 0, contap = 0, contaf = 0, contaMt = 0, contad = 0, contac = 0,contar=0,contapes=0;
	for (int i = 0; i < t.size(); i++) {

		if (t[i]->getTipo() == "territorio_inicial") {
			contater++;
		}

		else if (t[i]->getTipo() == "mina") {
			contam++;
		}
		else if (t[i]->getTipo() == "planicie") {
			contap++;
		}
		else if (t[i]->getTipo() == "fortaleza") {
			contaf++;
		}
		else if (t[i]->getTipo() == "montanha") {
			contaMt++;
		}
		else if (t[i]->getTipo() == "duna") {
			contad++;
		}
		else if (t[i]->getTipo() == "castelo") {
			contac++;
		}
		else if (t[i]->getTipo() == "refugio") {
			contar++;
		}
		else if(t[i]->getTipo()== "pescaria"){
			contapes++;
		}
	}

	vector<int> contage;
	contage.push_back(contater);
	contage.push_back(contam);
	contage.push_back(contap);
	contage.push_back(contaf);
	contage.push_back(contaMt);
	contage.push_back(contad);
	contage.push_back(contac);
	contage.push_back(contar);
	contage.push_back(contapes);

	return contage;

}

Territorio* Mundo::getTerritorio(string territorio) {

	for (int k = 0; k < getTerritorios().size(); k++) {
		if (territorio == getTerritorios()[k]->getNome()) {
			return getTerritorios()[k];
		}
	}
}


bool Mundo::verificaTerritorio(string territorio,Imperio* imp) {

	for (int k = 0; k < getTerritorios().size(); k++) {
		if (territorio == getTerritorios()[k]->getNome()) {
			for (int i = 0; i < imp->getTerritorios().size(); i++) {
				if (getTerritorios()[k]->getNome() == imp->getTerritorios()[i]) {
					return false;
				}



			}
		}
	}
	
	return true;
}


string Mundo::getAsString() {

	vector<int> contage = getContaTerritorios();
	ostringstream os;
	os << "territorio inicial:"<< contage[0] << "\nmina:" << contage[1] << "\nplanicie:" << contage[2] << "\nfortaleza:" << contage[3] << "\nmontanha:" 
		<< contage[4] << "\nduna:" << contage[5] << "\ncastelo:" << contage[6]  <<
		"\nrefugio de piratas:" << contage[7] << "\npescaria:" << contage[8]<< endl;
	return os.str();
}



/* FUNCAO DE : "Nos turnos do primeiro ano, produz 1unidade de produtos e 1de ouro,
				nos turnos do segundo ano produz 2unidades de produtos e 1de ouro. */


bool Mundo::Verfica_Turno(int turn, int turn2)
{
	if (((turn2 - turn) > 2))
		return true;

	return false;
}

void Mundo::Verifica_Conta_Conquistado(int turn, Imperio* imp) //VERIFICA SE É MONTANHA E SE JA PASSARAM DOIS TURNOS
{
	int turnMontanha=0;
	for (int i = 0; i < imp->getTerritorios().size(); i++)
	{
		for(int k=0; k< getTerritorios().size(); k++)
		{
			if (imp->getTerritorios()[i] == getTerritorios()[k]->getNome()) {
				if (getTerritorios()[k]->getTipo() == "montanha")
				{
					turnMontanha = getTerritorios()[k]->getMontanha_conquistada();

					if ((Verfica_Turno(turnMontanha, turn))) {
						t[i]->setCriaProtudo(1);
					}
					else {
						t[i]->setCriaProtudo(0);
					}
				}
			}
		}
	}
}

void Mundo::Ouro_Produtos_Troca(int turn,Imperio* imp){

	for (int i=0; i < t.size();i++) {
		if(t[i]->getTipo() == "planicie" && turn <= 6){
			t[i]->setCriaOuro(1);
			t[i]->setCriaProtudo(1);
		}
		else if ((t[i]->getTipo() == "planicie" && turn > 6))
		{
			t[i]->setCriaOuro(1);
			t[i]->setCriaProtudo(2);
		}
		else if(t[i]->getTipo() == "mina"){
			if(turn > 0 && turn <= 3 || turn > 6 && turn <=9){
				t[i]->setCriaOuro(1);
			}
			else if(turn > 3 && turn <= 6 || turn > 9 && turn <= 12){
				t[i]->setCriaOuro(2);
			}
		}
		else if(t[i]->getTipo() == "castelo"){ 
			if(turn == 1 || turn == 2 || turn == 7 || turn == 8){
				t[i]->setCriaProtudo(3);
			}
		}
		else if (t[i]->getTipo() == "pescaria"){ 
			if (turn >= 1 || turn <= 6) {
				t[i]->setCriaProtudo(2);
			}
			else if (turn > 6 || turn <= 12) {
				t[i]->setCriaProtudo(4);
			}
		}
	}
}