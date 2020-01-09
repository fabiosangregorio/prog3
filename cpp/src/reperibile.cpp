/*
 * reperibile.cpp
 *
 *  Created on: Jan 8, 2020
 *      Author: fabio
 */

#include "reperibile.h"
#include <iostream>

using namespace std;

Reperibile::Reperibile(string const& nome, string const& cognome):
		Dipendente(nome, cognome) {}

Reperibile::~Reperibile() {}

void Reperibile::stampaInfo() {
	cout << "Dipendente reperibile: ";
	Dipendente::stampaInfo();
}
