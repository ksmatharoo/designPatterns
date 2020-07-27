#include<iostream>
#include<vector>
#include<string>
#include <memory>
#include <iostream>
#include <vector>
using namespace std;

#define PRINT cout<<__FUNCTION__<<endl;

class car
{
public:
	car() {}
	virtual ~car() {
		PRINT
	}

	virtual void assemble() = 0;
	virtual int cost() = 0;
};

class basic_car :public car
{
public:
	~basic_car() {
		PRINT
	}
	void assemble() { PRINT }
	int cost() { return 1000; }
};

class decorator :public car {
public:
	car *_ptr;
	decorator(car* _p) :_ptr(_p) {}
	~decorator() {
		delete this->_ptr;
		PRINT
	}
	int cost()
	{
		return _ptr->cost();
	}
	void assemble()
	{
		_ptr->assemble();
	}
};

class sportscar :public decorator
{
public:
	sportscar(car * _p) :decorator(_p) {}
	~sportscar() {
		PRINT
	}


	int cost()
	{
		return 500 + decorator::cost();
	}
	void assemble()
	{
		PRINT
			decorator::assemble();
	}
};

class luxarycar :public decorator
{
public:
	luxarycar(car* _p) :decorator(_p) {}
	~luxarycar() {
		PRINT
	}

	int cost()
	{
		return 700 + decorator::cost();
	}
	void assemble()
	{
		PRINT
			decorator::assemble();
	}
};

int main() {
	{
		unique_ptr<car> c = make_unique<sportscar>(new luxarycar(new basic_car()));
		//unique_ptr<car> c = unique_ptr<car>(new sportscar(new luxarycar(new basic_car())));
		c->assemble();
		cout << c->cost() << endl;
	}
	return 0;
}

