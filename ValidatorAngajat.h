#pragma once
#include <iostream>
#include "Angajat.h"
#include "MyExceptionClass.h"
using namespace std;
template <class T>
class ValidatorAngajat {
private:
	string msg;
public:
	ValidatorAngajat() {
	}

	~ValidatorAngajat(){
	}

	void validate(T* a)
	{
		if (typeid(*a) == typeid(Angajat))
		{
			if (a->getId() <= 0)
				msg += "Id-ul trebuie sa fie mai mare ca 0! \n";
			if (a->getGrad() < 0)
				msg += "Gradul de acces trebuie sa fie mai mare sau egal cu 0! \n";
			string name = a->getNume();
			for (int i = 0; i < name.length(); i++)
				if (name[i] >= '0' and name[i] <= '9')
				{
					msg += "Numele angajatului nu trebuie sa contina cifre! \n";
					break;
				}
			if (msg.length() > 1)
				throw MyExcept(msg);
		}
		if (typeid(*a) == typeid(Medicament))
		{
			if (a->getId() <= 0)
				msg += "Id-ul trebuie sa fie mai mare ca 0! \n";
			string name = a->getNume();
			for (int i = 0; i < name.length(); i++)
				if (name[i] >= '0' and name[i] <= '9')
				{
					msg += "Numele medicamentului nu trebuie sa contina cifre! \n";
					break;
				}
			if (a->getStoc() < 0)
				msg += "Stocul nu poate fi negativ! \n";
			string producator = a->getProducator();
			for (int i = 0; i < name.length(); i++)
				if (name[i] >= '0' and name[i] <= '9')
				{
					msg += "Numele producatorului nu trebuie sa contina cifre! \n";
					break;
				}
			if (msg.length() > 1)
				throw MyExcept(msg);
		}
	}
};