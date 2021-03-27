#pragma once
#pragma once
#include "Repository.h"
#include "Medicament.h"
#include "MyExceptionClass.h"
class MedicineService {
private:
	Repository<Medicament>* r;
public:
	MedicineService() {
		this->r = NULL;
	}

	MedicineService(Repository<Medicament>& repo)
	{
		this->r = &repo;
	}

	~MedicineService() {}

	Medicament* look4id(int id)
	{
		for (int i = 0; i < r->getSize(); i++)
		{
			if ((*r->getPosEntity(i)).getId() == id)
				return r->getPosEntity(i);
		}
		throw MyExcept("Id invalid!");
	}

	void addElem(int id, string nume, bool reteta, int stoc, string producator) throw(MyExcept){
		Medicament a = Medicament(id,nume,reteta,stoc,producator);
		this->r->add(&a);
	}

	void add(Medicament a)
	{
		this->r->add(&a);
	}

	void delElem(int id)
	{
		try {
			Medicament a(*this->look4id(id));
			this->r->remove(id);
		}
		catch (MyExcept & exc)
		{
			throw exc;
		}
	}

	void remove(int id)
	{
		Medicament a(*this->look4id(id));
		this->r->remove(id);
	}

	vector<Medicament*> getALL() {
		return this->r->getAll();
	}

	void updateElements(int id, string numeN, bool retetaN, int stocN, string producatorN) {
		try {
			//this->look4id(idN);
			Medicament a = *this->look4id(id);
			Medicament aNew(id, numeN, retetaN, stocN,producatorN);
			this->r->update(&a, &aNew);
		}
		catch (MyExcept & exc) {
			throw exc;
		}
	}

	void update(Medicament* old, Medicament* newElem)
	{
		this->r->update(old, newElem);
	}

	vector<Medicament*> search(string text)
	{	
		vector<Medicament*> newVector;
		for (int i = 0; i < r->getSize(); i++)
		{
			if ((*this->r->getPosEntity(i)).getNume().find(text) != std::string::npos)
				newVector.push_back(this->r->getPosEntity(i));
		}
		return newVector;
	}

	void clearEntity() {
		this->r->clear();
	}

};