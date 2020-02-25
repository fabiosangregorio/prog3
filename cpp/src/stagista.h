/*
 * stagista.h
 *
 *  Created on: Jan 8, 2020
 *      Author: fabio
 */

#ifndef STAGISTA_H_
#define STAGISTA_H_

#include "dipendente.h"

using namespace std;

class Stagista: public virtual Dipendente {
	friend class Azienda;
	friend class Visitor;

public:
	virtual ~Stagista();

	virtual void stampaInfo();

	virtual void accept(Visitor* visitor) { visitor->visit(this); }

protected:
	Stagista();
	Stagista(string const& nome, string const& cognome);

private:
	Stagista(Stagista const& other);
};

#endif /* STAGISTA_H_ */
