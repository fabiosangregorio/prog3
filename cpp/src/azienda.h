/*
 * Company.h
 *
 *  Created on: Jan 8, 2020
 *      Author: fabio
 */

#ifndef AZIENDA_H_
#define AZIENDA_H_

#include <string>
#include <tr1/unordered_map>
#include "dipendente.h"
#include "stipendiato.h"
#include "salariato.h"
#include "reperibile.h"
#include "stagista.h"

class Azienda {
public:
	static Azienda *getInstance();
	~Azienda();

	string const& getNome() const;

	Stipendiato* nuovoStipendiato(string const& nome, string const& cognome);
	Salariato* nuovoSalariato(string const& nome, string const& cognome);
	Reperibile* nuovoReperibile(string const& nome, string const& cognome);
	Stagista* nuovoStagista(string const& nome, string const& cognome);

	Dipendente* getDipendente(long id);
	Dipendente* operator[] (long id);
	void find(string const& string);

private:
	static Azienda *instance;

	string nome;
	long ultimo_id;
	tr1::unordered_map<long, Dipendente*> dipendenti;

	Azienda();
	Azienda(Azienda const& other);
	void operator= (Azienda const& other);

	long nuovoDipendente(Dipendente* dipendente);
};

#endif /* AZIENDA_H_ */
