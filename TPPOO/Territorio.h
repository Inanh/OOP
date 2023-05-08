#pragma once
#include <vector>
#include <string>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <list>


using namespace std;
class Territorio
{
	string nome;
	string tipo;
	int resistencia, criaProdutos, criaOuro, pVitoria;

public:
	Territorio(int res, int criaP, int CriaO, int PVit, string t, string nome);
	virtual~Territorio();
	//---------------------------- GETTERS ------------------------

	virtual int getMontanha_conquistada() { return 1; };
	virtual string getNome();
	virtual string getTipo();
	virtual int getResistencia();
	virtual int getCriaProdutos();
	virtual int getCriaOuro();
	virtual int getVitoria();

	
	//---------------------------- SETTERS (CASO FOR PRECISO) -----------------------
	
	virtual void setMontanha_conquistada(int mont) {};
	virtual void setResistencia(int r);
	virtual void setCriaProtudo(int p);
	virtual void setCriaOuro(int o);
	virtual void setVitoria(int v);

	virtual Territorio* duplica()const = 0;
	static Territorio* criaTerritorio(string tipo);
	virtual string getAsString() const;
};

