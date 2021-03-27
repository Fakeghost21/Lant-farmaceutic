/*
#pragma once
#include "ObjectInterface.h"
#include "ArrayIteratorInterface.h"

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
*/