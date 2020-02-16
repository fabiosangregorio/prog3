#include <iostream>
#include "azienda.h"

using namespace std;

int main() {
	Azienda *az = Azienda::getInstance();
	az->setNome("Test");

	Stipendiato* p = az->nuovoStipendiato("stip1", "cogn_stip1", 3);
	Salariato* s = az->nuovoSalariato("sal1", "cogn_sal1");
	s->setOreLavorate(100);
	Reperibile* r = az->nuovoReperibile("rep1", "cogn_rep1");
	r->setOreLavorate(10);
	Dipendente* pr = (Dipendente*)r;

	cout << "Nome azienda: " << az->getNome() << endl;
	p->stampaInfo();
	s->stampaInfo();
	pr->stampaInfo();

	az->find("Cogn_sal");

	az->generaPaghe();

	delete az;
	return 0;
}
