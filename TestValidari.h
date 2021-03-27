#pragma once
#include <iostream>
using namespace std;
#include "Repository.h"
#include "RepositoryFileTXT.h"
#include "RepositoryFileCSV.h"
#include "ServiceAngajat.h"
#include "ServiceMedicament.h"
#include <assert.h>
class TestValidare {
public:
	void testALL()
	{
		Medicament m1 = Medicament(-100, "paaracetamol", false, 10, "Protect");
		Repository<Medicament>* repo = new RepositoryFileCSV<Medicament>();
		Repository<Angajat>* repo2 = new RepositoryFileCSV<Angajat>();
		Medicament m2 = Medicament(100, "paaracetamol", false, 10, "Protect");
		try {
			repo->add(&m2);
		}
		catch (MyExcept & exc)
		{
			assert(false);
		}
		try {
			repo->add(&m1);
		}
		catch (MyExcept & exc)
		{
			assert(true);
		}
		m1 = Medicament(100, "paarac21etamol", false, -10, "Protect");
		try {
			repo->add(&m1);
		}
		catch (MyExcept & exc)
		{
			assert(true);
		}
		Angajat a1 = Angajat(-14324, "svaj", "dasfty", -4);
		try {
			repo2->add(&a1);
		}
		catch (...)
		{
			assert(true);
		}
		cout << "Testele de la validari au functionat! \n";
	}
};