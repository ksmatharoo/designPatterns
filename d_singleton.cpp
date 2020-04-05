
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;

#include <iostream>
using namespace std ;
 
class Singleton 
{
public:
// Implement the logic here to instantiate the class for the first time by validating the 
// member pointer. If member pointer is already pointing to some valid memory it means
// that the first object is created and it should not allow for the next instantiation
// so simply return the member pointer without calling its ctor. 
static Singleton* Instance();
 
protected:
 
// Default ctor, copy-ctor and assignment operators should be as private so that nobody
// from outside can call those functions and instantiate it
 
Singleton();
Singleton(const Singleton&);
Singleton& operator= (const Singleton&);
 
private:
// A member pointer to itself which point to the firstly created object and this should be
// returned if another object is instantiated that means the second object what you 
// thought of created is nothind but the first instance
 
static Singleton* pinstance;
};
 
Singleton* Singleton::pinstance = 0;




Singleton* Singleton::Instance () 
{
if (pinstance == 0) // is it the first call?
{ 
pinstance = new Singleton; // create sole instance
}
return pinstance; // address of sole instance
}

Singleton::Singleton() 
{ 
//... perform necessary instance initializations 
cout << "Hellow\n" ;
}
 
 
int main()
{
Singleton *p1 = Singleton::Instance();

//Singleton *p2 = p1->Instance();
//Singleton & ref = * Singleton::Instance();
 
return 0 ;
}



/*
#include <iostream>

using namespace std;

class Singleton
{
private:
    static bool instanceFlag;
    static Singleton *single;
    Singleton()
    {
        //private constructor
    }
public:
    static Singleton* getInstance();
    void method();
    ~Singleton()
    {
        instanceFlag = false;
    }
};

bool Singleton::instanceFlag = false;
Singleton* Singleton::single = NULL;
Singleton* Singleton::getInstance()
{
    if(! instanceFlag)
    {
        single = new Singleton();
        instanceFlag = true;
        return single;
    }
    else
    {
        return single;
    }
}

void Singleton::method()
{
    cout << "Method of the singleton class" << endl;
}

int main()
{
    Singleton *sc1,*sc2;
    sc1 = Singleton::getInstance();
    sc1->method();
    sc2 = Singleton::getInstance();
    sc2->method();

    return 0;
}

*/