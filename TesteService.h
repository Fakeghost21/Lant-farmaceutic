#pragma once
#include <iostream>
using namespace std;
#include "Repository.h"
#include "RepositoryFileTXT.h"
#include "RepositoryFileCSV.h"
#include "ServiceAngajat.h"
#include "ServiceMedicament.h"
#include <assert.h>
#include <cstdlib>
class TesteService {
private:
	ServiceAngajat angajat;
	MedicineService medicament;
	void testeCRUD() {
		this->angajat.clearEntity();
		assert(this->angajat.getALL().size() == 0);
		this->angajat.addElem(124, "Alina", "a@yahoo.com", 12);
		assert(this->angajat.getALL()[0]->toString(" ") == "124 Alina a@yahoo.com 12");
		assert(this->angajat.getALL().size() == 1);
		this->angajat.updateElements(124, "Raluca", "r@yahoo.com", 0);
		assert(this->angajat.getALL()[0]->getNume() == "Raluca");
		assert(this->angajat.getALL()[0]->getEmail() == "r@yahoo.com");
		assert(this->angajat.getALL()[0]->getGrad() == 0);
		this->angajat.delElem(124);
		assert(this->angajat.getALL().size() == 0);
		this->medicament.clearEntity();
		this->medicament.addElem(121, "Panadol", 0, 100, "Bby");
		this->medicament.addElem(12, "Paracetamol", 1, 1080, "Portal");
		this->medicament.addElem(11, "Spasmocalm", 0, 10, "Calmin");
		this->medicament.addElem(101, "Cicatidin", 1, 1006, "B");
		assert(this->medicament.getALL().size() == 4);
		this->medicament.delElem(101);
		this->medicament.delElem(12);
		assert(this->medicament.getALL().size() == 2);
		this->medicament.updateElements(121, "Monoglu", 0, 900, "VitaPlus");
		assert(this->medicament.getALL()[0]->getProducator() == "VitaPlus");

	}

	void testeCerinta()
	{
		Repository<Medicament>* repoT = new RepositoryFileCSV<Medicament>("MedicamentOut_Test.csv");
		MedicineService* service = new MedicineService(*repoT);
		Medicament* m1 = new Medicament(100, "parasinus", false, 10, "p1");
		Medicament* m2 = new Medicament(200, "ketonal", false, 90, "p2");
		Medicament* m3 = new Medicament(300, "antibiotic", true, 70, "p3");
		service->clearEntity();
		service->add(*m1);
		service->add(*m2);
		assert(service->getALL().size() == 2);
		assert(*service->getALL()[0] == *m1);
		assert(*service->getALL()[1] == *m2);
		service->add(*m3);
		assert(*service->getALL()[2] == *m3);

		assert(service->search("ic").size() == 1);
		assert(service->search("a").size() == 3);

		Medicament m1_new(100, "altceva", false, 50, "p1");
		service->update(m1, &m1_new);
		assert(service->search("al").size() == 2);
		assert(*service->search("al")[0] == m1_new);
		assert(*service->search("al")[1] == *m2);
		service->remove(200);
		assert(service->search("al").size() == 1);
		assert(*service->search("al")[0] == m1_new);
		delete m3;
		delete m2;
		delete m1;
	}
	
