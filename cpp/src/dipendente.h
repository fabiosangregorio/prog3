/*
 * dipendente.h
 *
 *  Created on: Jan 8, 2020
 *      Author: fabio
 */

#ifndef DIPENDENTE_H_
#define DIPENDENTE_H_

#include "visitable.h"
#include <string>

using namespace std;

class Dipendente: public Visitable {
public:
	virtual ~Dipendente() = 0;

	string const& getCognome() const;
	void setCognome(string const& cognome);
	string const& getNome() const;
	void setNome(string const& nome);

	virtual void stampaInfo();

protected:
	Dipendente();
	Dipendente(string const& nome, string const& cognome);

private:
	string nome;
	string cognome;

	Dipendente(Dipendente const& other);
};

#endif /* DIPENDENTE_H_ */
