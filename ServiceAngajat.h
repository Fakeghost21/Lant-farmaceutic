#pragma once
#include "Repository.h"
#include "Angajat.h"
#include "MyExceptionClass.h"
#include <cstdlib>
string pool = "ABCDEFHIJKLMNOPQRSTUWY"
"abcdefghijklmopqrstuwxy";
int poolSize = sizeof(pool) - 1;
class ServiceAngajat {
private:
	Repository<Angajat>* r;
public:
	ServiceAngajat() {
		this->r = NULL;
	}

	ServiceAngajat(Repository<Angajat>& repo)
	{
		this->r = &repo;
	}

	~ServiceAngajat(){}

	Angajat* look4id(int id)
	{
		for (int i = 0; i < r->getSize(); i++)
		{
			if ((*r->getPosEntity(i)).getId() == id)
				return r->getPosEntity(i);
		}
		throw MyExcept("Id invalid!");
	}

	Angajat* look4email(string email)
	{
		for (int i = 0; i < r->getSize(); i++)
		{
			if ((*r->getPosEntity(i)).getEmail() == email)
				return r->getPosEntity(i);
		}
		throw MyExcept("Email invalid!");
	}

	bool logIn(string username, int password)
	{
		try {
			Angajat a = *this->look4id(password);
			a = *this->look4email(username);
			return true;
		}
		catch (MyExcept & exc)
		{
			throw exc;
		}
	}

	void addElem(int idN, string numeN, string emailN, int gradAccesN) throw(MyExcept) {
		Angajat a;
		Angajat b = Angajat(idN, numeN, emailN, gradAccesN);
		a = b;
		this->r->add(&a);
	}

	void schimbareGrad(int id, int newGrad) throw(MyExcept)
	{
		Angajat a = *this->look4id(id);
		a.setGrad(newGrad);
		this->r->update(this->look4id(id), &a);
	}

	void delElem(int id)
	{
		try {
			Angajat a(*this->look4id(id));
			this->r->remove(id);
		}
		catch (MyExcept & exc)
		{
			throw exc;
		}
	}

	vector<Angajat*> getALL() {
		return this->r->getAll();
	}

	void updateElements(int idN, string numeN, string emailN, int gradAccesN) {
		try {
			//this->look4id(idN);
			Angajat a = *this->look4id(idN);
			Angajat aNew(idN, numeN, emailN, gradAccesN);
			this->r->update(&a, &aNew);
		}
		catch (MyExcept & exc) {
			throw exc;
		}
	}

	char getRandomCharacter()
	{
		return pool[rand() % poolSize];
	}
	string randomStrings()
	{
		string s;
		for (int i = 0; i <= 10; i++)
			s += this->getRandomCharacter();
		return s;
	}
	Angajat generareRandom()
	{
		string nume, email;
		nume = this->randomStrings();
		email = this->randomStrings();
		int id = rand() % 10000;
		int gradAcces = rand() % 100;
		Angajat a(id, nume, email, gradAcces);
		return a;
	}

	void clearEntity() {
		this->r->clear();
	}

};