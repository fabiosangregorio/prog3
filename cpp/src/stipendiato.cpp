/*
 * stipendiato.cpp
 *
 *  Created on: Jan 8, 2020
 *      Author: fabio
 */

#include "stipendiato.h"
#include <iostream>
#include <algorithm>

using namespace std;

Stipendiato::Stipendiato(): livello(1) {}

Stipendiato::Stipendiato(string const& nome, string const& cognome, int livello):
			Dipendente(nome, cognome), livello(livello) {}

Stipendiato::~Stipendiato() {}

void Stipendiato::setLivello(int livello) {
	this->livello = livello;
}

int Stipendiato::getLivello() {
	return livello;
}

void Stipendiato::stampaInfo() {
	cout << "Dipendente stipendiato: " << endl;
	Dipendente::stampaInfo();
}
