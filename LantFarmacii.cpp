#include <iostream>
using namespace std;
#include "Angajat.h"
#include "Medicament.h"
#include "Repository.h"
#include "RepositoryFileTXT.h"
#include "RepositoryFileCSV.h"
#include "ServiceAngajat.h"
#include "ServiceMedicament.h"
#include "UI.h"
#include "TesteService.h"
#include <assert.h>
#include "TestValidari.h"

int main()
{	
	Repository<Medicament>* repo = new RepositoryFileTXT<Medicament>();
	Medicament* m1 = new Medicament(100, "parasinus", false, 10, "p1");
	Medicament* m2 = new Medicament(200, "ketonal", false, 90, "p2");
	Medicament* m3 = new Medicament(300, "antibiotic", true, 70, "p3");

	repo->add(m1);
	repo->add(m2);
	assert(repo->getAll().size() == 2);
	assert(*repo->getAll()[0] == *m1);
	assert(*repo->getAll()[1] == *m2);
	repo->add(m3);
	assert(*repo->getAll()[2] == *m3);

	Medicament m1_new(100, "paracetamol", false, 50, "p1");
	repo->update(m1, &m1_new);
	assert(*repo->getAll()[0] != *m1);
	assert(*repo->getAll()[0] == m1_new);

	repo->remove(200);
	assert(repo->getAll().size() == 2);
	Repository<Medicament>* repoTestMed = new RepositoryFileCSV<Medicament>("MedicamentOut_Test.csv");
	Repository<Angajat>* repoTestAng = new RepositoryFileCSV<Angajat>("AngajatOut_Test.csv");
	ServiceAngajat sAngTest(*repoTestAng);
	MedicineService sMedTest(*repoTestMed);
	TesteService t(sAngTest, sMedTest);
	t.testAllService();
	TestValidare t2;
	t2.testALL();
	delete repoTestAng;
	delete repoTestMed;
	string text;
	while (true)
	{
		try {
			cout << "TXT sau CSV : ";
			cin >> text;
			if (text == "TXT" or text == "CSV")
			{
				Repository<Medicament>* repo = new RepositoryFileCSV<Medicament>("MedicamentOut.csv");
				Repository<Angajat>* repo2 = new RepositoryFileCSV<Angajat>("AngajatOut.csv");
				if (text == "TXT")
				{
					repo = new RepositoryFileTXT<Medicament>("MedicamentOut.txt");
					repo2 = new RepositoryFileTXT<Angajat>("AngajatulLunii.txt");
				}
				MedicineService s(*repo);
				ServiceAngajat s2(*repo2);
				UI u(s2, s);
				u.run_console();
				delete repo;
				delete repo2;
			}
			else throw MyExcept("Extensie fisier invalida!");
			break;
		}
		catch (MyExcept & exc) {
			cout << exc.getMsg() << endl;
		}
	}
	return 0;
}
