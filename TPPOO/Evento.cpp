#include "Evento.h"

Evento::Evento(){}

Evento::~Evento(){}

/*um  recurso abandonado foi encontrado e fornece ao imp�rio uma unidade de produtos
ou de ouro conforme for encontrado  no primeiro ano  do jogo  (produto)  ou  no  segundo  (ouro). 
Caso  j�  tenha  sido  atingido  o  valor  m�ximo permitido,
o recurso encontrado � desperdi�ado (e n�o ocorre nenhum outro evento em sua substitui��o)*/
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

/*um qualquer outro imp�rio concorrente, do qual nem sequer existe qualquer registo, est�  a  tentar  conquistar  um  dos  territ�rios  do  jogador.
 Escolhe  o  territ�rio mais  recentemente  conquistado.  
 �  gerado  aleatoriamente  um  fator  sorte,  n�mero entre 1 e 6 inclusive. 
 Este fator sorte � somado � for�a da invas�o que tem o valor 2 no primeiro  ano  e  3  no  segundo  ano.
 Se  o  resultado  for  inferior  �  resist�ncia  do territ�rio, a invas�o falha.
 Caso contr�rio, a invas�o concretiza-se, e o territ�rio deixa de fazer parte do  imp�rio, 
 deixando assim de contribuir para a cria��o e produtos e ouro.
 No caso de o imp�rio possuir a tecnologia defesas territoriais, 
 � acrescentado 1 ao  n�vel  de  resist�ncia  do  territ�rio  que  �  alvo  da  invas�o.
 Se  o  imp�rio  for  apenas constitu�do pelo Territ�rio Inicial, o sucesso da invas�o leva � perda do jogo.*/
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


/*foi assinada uma alian�a com um outro imp�rio do qual tamb�m n�o  existe  nenhum  registo. 
Em consequ�ncia  disto afor�a  militar  aumenta  uma unidade, 
desde que n�o seja ultrapassado o m�ximo de unidades poss�veis no imp�rio 
(caso contr�rio, n�o se ganha nada, mas o evento �conta� na mesma).*/
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