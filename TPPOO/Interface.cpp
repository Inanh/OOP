#include "Interface.h"
#include <iostream>

using namespace std;
using std::cout;


class Jogo;
Jogo j;
Interface::Interface(){
}

Interface::~Interface(){
}

vector<string> Interface::split(const string& s, char separa) {
	vector<string> tokens;
	string token;
	istringstream tokenStream(s);
	while (getline(tokenStream, token, separa)) {
		tokens.push_back(token);
	}
	return tokens;
}


	//----------------------COMANDOS QUE POSSAM SER UTILIZADOS DURANTE O JOGO TODO: -------------------------
	//GRAVA,APAGA,ATIVA,LISTA,DEGUBG


void Interface::Comando_Grava() {

}

void Interface::Comando_Ativa() {

}

void Interface::Comando_Apaga() {

}

void Interface::Comando_Lista2() {

	cout << "----- Listagem global-----" << endl;
	cout << "--- Mundo ---" << endl;
	for (int i = 0; i < j.getMundo()->getTerritorios().size(); i++) {
		cout << j.getMundo()->getTerritorios()[i]->getAsString();
	}

	cout << "--- Territorios ---" << endl;
	cout << j.getMundo()->getAsString();
	cout << "--- Jogador ---" << endl;
	cout << j.getImperio()->getAsString();
	

}


void Interface::Comando_Lista(string token) {

	if (token== "mundo") {

		cout << "----- Listagem Mundo-----" << endl;
		for (int i = 0; i < j.getMundo()->getTerritorios().size(); i++)
			cout << j.getMundo()->getTerritorios()[i]->getAsString();
	}
	else if (token == "territorios") {
		cout << "----- Listagem Territorios-----" << endl;
		cout << j.getMundo()->getAsString();
	}

	else if (token == "jogador") {
		cout << "----- Listagem jogador-----" << endl;
		cout << j.getImperio()->getAsString();
	}

}


void Interface::Comando_Avanca() {

	j.getMundo()->Verifica_Conta_Conquistado(j.Turno(), j.getImperio());
	j.getMundo()->Ouro_Produtos_Troca(j.Turno(), j.getImperio());
	j.getTurno();
}

void Interface::Comando_Passa() {

	j.getMundo()->Verifica_Conta_Conquistado(j.Turno(), j.getImperio());
	j.getMundo()->Ouro_Produtos_Troca(j.Turno(), j.getImperio());

}

void Interface::Fase_Configuracao() {

	string comando;
	vector<string> tokens;
	cout << "------------- INICIO DA FASE DE CONFIGURACAO ----------------" << endl;
	do {

		cout << "Introduza um comando:" ;
		getline(cin, comando);
		tokens = split(comando, ' ');

		if (tokens[0] == "cria") {
			if (tokens.size() == 3) {

				j.getMundo()->adicionaTerritorio(tokens[1], stoi(tokens[2]));
				cout << "\nO territorio foi criado com sucesso!" << endl;
			}
		}

		else if (tokens[0] == "carrega") {
			if (tokens.size() == 2) {
				ifstream map(tokens[1]);

				if (!map.is_open()) {
					return;
				}

				string s, line, tipo;
				int x;

				while (!map.eof())
				{
					getline(map, s);
					istringstream is(s);

					//le um comando(cria int)
					is >> line >> tipo >> x;

					if (line == "cria") {
						j.getMundo()->adicionaTerritorio(tipo, x);

					}
				}
				cout << "\nMapa carregado com sucesso!" << endl;
			}

		}

		else if (tokens[0] == "lista") {
			if (tokens.size() == 2){
				Comando_Lista(tokens[1]);
			}
			else if(tokens.size()==1) {
				Comando_Lista2();
			}
		}

		else if(tokens[0]=="grava"){
			Comando_Grava();
		}

		else if (tokens[0] == "apaga") {
			Comando_Apaga();
		}

		else if (tokens[0] == "ativa"){
			Comando_Ativa();
		}
	} while (tokens[0] != "avanca");
	
	
	Comando_Avanca();
	j.setTurno(j.getTurno() - 2);
	cout << "Turno:" << j.Turno()<< endl;
	cout << "Fim da fase de configuracao, incio da seguinte fase " << endl;
	Fase_Conquistar_Passa();
}


