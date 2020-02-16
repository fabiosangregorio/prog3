/*
 * Company.cpp
 *
 *  Created on: Jan 8, 2020
 *      Author: fabio
 */

#include "azienda.h"
#include "paga.h"
#include <iostream>
#include <stdlib.h>
#include <strings.h>
#include <algorithm>
#include <cctype>

using namespace std;
using namespace std::tr1;

Azienda *Azienda::instance = NULL;

Azienda::Azienda() :
		nome(""), ultimo_id(0) {
}

Azienda::~Azienda() {
	cout << endl << nome << " è stata distrutta." << endl;
	dipendenti.clear();
}

Azienda* Azienda::getInstance() {
	return instance ? instance : (instance = new Azienda());
}

string const& Azienda::getNome() const {
	return nome;
}

void Azienda::setNome(string const &nome) {
	this->nome = nome;
}

Stipendiato* Azienda::nuovoStipendiato(string const &nome,
		string const &cognome, int livello) {
	Stipendiato *s = new Stipendiato(nome, cognome, livello);
	nuovoDipendente(s);
	return s;
}

Salariato* Azienda::nuovoSalariato(string const &nome, string const &cognome) {
	Salariato *s = new Salariato(nome, cognome);
	nuovoDipendente(s);
	return s;
}

Reperibile* Azienda::nuovoReperibile(string const &nome,
		string const &cognome) {
	Reperibile *r = new Reperibile(nome, cognome);
	nuovoDipendente(r);
	return r;
}

Stagista* Azienda::nuovoStagista(string const &nome, string const &cognome) {
	Stagista *s = new Stagista(nome, cognome);
	nuovoDipendente(s);
	return s;
}

Dipendente* Azienda::getDipendente(long id) {
	unordered_map<long, Dipendente*>::const_iterator x = dipendenti.find(id);
	if (x == dipendenti.end())
		return NULL;
	return x->second;
}

void Azienda::find(string const &str) {
	cout << endl << "Ricerca di \"" << str << "\":\n";
	bool found = false;
	string str_l = str;
	std::transform(str_l.begin(), str_l.end(), str_l.begin(), ::tolower);

	for (unordered_map<long, Dipendente*>::const_iterator i =
			dipendenti.begin(); i != dipendenti.end(); ++i) {
		string cognome_l = i->second->getCognome();

		std::transform(cognome_l.begin(), cognome_l.end(), cognome_l.begin(),
				::tolower);

		if (cognome_l.find(str_l) != std::string::npos) {
			cout << i->first << "\t" << i->second->getNome() << " "
					<< i->second->getCognome() << endl;
			found = true;
		}
	}
	if (!found)
		cout << "Nessun risultato trovato." << endl;
}

void Azienda::generaPaghe() {
	Paga *paga = new Paga();

	cout << endl << "Generazione paghe:" << endl;
	for (unordered_map<long, Dipendente*>::const_iterator i =
			dipendenti.begin(); i != dipendenti.end(); ++i) {
		Dipendente *d = i->second;
		d->accept(paga);

		string const& nome = d->getNome();
		string const& cognome = d->getCognome();

		cout << nome << " " << cognome << ": " << paga->getValue() << " EUR" << endl;

		char *buff = new char[nome.length() + cognome.length() + 100];
		sprintf(buff, "..\\cyclone\\generapaghe.exe %s %s %f", nome.c_str(),
				cognome.c_str(), paga->getValue());
		cout << buff << endl;
		system(buff);
	}

	cout << "Paghe generate." << endl;
}

long Azienda::nuovoDipendente(Dipendente *d) {
	dipendenti.insert(make_pair(++ultimo_id, d));
	cout << endl << "Id " << ultimo_id << " creato." << endl;
	return ultimo_id;
}
