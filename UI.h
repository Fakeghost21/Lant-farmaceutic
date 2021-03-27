#pragma once
#include "ServiceAngajat.h"
#include "ServiceMedicament.h"
#include <iostream>
using namespace std;
class UI {
private:
	ServiceAngajat angajat;
	MedicineService medicament;

	void showMenuAngajat() {
		cout << "1.Adaugare angajat : \n"
			<< "2.Stergere angajat : \n"
			<< "3.Actualizare angajat : \n"
			<< "4.Afisare toti angajatii : \n"
			<< "5.Schimbare grad angajat : \n"
			<< "x.Inapoi \n";
	}
	void showMenuMedicament() {
		cout << "1.Adaugare medicament : \n"
			<< "2.Stergere medicament : \n"
			<< "3.Actualizare medicament : \n"
			<< "4.Afisare toate medicamentele : \n"
			<< "5.Cautare medicament dupa o portiune din nume : \n"
			<< "x.Inapoi \n";
	}
	void showMenuPrincipal() {
		cout << "1.Angajati \n"
			<< "2.Medicamente \n"
			<< "x.Log Out \n";
	}

	void adaugareAngajat() {
		//int idN, string numeN, string emailN, int gradAccesN
		int id, gradAcces;
		string email, nume;
		cout << "Id-ul angajatului : "; cin >> id;
		cout << "Numele angajatului : "; cin >> nume;
		cout << "Email-ul angajatului : "; cin >> email;
		cout << "Gradul de acces : "; cin >> gradAcces;
		try
		{
			angajat.addElem(id, nume, email, gradAcces);
		}
		catch (MyExcept & exc) {
			cout << exc.getMsg() << endl;
		}
		//cout << "Angajatul a fost adaugat! \n";
	}
	void stergereAngajat() {
		int idDel;
		cout << "Id-ul angajatului pe care doriti sa il stergeti : "; cin >> idDel;
		try {
			angajat.delElem(idDel);
		}
		catch (MyExcept & exc)
		{
			cout << exc.getMsg() << endl;
		}
		//cout << "Angajatul a fost sters! \n";
	}
	void actualizareAngajat() {
		int idUp, gradAcces;
		string email, nume;
		cout << "Id-ul angajatului pe care doriti sa il actualizati : "; cin >> idUp;
		cout << "Numele noului angajat : "; cin >> nume;
		cout << "Email-ul noului angajat : "; cin >> email;
		cout << "Gradul nou de acces : "; cin >> gradAcces;
		try {
			angajat.updateElements(idUp, nume, email, gradAcces);
		}
		catch (MyExcept & exc) {
			cout << exc.getMsg() << endl;
		}
		//cout << "Angajatul a fost actualizat! \n";
	}
	void afisareAngajati() {
		for (int i = 0; i < angajat.getALL().size(); i++)
		{
			cout << angajat.getALL()[i]->toString(" * ") << endl;
		}
		cout << endl;
	}

	void schimbareGradAngajat() {
		int id,newGrad;
		cout << "Id-ul angajatului : ";
		cin >> id;
		cout << "Noul grad de acces : ";
		cin >> newGrad;
		this->angajat.schimbareGrad(id, newGrad);
	}

