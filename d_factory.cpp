#include<iostream>
using namespace std;




//Intent

//Define an interface for creating an object, but let subclasses decide which class
//to instantiate. Factory Method lets a class defer instantiation to subclasses.

//Also Known As
//Virtual Constructor

//Motivation
//Frameworks use abstract classes to define and maintain relationships between
//objects. A framework is often responsible for creating these objects as well.

//http://www.youtube.com/watch?v=ub0DXaeV6hA





class vehicle{//interface
public:
	virtual void getvehicle()=0;
};


class car:public vehicle
{
public:
	void getvehicle(){
	cout<<"This is car"<<endl;
	}

};

class truck:public vehicle
{
	public:
	void getvehicle(){
	cout<<"This is Truck"<<endl;
	}
};


class vehcilefactory{
public:
  vehicle* getvehiclename(int i)
   {
	if (i==1)
		return new car();
	else
		return new truck();
   }
};

int main()
{
vehicle *v1;
vehcilefactory vf;
v1=vf.getvehiclename(2);
v1->getvehicle();

}