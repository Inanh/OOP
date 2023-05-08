#include "Jogador.h"

Jogador::Jogador(){

}

Jogador::~Jogador()
{
}


vector<string> Jogador::getTecnologias() { //VETOR DOS TERRITORIOS
	return tecnologias;  //NOME DO VETOR DE STRINGS
}

void Jogador::adquireTecnologias(string nome) { //FUNCAO QUE ADICIONA TECNOLOGIAS ADQUIRIDAS
	tecnologias.push_back((nome)); //PUSH_BACK -> ADICIONA AO VETOR
}