	void adaugareMedicament()
	{
		int id, stoc;
		bool reteta;
		string producator,nume;
		//int id, string nume, bool reteta, int stoc, string producator
		cout << "Id-ul medicamentului : "; cin >> id;
		cout << "Numele medicamentului : "; cin >> nume;
		cout << "Numele producatorului : "; cin >> producator;
		cout << "Numarul de stoc : "; cin >> stoc;
		cout << "Este nevoie de reteta(0 sau 1) : "; cin >> reteta;		
		try
		{
			medicament.addElem(id, nume, reteta, stoc, producator);
		}
		catch (MyExcept & exc) {
			cout << exc.getMsg() << endl;
		}
	}
	void stergereMedicament()
	{
		int idDel;
		cout << "Id-ul medicamentului de sters : "; cin >> idDel;

		medicament.delElem(idDel);
	}
	void actualizareMedicament()
	{
		int idUp, stoc, reteta;
		string producator,nume;
		cout << "Id-ul medicamentului de actualizat : "; cin >> idUp;
		cout << "Numele medicamentului : "; cin >> nume;
		cout << "Numele noului producat : "; cin >> producator;
		cout << "Numarul nou de stoc : "; cin >> stoc;
		cout << "Este nevoie de reteta(0 sau 1) : "; cin >> reteta;
		medicament.updateElements(idUp, nume, reteta, stoc, producator);
	}
	void afisareMedicamente()
	{
		for (int i = 0; i < medicament.getALL().size(); i++)
		{	
			cout << medicament.getALL()[i]->toString(" * ") << endl;
		}
		cout << endl;
	}
	void cautareMedicament()
	{	
		string part;
		cout << "Portiunea din numele medicamentului pe care il cautati : ";
		cin >> part;
		for (int i = 0; i < this->medicament.search(part).size(); i++)
		{
			cout << this->medicament.search(part)[i]->toString(" * ") << endl;
		}
		cout << endl;

	}

	void menuLogare()
	{
		cout << "*.Login \n"
			<< "x.Iesire din program  \n";
	}

	void UImenuLogare()
	{	
		string emailUser,option,optiune1,optiune2,optiune3;
		int password;
		while (true)
		{
			this->menuLogare();
			cout << "Optiune : ";
			cin >> option;
			try {
				if (option == "*")
				{
					try {
						cout << "Autentificare : \n";
						cout << "Adresa de email : "; cin >> emailUser;
						cout << "Parola : "; cin >> password;
						this->angajat.logIn(emailUser, password);
						while (true)
						{
							try {
								this->showMenuPrincipal();
								cout << "Optiune : ";
								cin >> optiune1;
								if (optiune1 == "1")
								{
									while (true)
									{
										this->showMenuAngajat();
										cout << "Opiune : "; cin >> optiune2;
										if (optiune2 == "1")
											this->adaugareAngajat();
										else if (optiune2 == "2")
											this->stergereAngajat();
										else if (optiune2 == "3")
											this->actualizareAngajat();
										else if (optiune2 == "4")
											this->afisareAngajati();
										else if (optiune2 == "5")
											this->schimbareGradAngajat();
										else if (optiune2 == "x")
											break;
										else throw MyExcept("Optiune invalida!");
									}
								}
								else if (optiune1 == "2")
								{
									while (true)
									{
										this->showMenuMedicament();
										cout << "Optiune : "; cin >> optiune3;
										if (optiune3 == "1")
											this->adaugareMedicament();
										else if (optiune3 == "2")
											this->stergereMedicament();
										else if (optiune3 == "3")
											this->actualizareMedicament();
										else if (optiune3 == "4")
											this->afisareMedicamente();
										else if (optiune3 == "5")
											this->cautareMedicament();
										else if (optiune3 == "x")
											break;
										else throw MyExcept("Optiune invalida!");
									}
								}
								else if (optiune1 == "x")
								{
									break;
								}
								else throw MyExcept("Optiune invalida!");
							}
							catch (MyExcept & exc) {
								cout << exc.getMsg() << endl;
							}
						}

					}
					catch (MyExcept & exc)
					{
						cout << exc.getMsg() << endl;
					}
				}
				else if (option == "x")
				{	
					cout << "Ati iesit din program! \n";
					break;
				}
				else throw MyExcept("Optiune invalida!");
			}
			catch (MyExcept & exc)
			{
				cout << exc.getMsg() << endl;
			}
		}
	}

public:
	UI(ServiceAngajat& ang, MedicineService& med) {
		this->angajat = ang;
		this->medicament = med;
	}
	void run_console()
	{
		this->UImenuLogare();
	}
};