void Interface::Fase_Conquistar_Passa(){
	string comando;
	vector<string> tokens;
	cout << "------------- INICIO DA FASE DE CONQUISTA ----------------" << endl;
	
	bool flag = false, flag2=false,flag3=false,flag4=false;

	do {
		cout << "Introduza um comando:" ;
		getline(cin, comando);
		tokens = split(comando, ' ');

		if (tokens[0] == "conquista") {
			if (tokens.size() == 2 && !flag) {

				if (j.getMundo()->verificaTerritorio(tokens[1], j.getImperio())) {

					if (tokens[1] == "territorio_inicial") {
						cout << "Territorio impossivel de voltar a conquistar, so existe um!!" << endl;
					}
					else {
						for (int i = 0; i < j.getMundo()->getTerritorios().size(); i++) {
							if (j.getMundo()->getTerritorios()[i]->getTipo() == "pescaria" || j.getMundo()->getTerritorios()[i]->getTipo() == "refugio") {
								cout << "1" << endl;
								if (j.getMundo()->getTerritorios()[i]->getNome() == tokens[1])
									flag4 = true;
							}
						}
						if (flag4) {
							if (j.getJogador()->getTecnologias().size() == 0)
							{
								cout << "Ainda nao possui tecnologias para conquistar este territorio!! Avance mais no jogo!!" << endl;
							}

							for (int k = 0; k < j.getJogador()->getTecnologias().size(); k++)
							{
								
								if (j.getJogador()->getTecnologias()[k] == "misseis")
								{
									flag3 = true;
								}
							}

							for (int i = 0; i < j.getImperio()->getTerritorios().size(); i++) {
								if (j.getImperio()->getTerritorios().size() >= 5) {
									if (flag3) {
										if (j.Verifica_Forca_Militar(j.getMundo()->getTerritorio(tokens[1]))) {
											j.getImperio()->conquistaTerritorio(tokens[1]);
											cout << "Territorio conquistado:" << tokens[1] << endl;
										}
										else {
											j.getImperio()->setMilitar(j.getImperio()->getMilitar() - 1);
											cout << "Conquista falhada, perdeu uma unidade militar!!" << endl;
										}
									}
									else {
										cout << "Impossival a conquista de" << tokens[1] << endl;
										cout << "Necessita da tecnologia misseis e de pelo o menos 5 territorios conquistados!!" << endl;
									}
								}
							}
						}

						else {
							if (j.Verifica_Forca_Militar(j.getMundo()->getTerritorio(tokens[1]))) {
								j.getImperio()->conquistaTerritorio(tokens[1]);
								cout << "Territorio conquistado:" << tokens[1] << endl;
							}
							else {
								j.getImperio()->setMilitar(j.getImperio()->getMilitar() - 1);
								cout << "Conquista falhada, perdeu uma unidade militar!!" << endl;
							}

							for (int i = 0; i < j.getMundo()->getTerritorios().size(); i++)
							{
								if (j.getMundo()->getTerritorios()[i]->getNome() == tokens[1])
								{
									if ((j.getMundo()->getTerritorios()[i]->getTipo() == "montanha"))
									{
										j.getMundo()->getTerritorios()[i]->setMontanha_conquistada(j.Turno());
									}
								}
							}
							flag = true;
						}
					}
				}
				
				else {
					cout << "Territorio ja conquistado" << endl;
				}
				
			}
			else {
				cout << "Comando incorreto ou ja nao da para conquistar mais nenhum territorio!!" << endl;
			}
		}
		else if (tokens[0] == "lista") {
			if (tokens.size() == 2) {
				Comando_Lista(tokens[1]);
			}
			else if (tokens.size() == 1) {
				Comando_Lista2();
			}
		}

		else if (tokens[0] == "grava") {
			Comando_Grava();
		}

		else if (tokens[0] == "apaga") {
			Comando_Apaga();
		}

		else if (tokens[0] == "ativa") {
			Comando_Ativa();
		}
		else if (tokens[0] == "avanca" || tokens[0] == "passa")
			flag2 = true;
		
	} while (!flag2);

	if (tokens[0] == "avanca") {
		Comando_Avanca();
		j.setTurno(j.getTurno() - 2);
	}
	else if (tokens[0] == "passa") {
		Comando_Passa();
	}
		
		
	cout << "Turno:" << j.Turno() << endl;
	cout << "Fim da fase de conquista, incio da seguinte fase " << endl;
	Fase_Recolha_Prod_Ouro();
}


