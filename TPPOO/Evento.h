#pragma once
#include "Jogo.h"

class Jogo;
class Evento
{

public:
	Evento();
	~Evento();
	void Recurso_Abandonado(Jogo* j);
	void Invasao(Jogo* j);
	void Alianca_Diplomatica(Jogo* j);
	void Sem_Evento(Jogo* j);
};

