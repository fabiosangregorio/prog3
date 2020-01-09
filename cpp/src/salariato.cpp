/*
 * salariato.cpp
 *
 *  Created on: Jan 8, 2020
 *      Author: fabio
 */

#include "salariato.h"
#include <iostream>
#include <algorithm>

using namespace std;

Salariato::Salariato() {}

Salariato::Salariato(string const& nome, string const& cognome):
			Dipendente(nome, cognome) {}

void Salariato::stampaInfo() {
	cout << "Dipendente salariato: " << endl;
	Dipendente::stampaInfo();
}
