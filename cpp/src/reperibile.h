/*
 * reperibile.h
 *
 *  Created on: Jan 8, 2020
 *      Author: fabio
 */

#ifndef REPERIBILE_H_
#define REPERIBILE_H_

#include "salariato.h"
#include "stipendiato.h"

using namespace std;

class Reperibile: public virtual Salariato, public virtual Stipendiato {
	friend class Azienda;
	friend class Visitor;

public:
	virtual ~Reperibile();
	virtual void stampaInfo();
	virtual void accept(Visitor* visitor) { visitor->visit(this); }

protected:
	Reperibile(string const& nome, string const& cognome);

private:
	Reperibile(Reperibile const& other);
	void operator= (Reperibile const& other);
};

#endif /* REPERIBILE_H_ */
