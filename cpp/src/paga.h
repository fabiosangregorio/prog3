/*
 * Paga.h
 *
 *  Created on: Feb 16, 2020
 *      Author: fabio
 */

#ifndef PAGA_H_
#define PAGA_H_

#include "visitor.h"

class Paga: public ReturnVisitor<double> {
public:
	Paga();
	virtual ~Paga();

	virtual void visit(Salariato*);
	virtual void visit(Stipendiato*);
	virtual void visit(Reperibile*);
	virtual void visit(Stagista*);
};

#endif /* PAGA_H_ */
