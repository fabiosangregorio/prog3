/*
 * salariato.h
 *
 *  Created on: Jan 8, 2020
 *      Author: fabio
 */

#ifndef SALARIATO_H_
#define SALARIATO_H_

#include "dipendente.h"
#include <vector>

class Salariato: public virtual Dipendente {
	friend class Azienda;
	friend class Visitor;

public:
	virtual ~Salariato();


};

#endif /* SALARIATO_H_ */
