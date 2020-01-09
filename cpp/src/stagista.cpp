/*
 * stagista.cpp
 *
 *  Created on: Jan 8, 2020
 *      Author: fabio
 */

#include "stagista.h"
#include <iostream>
#include <algorithm>

using namespace std;

Stagista::Stagista() {}

Stagista::Stagista(string const& nome, string const& cognome):
		Dipendente(nome, cognome) {}

Stagista::~Stagista() {}

void Stagista::stampaInfo() {
	cout << "Dipendente stagista: " << endl;
	Dipendente::stampaInfo();
}
