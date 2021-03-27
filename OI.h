#pragma once
#include <string>
using namespace std;
class IE {
public:
	virtual IE* clone() = 0;
	virtual void copy(IE*) = 0;
	virtual bool operator==(IE*) = 0;
	virtual string toString(string delim) = 0;
	virtual ~IE() {};
};