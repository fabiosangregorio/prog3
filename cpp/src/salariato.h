/*
 * salariato.h
 *
 *  Created on: Jan 8, 2020
 *      Author: fabio
 */

#ifndef SALARIATO_H_
#define SALARIATO_H_

#include "dipendente.h"

using namespace std;

class Salariato: public virtual Dipendente {
	friend class Azienda;
	friend class Visitor;

public:
	virtual ~Salariato();

	void setOreLavorate(int oreLavorate);
	int getOreLavorate();

	virtual void stampaInfo();

	virtual void accept(Visitor* visitor) { visitor->visit(this); }

protected:
	Salariato();
	Salariato(string const& nome, string const& cognome);

private:
	int oreLavorate;

	Salariato(Salariato const& other);
};

#endif /* SALARIATO_H_ */
