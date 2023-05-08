#include "Evento.h"

Evento::Evento(){}

Evento::~Evento(){}

/*um  recurso abandonado foi encontrado e fornece ao império uma unidade de produtos
ou de ouro conforme for encontrado  no primeiro ano  do jogo  (produto)  ou  no  segundo  (ouro). 
Caso  já  tenha  sido  atingido  o  valor  máximo permitido,
o recurso encontrado é desperdiçado (e não ocorre nenhum outro evento em sua substituição)*/
void Evento::Recurso_Abandonado(Jogo* j) {

	if (j->Turno() <= 6)
	{
		j->getImperio()->setProdutos(j->getImperio()->getProdutos() + 1);
		if (j->getImperio()->Verifica_Ouro_Jogador(j->getImperio()->getProdutos()))
		{
			cout << "Limite de produtos atingido!! Nao e possivel adquirir recurso abandonado (prod)" << endl;
			j->getImperio()->setProdutos(j->getImperio()->getProdutos() - 1);
		}
		else {
			cout << "Recurso adquirido ( 1 Produto )!!"  "Produto Total:" << j->getImperio()->getProdutos() << endl;
		}
	}
	else if (j->Turno() > 6)
	{
		j->getImperio()->setOuro(j->getImperio()->getOuro() + 1);
		if (j->getImperio()->Verifica_Ouro_Jogador(j->getImperio()->getOuro()))
		{
			cout << "Limite de ouro atingido!! Nao e possivel adquirir recurso abandonado (ouro)" << endl;
			j->getImperio()->setOuro(j->getImperio()->getOuro() - 1);
		}
		else {
			cout << "Recurso adquirido ( 1 Ouro )!!"  "Ouro Total:" << j->getImperio()->getOuro() << endl;
		}
	}

}

/*um qualquer outro império concorrente, do qual nem sequer existe qualquer registo, está  a  tentar  conquistar  um  dos  territórios  do  jogador.
 Escolhe  o  território mais  recentemente  conquistado.  
 É  gerado  aleatoriamente  um  fator  sorte,  número entre 1 e 6 inclusive. 
 Este fator sorte é somado à força da invasão que tem o valor 2 no primeiro  ano  e  3  no  segundo  ano.
 Se  o  resultado  for  inferior  à  resistência  do território, a invasão falha.
 Caso contrário, a invasão concretiza-se, e o território deixa de fazer parte do  império, 
 deixando assim de contribuir para a criação e produtos e ouro.
 No caso de o império possuir a tecnologia defesas territoriais, 
 é acrescentado 1 ao  nível  de  resistência  do  território  que  é  alvo  da  invasão.
 Se  o  império  for  apenas constituído pelo Território Inicial, o sucesso da invasão leva à perda do jogo.*/
void Evento::Invasao(Jogo* j){

	string ultimo_territorio;
	bool flag = false;

	ultimo_territorio=j->getImperio()->getTerritorios()[j->getImperio()->getTerritorios().size()-1];
	
	for (int k = 0; k < j->getJogador()->getTecnologias().size(); k++)
	{
		if (j->getJogador()->getTecnologias()[k] == "defesa") {
			flag=true;
		}
	}


	for(int i=0;i< j->getImperio()->getTerritorios().size();i++)
	{
		if(j->getImperio()->getTerritorios()[i] == ultimo_territorio)
		{ 
			
			if (flag) {
				if (j->Turno() <= 6)
				{
					if (j->Fator_Sorte() + 2 > j->getMundo()->getTerritorios()[i]->getResistencia()+1) {
						j->getImperio()->Apaga_Ultimo_Elemento();
						cout << "Invasao bem sucedida!! Perda do territorio:"<< ultimo_territorio << endl;
					}
					else {
						cout<< "Invasao mal sucedida!! Continua com o territorio:" << ultimo_territorio << endl;
					}
				}

				else if (j->Turno() > 6) {
					if (j->Fator_Sorte() + 3 > j->getMundo()->getTerritorios()[i]->getResistencia()+1) {
						j->getImperio()->Apaga_Ultimo_Elemento();
						cout << "Invasao bem sucedida!! Perda do territorio:" << ultimo_territorio << endl;
					}
					else {
						cout << "Invasao mal sucedida!! Continua com o territorio:" << ultimo_territorio << endl;
					}
				}
			}
			else {
				if (j->Turno() <= 6)
				{
					if (j->Fator_Sorte() + 2 > j->getMundo()->getTerritorios()[i]->getResistencia()) {
						j->getImperio()->Apaga_Ultimo_Elemento();
						cout << "Invasao bem sucedida!! Perda do territorio:" << ultimo_territorio << endl;
					}
					else {
						cout << "Invasao mal sucedida!! Continua com o territorio:" << ultimo_territorio << endl;
					}
				}

				else if (j->Turno() > 6) {
					if (j->Fator_Sorte() + 3 > j->getMundo()->getTerritorios()[i]->getResistencia()) {
						j->getImperio()->Apaga_Ultimo_Elemento();
						cout << "Invasao bem sucedida!! Perda do territorio:" << ultimo_territorio << endl;
					}
					else {
						cout << "Invasao mal sucedida!! Continua com o territorio:" << ultimo_territorio << endl;
					}
				}
			}
		}
	}


	if (j->getImperio()->getTerritorios().size() == 1)
	{
		j->setTurno(12);
		cout << "Fim de jogo. Perdeu todos os seus territorios!!" << endl;
		j->Pontuacao();
		cout << "Pontuacao Final:"<< j->getPontuacao() << endl;
		exit(0);
	}
	
}


/*foi assinada uma aliança com um outro império do qual também não  existe  nenhum  registo. 
Em consequência  disto aforça  militar  aumenta  uma unidade, 
desde que não seja ultrapassado o máximo de unidades possíveis no império 
(caso contrário, não se ganha nada, mas o evento “conta” na mesma).*/
void Evento::Alianca_Diplomatica(Jogo* j) {

	j->getImperio()->setMilitar(j->getImperio()->getMilitar() + 1);

	if (j->getImperio()->getMilitar() <= j->getImperio()->Verifica_Limites(j))
	{
		j->getImperio()->setMilitar(j->getImperio()->getMilitar());
		cout << "Alianca definida!! Ganha mais um de forca Militar" << j->getImperio()->getMilitar() << endl;
	}

	else {
		cout << "Alianca definida!! Limite maximo militar" << endl;
		j->getImperio()->setMilitar(j->getImperio()->getMilitar() - 1);
	}
}


/*nada ocorre e todos podem dormir descansados.*/
void Evento::Sem_Evento(Jogo* j) {

	cout << "Nao ha ocorrencias de eventos! Prossiga" <<  endl;
}