#pragma once
#include <string.h>
#include <fstream>
#include <iostream>
#include "Repository.h"
using namespace std;
template <class T>
class RepositoryFileTXT : public Repository<T>
{
private:
	string fileNameIn;
public:
	RepositoryFileTXT()
	{
		this->fileNameIn = "";
	}
	RepositoryFileTXT(string fileNameIn)
	{
		this->fileNameIn = fileNameIn;
		this->loadFromFile();
	}
	~RepositoryFileTXT() {};

	void setFileNameIn(string fileNameIn)
	{
		this->fileNameIn = fileNameIn;
	}

	//void update(T* old, T* newElem);
	void loadFromFile()
	{
		ifstream f(this->fileNameIn);
		if (f.is_open())
		{
			//this->emptyRepo();
			string linie;
			string delim = " ";
			while (getline(f, linie))
			{
				T ob(linie, " ");
				this->entity.push_back(ob.clone());
			}
			f.close();
		}
	}
	void saveToFile()
	{
		if (this->fileNameIn != "")
		{
			ofstream f(this->fileNameIn);
			for (T* crt : this->entity)
			{
				f << crt->toString(" ") << endl;
			}
			f.close();
		}
	}
	//void remove(int id);
};
