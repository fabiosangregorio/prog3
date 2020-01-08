/*
 * dipendente.cpp
 *
 *  Created on: Jan 8, 2020
 *      Author: fabio
 */

#include "dipendente.h"
#include <iostream>

using namespace std;

Dipendente::Dipendente(): nome(), cognome() {}

Dipendente::Dipendente(string const& nome, string const& cognome):
		nome(nome), cognome(cognome) {}

Dipendente::~Dipendente() {}

string const& Dipendente::getCognome() const {
	return cognome;
}

void Dipendente::setCognome(string const& cognome) {
	this->cognome = cognome;
}

string const& Dipendente::getNome() const {
	return nome;
}

void Dipendente::setNome(string const& nome) {
	this->nome = nome;
}

void Dipendente::stampaInfo() {
	cout << "Nome: " << nome << ", Cognome: " << cognome << endl;
}
