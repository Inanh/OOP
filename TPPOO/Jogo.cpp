#include "Jogo.h"


using namespace std;

Jogo::Jogo()
{
	turno = 1;
	pontuacao = 0;
}

Jogo::~Jogo()
{
	delete m;
	delete i;
	delete jog;
}

int Jogo::getPontuacao() {
	return pontuacao;
}

void Jogo::setPontuacao(int p) {
	pontuacao = p;
}


void Jogo::createMundo()
{
	m = new Mundo();
}

void Jogo::createImperio()
{
	i = new Imperio();
}

void Jogo::createJogador()
{
	jog = new Jogador();
}

void Jogo::createEvento()
{
	env = new Evento();
}

int Jogo::Turno() //DEVOLVE SO TURNO EM QUE ESTA
{
	return turno;
}

int Jogo::getTurno()  //INCREMENTA O TURNO
{
	turno++;
	return turno;
}

void Jogo::setTurno(int t)
{	
	turno = t;
}

int Jogo::Fator_Sorte()
{
	int randnumero = (rand() % 6) + 1;
	return randnumero;
}

bool Jogo::Verifica_Forca_Militar(Territorio* t)
{
	if (i->getMilitar() + Fator_Sorte() >= t->getResistencia())
		return true;	
	
	return false;
}

void Jogo::verificaTerritorio_Incrementa_Ouro_Produto(Imperio* imp) {

	for (int k = 0; k < getMundo()->getTerritorios().size(); k++) {
		for (int i = 0; i < imp->getTerritorios().size(); i++) {
			if (getMundo()->getTerritorios()[k]->getNome() == imp->getTerritorios()[i]) {

				imp->setOuro(imp->getOuro() + (getMundo()->getTerritorios()[k]->getCriaOuro()));
				imp->setProdutos(imp->getProdutos() + (getMundo()->getTerritorios()[k]->getCriaProdutos()));
			}
		}
	}
}

void Jogo::Pontuacao() {

	int contPont = 0;

	if (getJogador()->getTecnologias().size() >= 5)
	{
		setPontuacao(getPontuacao() + 1);
	}

	for (int k = 0; k < getJogador()->getTecnologias().size(); k++)
	{
		setPontuacao(getPontuacao()+1);
	}

	if (getMundo()->getTerritorios().size() == getImperio()->getTerritorios().size()) {
		setPontuacao(getPontuacao() + 3);
	}

	for (int i = 0;i< getMundo()->getTerritorios().size(); i++)
	{
		for (int k = 0;k< getImperio()->getTerritorios().size(); k++)
		{
			if (getMundo()->getTerritorios()[i]->getNome() == getImperio()->getTerritorios()[k])
			{
				setPontuacao(getPontuacao() + getMundo()->getTerritorios()[k]->getVitoria());
			}

		}
	}
}