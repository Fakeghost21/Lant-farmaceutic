#pragma once
#include "ObjectInterface.h"
#include <string>
using namespace std;

class Angajat {
private:
	int id, gradAcces;
	string nume;
	string email;
public:
	Angajat() {
		this->id = -1;
		this->gradAcces = 0;
		this->nume = "";
		this->email = "";
	}

	Angajat(int idN, string numeN, string emailN, int gradAccesN) {
		this->id = idN;
		this->nume = numeN;
		this->email = emailN;
		this->gradAcces = gradAccesN;
	}

	Angajat(const Angajat& a) {
		this->id = a.id;
		this->nume = a.nume;
		this->email = a.email;
		this->gradAcces = a.gradAcces;
	}

	Angajat(string line, string delim) {
		this->loadFromString(line, delim);
	}
	
	int getId() {
		return this->id;
	}

	int getStoc() {
		return 0;
	}
	string getProducator() {
		return "";
	}

	bool getReteta() {
		return false;
	}

	int getGrad() {
		return this->gradAcces;
	}

	string getNume() {
		return this->nume;
	}

	string getEmail() {
		return this->email;
	}

	void setId(int newId) {
		this->id = newId;
	}

	void setNume(string newNume) {
		this->nume = newNume;
	}

	void setGrad(int newGrad) {
		this->gradAcces = newGrad;
	}

	void setEmail(string newEmail) {
		this->email = newEmail;
	}

	Angajat* clone()
	{
		Angajat* a = new Angajat(this->id, this->nume, this->email, this->gradAcces);
		return a;
	}

	void operator=(const Angajat& a) {
		this->id = a.id;
		this->nume = a.nume;
		this->email = a.email;
		this->gradAcces = a.gradAcces;
		//return *this;
	}

	string toString(string delim) {
		string grad = to_string(this->gradAcces);
		string id = to_string(this->id);
		string s =id + delim + this->nume + delim + this->email + delim + grad;
		return s;
	}

	bool operator==(const Angajat& t) {
		return(this->id == t.id and this->email == t.email
			and this->gradAcces == t.gradAcces and this->nume == t.nume);
	}

	bool operator!=(const Angajat& t) {
		return(this->id != t.id and this->email != t.email
			and this->gradAcces != t.gradAcces and this->nume != t.nume);
	}

	void loadFromString(string s, string delim)
	{
		int pos;

		pos = s.find(delim);
		this->id = stoi(s.substr(0, pos));
		s = s.erase(0, pos + 1);

		pos = s.find(delim);
		this->nume = s.substr(0, pos);
		s = s.erase(0, pos + 1);

		pos = s.find(delim);
		this->email = s.substr(0, pos);
		s = s.erase(0, pos + 1);

		this->gradAcces = stoi(s.substr(0));
	}
};