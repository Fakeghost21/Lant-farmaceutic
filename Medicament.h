#pragma once
#include "OI.h";
#include <string>
using namespace std;

class Medicament {
private:
	int id, stoc;
	bool reteta;
	string producator,nume;
public:
	Medicament() {
		this->id = -1;
		this->stoc = 0;
		this->reteta = false;
		this->nume = "";
		this->producator = "";
	}

	Medicament(int id, string nume,bool reteta, int stoc, string producator)
	{
		this->id = id;
		this->stoc = stoc;
		this->reteta = reteta;
		this->producator = producator;
		this->nume = nume;
	}

	Medicament(const Medicament& m) {
		this->id = m.id;
		this->stoc = m.stoc;
		this->reteta = m.reteta;
		this->producator = m.producator;
		this->nume = m.nume;
	}

	Medicament(string line, string delim)
	{
		this->loadFromString(line,delim);
	}

	Medicament* clone()
	{
		Medicament* m = new Medicament(this->id, this->nume, this->reteta, this->stoc, this->producator);
		return m;
	}

	int getId() {
		return this->id;
	}

	int getStoc() {
		return this->stoc;
	}

	string getNume() {
		return this->nume;
	}

	string getProducator() {
		return this->producator;
	}

	bool getReteta() {
		return this->reteta;
	}
	string getEmail() {
		return "";
	}
	int getGrad() {
		return 0;
	}

	void setGrad(int newGrad) {
		newGrad = 0;
	}

	void setId(int newId) {
		this->id = newId;
	}

	void setProducator(string newProducator) {
		this->producator = newProducator;
	}

	void setStoc(int newStoc) {
		this->stoc = newStoc;
	}

	void setReteta(int newReteta) {
		this->reteta = newReteta;
	}

	Medicament& operator=(const Medicament& m) {
		this->id = m.id;
		this->stoc = m.stoc;
		this->reteta = m.reteta;
		this->producator = m.producator;
		this->nume = m.nume;
		return *this;
	}

	bool equals(ObjInterface* OI) {
		return (this->id == ((Medicament*)OI)->id);
	}

	string toString(string delim) {
		string stoc = to_string(this->stoc);
		string id = to_string(this->id);
		string reteta = to_string(this->reteta);
		string s =id + delim + this->nume + delim + reteta + delim + stoc + delim + this->producator;
		return s;
	}

	bool operator==(const Medicament& t) {
		return(this->id == t.id and this->producator == t.producator
			and this->reteta == t.reteta and this->stoc == t.stoc
			and this->nume == t.nume);
	}

	bool operator!=(const Medicament& t) {
		return(this->id != t.id or this->producator != t.producator
			or this->reteta != t.reteta or this->stoc != t.stoc
			or this->nume != t.nume);
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
		string reteta = s.substr(0, pos);
		this->reteta = false;
		if (reteta == "1")
			this->reteta = true;
		s = s.erase(0, pos + 1);

		pos = s.find(delim);
		this->stoc = stoi(s.substr(0, pos));
		s = s.erase(0, pos + 1);

		this->producator = s.substr(0, pos);
	}
};