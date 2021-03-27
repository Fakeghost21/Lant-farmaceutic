#pragma once
#include "ArrayIteratorInterface.h"
#include <cstddef>
//#include "Container.h"

class ArrayIterator : public IIterator {
private:
	ArrayContainer* container;
	int crtPos;
public:
	ArrayIterator(ArrayContainer* ac) {
		this->container = ac;
		this->crtPos = 0;
	}

	~ArrayIterator() {

	}

	void moveNext() {
		this->crtPos++;
	}

	bool isValid() {
		return (this->crtPos < this->container->getSize());
	}

	ObjInterface* getCrtElem() {
		return this->container->elements[crtPos];
	}

	void moveFirst() {
		this->crtPos = 0;
	}

};

class IContainer {
public:
	virtual void addElem(ObjInterface*) = 0;
	virtual void delElem(ObjInterface*) = 0;
	virtual int getSize() = 0;
	virtual bool contains(ObjInterface*) = 0;

	friend class IIterator;
	virtual IIterator* getIterator() = 0;

	virtual ~IContainer() {};
};

class ArrayContainer : public IContainer {
private:
	int size;
	int capacity;
	ObjInterface** elements;
	void resize() {
		ObjInterface** aux = new ObjInterface * [(this->size / this->capacity + 1) * this->capacity];
		for (int i = 0; i < this->capacity; i++)
			aux[i] = this->elements[i]->clone();
		delete[] this->elements;
		this->elements = aux;
		this->capacity *= (this->size / this->capacity + 1);
	}
public:

	ArrayContainer(int c) {
		this->size = 0;
		this->capacity = c;
		this->elements = new ObjInterface * [c];
	}

	ArrayContainer(const ArrayContainer& AC)
	{
		this->size = AC.size;
		this->capacity = AC.capacity;
		this->elements = new ObjInterface * [AC.capacity];
		for (int i = 0; i < AC.size; i++)
			this->elements[i] = AC.elements[i]->clone();
	}

	~ArrayContainer() {
		if (this->elements)
		{
			for (int i = 0; i < this->size; i++)
			{
				if (this->elements[i])
				{
					delete this->elements[i];
					this->elements[i] = NULL;
				}
			}
			delete[] this->elements;
			this->elements = NULL;
		}
	}

	ArrayContainer& operator=(const ArrayContainer& AC) {
		if (this != &AC)
		{
			this->size = AC.size;
			this->capacity = AC.capacity;
			if (this->elements) {
				for (int i = 0; i < this->size; i++)
				{
					if (this->elements[i])
					{
						delete this->elements[i];
						this->elements[i] = NULL;
					}
				}
				delete[] this->elements;
				this->elements = NULL;
			}
			this->elements = new ObjInterface * [AC.capacity];
			for (int i = 0; i < AC.size; i++)
				this->elements[i] = AC.elements[i]->clone();
		}
		return *this;
	}

	void addElem(ObjInterface* e) {
		if (size >= capacity)
			this->resize();
		this->elements[this->size++] = e->clone();
	}

	void delElem(ObjInterface* e) {
		int i = 0;
		while (i < this->size) {
			if (e->equals(this->elements[i])) {
				delete this->elements[i]; //IE*
				for (int j = i; j < this->size - 1; j++)
					this->elements[j] = this->elements[j + 1];
				this->size--;
			}
			else
				i++;
		}
	}

	int getSize() {
		return this->size;
	}

	bool contains(ObjInterface* e) {
		for (int i = 0; i < this->size; i++)
			if (e->equals(this->elements[i]))
				return true;
		return false;
	}

	IIterator* getIterator() {
		IIterator* pit = new ArrayIterator(this);
		return pit;
	}

	friend class ArrayIterator;

};
