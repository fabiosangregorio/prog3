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

Stipendiato::Stipendiato() {}

Stipendiato::Stipendiato(string const& nome, string const& cognome):
			Dipendente(nome, cognome) {}

Stipendiato::~Stipendiato() {}

void Stipendiato::stampaInfo() {
	cout << "Dipendente stipendiato: " << endl;
	Dipendente::stampaInfo();
}
