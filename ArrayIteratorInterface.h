#pragma once
#include "ObjectInterface.h"

class IIterator {
public:
	virtual void moveNext() = 0;
	virtual bool isValid() = 0;
	virtual ObjInterface* getCrtElem() = 0;
	virtual void moveFirst() = 0;
	virtual ~IIterator() {};
};