void Interface::Fase_Recolha_Prod_Ouro(){

	cout << "------------- INICIO DA FASE DE RECOLHA DE OURO E PROD ----------------" << endl;

	string comando;
	vector<string> tokens;
	bool flag = false;
	
	j.getMundo()->Verifica_Conta_Conquistado(j.Turno(),j.getImperio());
	j.verificaTerritorio_Incrementa_Ouro_Produto(j.getImperio());

	if (j.getImperio()->getOuro() > j.getImperio()->Verifica_Limites(&j)) {
		j.getImperio()->setOuro(j.getImperio()->Verifica_Limites(&j));
	}
		
	if (j.getImperio()->getProdutos() > j.getImperio()->Verifica_Limites(&j)) {
		j.getImperio()->setProdutos(j.getImperio()->Verifica_Limites(&j));
	}
	
	cout << "Quantia de ouro do Imperio:"<< j.getImperio()->getOuro() << endl;
	cout << "Quantia de produto do Imperio:" << j.getImperio()->getProdutos() << endl;


	for (int i = 0; i < j.getJogador()->getTecnologias().size(); i++)
	{
		if (j.getJogador()->getTecnologias()[i] == "bolsa")
		{
			flag = true;
		}
	}

	do{

		cout << "Introduza um comando:" ;
		getline(cin, comando);
		tokens = split(comando, ' ');

		if (flag) {
			if (tokens[0] == "maisouro") {
				if (j.getImperio()->Verifica_Produto_Jogador(2)) {
					j.getImperio()->setOuro(j.getImperio()->getOuro() + 1);
					j.getImperio()->setProdutos(j.getImperio()->getProdutos() - 2);

					if (j.getImperio()->getOuro() <= j.getImperio()->Verifica_Limites(&j))
					{
						j.getImperio()->setOuro(j.getImperio()->getOuro());
						cout << "Troca feito com sucesso ! Ouro:" << j.getImperio()->getOuro() << endl;
					}
				}

				else {
					cout << "Nao da para comprar mais!! Limite maximo de Ouro" << endl;
					j.getImperio()->setOuro(j.getImperio()->getOuro() - 1);
					j.getImperio()->setProdutos(j.getImperio()->getProdutos() + 2);
				}
			}

			else if (tokens[0] == "maisprod") {
				if (j.getImperio()->Verifica_Ouro_Jogador(2)) {
					j.getImperio()->setOuro(j.getImperio()->getOuro() - 2);
					j.getImperio()->setProdutos(j.getImperio()->getProdutos() + 1);

					if (j.getImperio()->getProdutos() <= j.getImperio()->Verifica_Limites(&j))
					{
						j.getImperio()->setProdutos(j.getImperio()->getProdutos());
						cout << "Troca feito com sucesso ! Produto:" << j.getImperio()->getProdutos() << endl;
					}
				}

				else {
					cout << "Nao da para comprar mais!! Limite maximo de Produto" << endl;
					j.getImperio()->setOuro(j.getImperio()->getOuro() + 2);
					j.getImperio()->setProdutos(j.getImperio()->getProdutos() - 1);
				}

			}
		}
		else {
			cout << "Tecnologia bolsa nao adquirida!! Nao e permitido a troca" << endl;
		}

		if (tokens[0] == "lista") {
			if (tokens.size() == 2) {
				Comando_Lista(tokens[1]);
			}
			else if (tokens.size() == 1) {
				Comando_Lista2();
			}
		}

		else if (tokens[0] == "grava") {
			Comando_Grava();
		}

		else if (tokens[0] == "apaga") {
			Comando_Apaga();
		}

		else if (tokens[0] == "ativa") {
			Comando_Ativa();
		}
	} while (tokens[0] != "avanca");

	Comando_Avanca();
	j.setTurno(j.getTurno() - 2);
	cout << "Turno: " << j.Turno() << endl;
	cout << "Fim da fase de configuracao, incio da seguinte fase " << endl;
	Fase_Militar_Tecnologias();
}

