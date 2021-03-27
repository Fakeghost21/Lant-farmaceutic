#pragma once
#include <stdexcept>
using namespace std;
class MyExcept : public runtime_error {
private:
	string message;
public:
	MyExcept(string msg) :runtime_error(msg), message(msg) {

	}

	string getMsg()
	{
		return this->message;
	}
};