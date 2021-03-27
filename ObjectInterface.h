#pragma once

class ObjInterface {
public:
	virtual ObjInterface* clone() = 0;
	virtual void copy(ObjInterface*) = 0;
	virtual bool equals(ObjInterface*) = 0;
	virtual string toString() = 0;
	virtual ~ObjInterface() {};
	virtual bool operator==(ObjInterface*) = 0;
};