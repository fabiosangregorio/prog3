/*
 * stipendiato.h
 *
 *  Created on: Jan 8, 2020
 *      Author: fabio
 */

#ifndef STIPENDIATO_H_
#define STIPENDIATO_H_

#include "dipendente.h"

using namespace std;

class Stipendiato: public virtual Dipendente {
	friend class Azienda;
	friend class Visitor;

public:
	virtual ~Stipendiato();

	void setLivello(int livello);
	int getLivello();

	virtual void stampaInfo();

	virtual void accept(Visitor* visitor) { visitor->visit(this); }

protected:
	Stipendiato();
	Stipendiato(string const& nome, string const& cognome, int livello);

private:
	int livello;

	Stipendiato(Stipendiato const& other);
};

#endif /* STIPENDIATO_H_ */