void Interface::Fase_Militar_Tecnologias() {
	string comando;
	vector<string> tokens;

	bool flag = false;

	cout << "------------- INICIO DA FASE DE COMPRA DE UNID MILITARES E DE TECNOLOGIAS ----------------" << endl;

	do {

		cout << "\nIntroduza um comando:";
		getline(cin, comando);
		tokens = split(comando, ' ');

		if (tokens[0] == "maismilitar") {
			if (j.getImperio()->Verifica_Ouro_Jogador(1) && j.getImperio()->Verifica_Produto_Jogador(1)) {
				j.getImperio()->setOuro(j.getImperio()->getOuro() - 1);
				j.getImperio()->setProdutos(j.getImperio()->getProdutos() - 1);
				j.getImperio()->setMilitar(j.getImperio()->getMilitar() + 1);

				if (j.getImperio()->getMilitar() <= j.getImperio()->Verifica_Limites(&j))
				{
					j.getImperio()->setMilitar(j.getImperio()->getMilitar());
					cout << "Troca feito com sucesso ! Militar:" << j.getImperio()->getMilitar() << endl;
				}

				else {
					cout << "Nao da para comprar mais!! Limite maximo militar" << endl;
					j.getImperio()->setOuro(j.getImperio()->getOuro() + 1);
					j.getImperio()->setProdutos(j.getImperio()->getProdutos() + 1);
					j.getImperio()->setMilitar(j.getImperio()->getMilitar() - 1);
				}

			}
			else {

				cout << "Ouro e Produto insuficiente para a troca! Sem efeito!" << endl;
			}
		}

		for (int i = 0; i < j.getJogador()->getTecnologias().size(); i++)
		{
			if (j.getJogador()->getTecnologias()[i] == "banco")
			{
				flag = true;
			}
		}

		if (tokens[0] == "adquire") {

			if (tokens[1] == "drone") {
				if (j.getImperio()->Verifica_Ouro_Jogador(3)) {
					j.getImperio()->setOuro(j.getImperio()->getOuro() - 3);
					cout << "Foi retirado 3 de Ouro!!" << "Ouro no Cofre:" << j.getImperio()->getOuro() << endl;
					j.getJogador()->adquireTecnologias(tokens[1]);

					cout << "Drone militar adquirido!! Limite maximo Militar = 5" << endl;
				}
				else {
					cout << "Verifique o comando ou Ouro insuficiente. Ouro no cofre:" << j.getImperio()->getOuro() << endl;
				}
			}
			else if (tokens[1] == "misseis") {
				if (j.getImperio()->Verifica_Ouro_Jogador(4)) {
					j.getImperio()->setOuro(j.getImperio()->getOuro() - 4);
					cout << "Foi retirado 4 de Ouro!!" << "Ouro no Cofre:" << j.getImperio()->getOuro() << endl;
					j.getJogador()->adquireTecnologias(tokens[1]);

					cout << "Missil adquirido!! Ilhas desbloqueadas!" << endl;
				}
				else {
					cout << "Verifique o comando ou Ouro insuficiente. Ouro no cofre:" << j.getImperio()->getOuro() << endl;
				}

			}
			else if (tokens[1] == "defesas") {  
				if (j.getImperio()->Verifica_Ouro_Jogador(4)) {
					j.getImperio()->setOuro(j.getImperio()->getOuro() - 4);
					cout << "Foi retirado 4 de Ouro!!" << "Ouro no Cofre:" << j.getImperio()->getOuro() << endl;
					j.getJogador()->adquireTecnologias(tokens[1]);
					cout << "Defesa territorial adquirida !!" << endl;
				}
				else {
					cout << "Verifique o comando ou Ouro insuficiente. Ouro no cofre:" << j.getImperio()->getOuro() << endl;
				}
			}
			else if (tokens[1] == "bolsa") {
				if (j.getImperio()->Verifica_Ouro_Jogador(2)) {
					j.getImperio()->setOuro(j.getImperio()->getOuro() - 2);
					cout << "Foi retirado 2 de Ouro!!" << "Ouro no Cofre:" << j.getImperio()->getOuro() << endl;
					j.getJogador()->adquireTecnologias(tokens[1]);
					cout << "Bolsa de Valores adquirida !!" << endl;
				}
				else {
					cout << "Verifique o comando ou Ouro insuficiente. Ouro no cofre:" << j.getImperio()->getOuro() << endl;
				}
			}
			else if (tokens[1] == "banco") {

				if (!flag)
				{
					if (j.getImperio()->Verifica_Ouro_Jogador(3)) {
						j.getImperio()->setOuro(j.getImperio()->getOuro() - 3);
						cout << "Foi retirado 3 de Ouro!!"<< "Ouro no Cofre:" << j.getImperio()->getOuro() << endl;
						j.getJogador()->adquireTecnologias(tokens[1]);

						cout << "Banco central adquirido!! Limite maximo Produtos e Ouro = 5" << endl;

					}
					else {
						cout << "Verifique o comando ou Ouro insuficiente. Ouro no cofre:" << j.getImperio()->getOuro() << endl;
					}
				}
				else {
					cout << "Compra feita, mas ja atingiu o limite maximo!!" << endl;
				}
			}
		}

		else if (tokens[0] == "lista") {
			if (tokens.size() == 2) {
				Comando_Lista(tokens[1]);
			}
			else if (tokens.size() == 1) {
				Comando_Lista2();
			}
		}

		else if (tokens[0] == "grava") {
			Comando_Grava();
		}

		else if (tokens[0] == "apaga") {
			Comando_Apaga();
		}

		else if (tokens[0] == "ativa") {
			Comando_Ativa();
		}
	}while (tokens[0] != "avanca"); 

	Comando_Avanca();
	j.setTurno(j.getTurno() - 2);
	cout << "Turno Incializados: " << j.Turno() << endl;
	cout << "Fim da fase de configuracao, incio da seguinte fase " << endl;
	Fase_Evento();

}


	//NOVO TURNO , FASE 1, FIM DE JOGO