	void testeExceptii() {
		this->angajat.clearEntity();
		Angajat a1(100, "Raul", "raul@yahoo.com", 0);
		Angajat a2(105, "Paul", "paul@yahoo.com", 0);
		Angajat a3(120, "John", "jay@gmail.com", 0);
		angajat.addElem(100, "Raul", "raul@yahoo.com", 0);
		angajat.addElem(105, "Paul", "paul@yahoo.com", 0);
		angajat.addElem(120, "John", "jay@gmail.com", 0);
		try {
			Angajat a4 = *this->angajat.look4email("john@gmail.com");
		}
		catch (MyExcept & exc)
		{
			assert(true);
		}
		try {
			Angajat a4 = *this->angajat.look4email("paul@yahoo.com");
			assert(a4 == a2);
		}
		catch (MyExcept & exc)
		{
			assert(false);
		}
		try {
			Angajat a4 = *this->angajat.look4id(106);
		}
		catch (MyExcept & exc)
		{
			assert(true);
		}
		try {
			Angajat a4 = *this->angajat.look4id(105);
			assert(a4 == a2);
		}
		catch (MyExcept & exc)
		{
			assert(false);
		}
		try {
			this->angajat.delElem(109);
		}
		catch (MyExcept & exc)
		{
			assert(true);
		}
		try {
			this->angajat.delElem(120);
			assert(this->angajat.getALL().size() == 2);
		}
		catch (MyExcept & exc)
		{
			assert(false);
		}
		try {
			this->angajat.updateElements(104,"Daniel","daniel@gmail.com",17);
		}
		catch (MyExcept & exc)
		{
			assert(true);
		}
		try {
			this->angajat.updateElements(100, "Daniel", "daniel@gmail.com", 17);
			assert(this->angajat.getALL()[0]->getNume() == "Daniel");
		}
		catch (MyExcept & exc)
		{
			assert(false);
		}
		this->medicament.clearEntity();
		this->medicament.addElem(121, "Panadol", 0, 100, "Bby");
		this->medicament.addElem(12, "Paracetamol", 1, 1080, "Portal");
		this->medicament.addElem(11, "Spasmocalm", 0, 10, "Calmin");
		this->medicament.addElem(101, "Cicatidin", 1, 1006, "B");
		try {
			this->medicament.delElem(100);
		}
		catch (MyExcept & e)
		{
			assert(true);
		}
		try {
			this->medicament.delElem(11);
			assert(this->medicament.getALL().size() == 3);
		}
		catch (MyExcept & e)
		{
			assert(false);
		}
		try {
			this->medicament.updateElements(500, "dyd", 1, 2000, "fygsudkjf");
		}
		catch (MyExcept & e)
		{
			assert(true);
		}
		try {
			this->medicament.updateElements(12, "dyd", 1, 2000, "fygsudkjf");
		}
		catch (MyExcept & e)
		{
			assert(false);
		}


	}
	void testLogin() {
		this->angajat.clearEntity();
		angajat.addElem(100, "Raul", "raul@yahoo.com", 0);
		angajat.addElem(105, "Paul", "paul@yahoo.com", 0);
		angajat.addElem(120, "John", "jay@gmail.com", 0);
		string username = "smiley@yahoo.com";
		int password = 120;
		try {
			this->angajat.logIn(username, password);
		}
		catch (MyExcept & e)
		{
			assert(true);
		}
		username = "jay@gmail.com";
		try {
			assert(this->angajat.logIn(username, password) == true);
		}
		catch (MyExcept & e)
		{
			assert(false);
		}
	}
	void testRandom()
	{
		int capacity = 100 + rand() % 100;
		Repository<Angajat>* repoTestAng = new RepositoryFileCSV<Angajat>("AngajatTestRandom.txt");
		ServiceAngajat sAngTest(*repoTestAng);
		sAngTest.clearEntity();
		for (int i = 0; i < capacity; i++)
		{
			Angajat a = this->angajat.generareRandom();
			sAngTest.addElem(a.getId(), a.getNume(), a.getEmail(), a.getGrad());
		}
		int nrLogin = rand() % capacity;
		int verify;
		for (int i = 0; i < 1000; i++)
		{
			verify = rand() % capacity;
			if (sAngTest.getALL()[nrLogin]->getGrad() > sAngTest.getALL()[verify]->getGrad())
			{
				sAngTest.schimbareGrad(sAngTest.getALL()[verify]->getId(), -1);
				//assert(sAngTest.getALL()[verify]->getGrad() == -1);
			}
			else assert(sAngTest.getALL()[nrLogin]->getGrad() <= sAngTest.getALL()[verify]->getGrad());
		}

	}
public:
	TesteService(ServiceAngajat& s1, MedicineService& s2)
	{
		this->angajat = s1;
		this->medicament = s2;
	}
	void testAllService() {
		this->testeCRUD();
		this->testeExceptii();
		this->testLogin();
		this->testeCerinta();
		this->testRandom();
		cout << "Au rulat testele pentru Service!" << endl;
	}
};