/*
 * Company.cpp
 *
 *  Created on: Jan 8, 2020
 *      Author: fabio
 */

#include "azienda.h"
#include <iostream>
#include <strings.h>

using namespace std;
using namespace std::tr1;

Azienda *Azienda::instance = NULL;

Azienda::Azienda(): nome(""), ultimo_id(0) {}

Azienda::~Azienda() {
	cout << endl << nome << "è stata distrutta." << endl;
	dipendenti.clear();
}

Azienda *Azienda::getInstance() {
	return instance ? instance : (instance = new Azienda());
}

string const& Azienda::getNome() const {
	return nome;
}

void Azienda::setNome(string const& nome) {
	this->nome = nome;
}

Stipendiato* Azienda::nuovoStipendiato(string const& nome, string const& cognome) {
	Stipendiato* s = new Stipendiato(nome, cognome);
	nuovoDipendente(s);
	return s;
}

Salariato* Azienda::nuovoSalariato(string const& nome, string const& cognome) {
	Salariato* s = new Salariato(nome, cognome);
	nuovoDipendente(s);
	return s;
}

Reperibile* Azienda::nuovoReperibile(string const& nome, string const& cognome) {
	Reperibile* r = new Reperibile(nome, cognome);
	nuovoDipendente(r);
	return r;
}

Stagista* Azienda::nuovoStagista(string const& nome, string const& cognome) {
	Stagista* s = new Stagista(nome, cognome);
	nuovoDipendente(s);
	return s;
}

Dipendente* Azienda::getDipendente(long id) {
	unordered_map<long, Dipendente*>::const_iterator x = dipendenti.find(id);
	if(x == dipendenti.end()) return NULL;
	return x->second;
}

void Azienda::find(string const& str) {
	cout << endl << "Ricerca di \"" << str << "\": ";

	for(unordered_map<long, Dipendente*>::const_iterator i = dipendenti.begin(); i != dipendenti.end(); ++i) {
		string const& nome =    i->second->getNome();
		string const& cognome = i->second->getCognome();
		if(str.find(cognome))
			cout << i->first << "\t" << nome << " " << cognome << endl;
	}
}

long Azienda::nuovoDipendente(Dipendente* d) {
	dipendenti.insert(make_pair(++ultimo_id, d));
	cout << endl << "Id " << ultimo_id << " creato." << endl;
	return ultimo_id;
}






















