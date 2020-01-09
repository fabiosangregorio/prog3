/*
 * stipendiato.h
 *
 *  Created on: Jan 8, 2020
 *      Author: fabio
 */

#ifndef STIPENDIATO_H_
#define STIPENDIATO_H_

#include "dipendente.h"
#include <vector>

using namespace std;

class Stipendiato: public virtual Dipendente {
	friend class Azienda;
	friend class Visitor;

public:
	virtual ~Stipendiato();

	virtual void stampaInfo();

	virtual void accept(Visitor* visitor) { visitor->visit(this); }

protected:
	Stipendiato();
	Stipendiato(string const& nome, string const& cognome);

private:
	Stipendiato(Stipendiato const& other);
	void operator= (Stipendiato const& other);
};

#endif /* STIPENDIATO_H_ */
