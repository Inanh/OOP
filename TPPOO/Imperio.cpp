#include "Imperio.h"
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
#include "Jogo.h"


Imperio::Imperio() {
	produtos = 0;
	ouro = 0;
	militar = 0;
}

Imperio::~Imperio()
{
}

//---------------------------- GETTERS ------------------------//


int Imperio::getProdutos() {
	return produtos;
}

int Imperio::getOuro() {
	return ouro;
}

int Imperio::getMilitar() {
	return militar;
}

//-------------------------- SETTERS ---------------------------//

void Imperio::setProdutos(int p) {
	produtos = p;
}

void Imperio::setOuro(int o) {
	ouro = o;
}

void Imperio::setMilitar(int m) {
	militar = m;

}

vector<string> Imperio::getTerritorios() { //VETOR DOS TERRITORIOS
	return territorios;  //NOME DO VETOR DE STRINGS
}
void Imperio::Apaga_Ultimo_Elemento() { //FUNCAO QUE ADICIONA TERRITORIOS CONSQUISTADOS
	territorios.pop_back(); //PUSH_BACK -> ADICIONA AO VETOR
}

void Imperio::conquistaTerritorio(string nome) { //FUNCAO QUE ADICIONA TERRITORIOS CONSQUISTADOS
	territorios.push_back((nome)); //PUSH_BACK -> ADICIONA AO VETOR
}

int Imperio::Verifica_Limites(Jogo* j)
{
	for (int i = 0; i < j->getJogador()->getTecnologias().size() ; i++) {

		if (j->getJogador()->getTecnologias()[i] == "drone" || j->getJogador()->getTecnologias()[i] == "banco") {
			return 5;
		}
	}

	return 3;
}

bool Imperio::Verifica_Ouro_Jogador(int custo)
{
	if (ouro >= custo)
		return true;

	return false;
}

bool Imperio::Verifica_Produto_Jogador(int prod) {

	if (produtos >= prod)
		return true;

	return false;
}

bool Imperio::Verifica_Militar_Jogador(int mil)
{
	if (militar >= mil)
		return true;

	return false;
}


string Imperio::getAsString() {

	ostringstream os;
	os << "\nQuantia de Produto:" << produtos << "\nQuantia de Ouro:" << ouro << "\nMilitar:" << militar <<
		"\nN.Territorios Conquistados:" << territorios.size() << "\nTerritorios Conquistados:" << endl;
	for (int i = 0; i < territorios.size(); i++) {
		os << territorios[i] << "\n";
	}
	return os.str();
}