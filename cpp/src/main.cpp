#include <iostream>
#include "azienda.h"

using namespace std;

int main() {
	Azienda *az = Azienda::getInstance();
	az->setNome("Test");
	cout << az->getNome() << endl;

	Stipendiato* p = az->nuovoStipendiato("stip1", "cogn_stip1");
	p->stampaInfo();

	Salariato* s = az->nuovoSalariato("sal1", "cogn_sal1");
	s->stampaInfo();

	Reperibile* d = az->nuovoReperibile("rep1", "cogn_rep1");

	Dipendente* pd = (Dipendente*)d;
	pd->stampaInfo();

	az->find("cogn_sal1");

	delete az;
	return 0;
}
