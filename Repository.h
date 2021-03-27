#pragma once
#include <vector>
#include "ValidatorAngajat.h"
using namespace std;
template <class T>
class Repository {
protected:
	vector<T*> entity;
	ValidatorAngajat<T> vAng;
public:
	Repository();
	~Repository();

	virtual void clear();
	virtual void add(T* p);
	virtual vector<T*> getAll();
	virtual void update(T* old, T* newElem);
	virtual int getSize();
	virtual T* getPosEntity(int pos);
	virtual void saveToFile() = 0;
	virtual void loadFromFile() = 0;
	virtual void remove(int id);

};

template <class T> Repository<T>::Repository() {
}

template <class T> void Repository<T>::clear()
{
	this->entity.clear();
	this->saveToFile();
}

template <class T>Repository<T>::~Repository()
{
	this->entity.clear();
	cout << "s a apelat\n";
}

template <class T> void Repository<T>::add(T* t) throw(MyExcept)
{	
	this->vAng.validate(t);
	this->entity.push_back(t->clone());
	this->saveToFile();
}

template <class T> vector<T*> Repository<T>::getAll()
{
	return this->entity;
}

template<class T>
inline void Repository<T>::update(T* old, T* newElem)
{
	for (int i = 0; i < this->entity.size(); i++)
	{
		if ((*this->entity[i]) == *old)
		{
			delete this->entity[i];
			this->entity[i] = newElem->clone();
		}
	}
	this->saveToFile();
}

template <class T> int Repository<T>::getSize()
{
	return this->entity.size();
}

template <class T> T* Repository<T>::getPosEntity(int pos)
{
	return this->entity[pos];
}



template<class T>
inline void Repository<T>::remove(int id)
{
	T* p;
	int i = 0;
	while(i < this->entity.size() and this->entity[i]->getId() != id)
	{
		i++;
	}
	if (i < this->entity.size())
	{
		delete this->entity[i];
		this->entity.erase(this->entity.begin() + i);
		this->saveToFile();
	}

}


