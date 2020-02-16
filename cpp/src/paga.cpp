/*
 * Paga.cpp
 *
 *  Created on: Feb 16, 2020
 *      Author: fabio
 */

#include "paga.h"
#include "stipendiato.h"
#include "salariato.h"
#include "reperibile.h"
#include "stagista.h"

double const PAGA_BASE = 1500;
double const PAGA_ORARIA = 10;
double const RIMBORSO_SPESE = 400;

Paga::Paga() {}
Paga::~Paga() {}

void Paga::visit(Stipendiato* s) {
	setValue(PAGA_BASE * s->getLivello());
}

void Paga::visit(Salariato* s) {
	setValue(PAGA_ORARIA * s->getOreLavorate());
}

void Paga::visit(Reperibile* s) {
	setValue(PAGA_BASE * s->getLivello() + PAGA_ORARIA * s->getOreLavorate());
}

void Paga::visit(Stagista* s) {
	setValue(RIMBORSO_SPESE);
}