void Interface::Fase_Evento()
{
	string comando;
	vector<string> tokens;

	cout << "------------- INICIO DA FASE DE EVENTOS ----------------" << endl;


	int randnumero = (rand() % 4) + 1;
	int randmunero2 = (rand() % 4) + 1;

	if (randnumero != randmunero2) {
		randmunero2;
	}

	do {

		switch (randmunero2)
		{
		case(1):
			cout << "------------Evento de Alianca Diplomatica---------------" << endl;
			cout << "Assinada uma alianca com outro imperio" << endl;
			j.getEvento()->Alianca_Diplomatica(&j);
			break;
		case(2):
			cout << "----------------Evento de Invasao------------" << endl;
			cout << "Outro imperio esta a tentar conquistar o seu ultimo territorio" << endl;
			j.getEvento()->Invasao(&j);
			break;
		case(3):
			cout << "------------Evento de Recurso Abandonado---------------" << endl;
			cout << "Um  recurso abandonado foi encontrado e fornece ao império uma unidade de produtos ou de ouro " << endl;
			j.getEvento()->Recurso_Abandonado(&j);
			break;
		case(4):
			cout << "----------Sem Evento-----------" << endl;
			j.getEvento()->Sem_Evento(&j);
			break;
		}


		cout << "\nIntroduza um comando:";
		getline(cin, comando);
		tokens = split(comando, ' ');
		
		if (tokens[0] == "lista") {
			if (tokens.size() == 2) {
				Comando_Lista(tokens[1]);
			}
			else if (tokens.size() == 1) {
				Comando_Lista2();
			}
		}

		else if (tokens[0] == "grava") {
			Comando_Grava();
		}

		else if (tokens[0] == "apaga") {
			Comando_Apaga();
		}

		else if (tokens[0] == "ativa") {
			Comando_Ativa();
		}

		if (j.Turno() < 12) {
			Comando_Avanca();
			Fase_Conquistar_Passa();
		}

		else if (j.getTurno() == 12) {
			j.Pontuacao();
			cout << "FIM DE JOGO!!" << endl;
			cout << "Pontuacao Final:" << j.getPontuacao() << endl;
			exit(0);
		}

	} while (tokens[0] != "avanca");

	
}


void Interface::begin() {

	string comando;
	vector<string> tokens;

	j.createMundo();

	j.getMundo()->adicionaTerritorio("territorio_inicial", 1);

	j.createImperio();

	j.getImperio()->conquistaTerritorio("territorio_inicial");

	j.createJogador();
	
	do {
		Fase_Configuracao();
	} while (comando!= "sair");
}