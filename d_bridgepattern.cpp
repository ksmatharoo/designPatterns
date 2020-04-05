#include<iostream>
using namespace std;


//Intent

//Decouple an abstraction from its implementation so that the two can vary
//independently.

//Also Known As

//Handle/Body

//Motivation

//When an abstraction can have one of several possible implementations, the usual
//way to accommodate them is to use inheritance. An abstract class defines the
//interface to the abstraction, and concrete subclasses implement it in different
//ways. But this approach isn't always flexible enough. Inheritance binds an
//implementation to the abstraction permanently, which makes it difficult to modify,
//extend, and reuse abstractions and implementations independently.
//

//http://www.youtube.com/watch?v=9jIgSsIfh_8

class entertainmentdevice{
public:
    int devicestate;
    int maxsetting;
    int volume;
    entertainmentdevice():volume(0){};

    virtual void buttonfive()
    {
      volume++;
      cout<<"volume->"<<volume<<endl;   
    }
    virtual void buttonseven()
    {
      volume--;
      cout<<"volume->"<<volume<<endl;   
    }

};

class tv : public entertainmentdevice{
public :
    tv(int newdevicestate,int newmaxsetting)
    {
        devicestate=newdevicestate;
        maxsetting=newmaxsetting;
    }
    virtual void buttonfive()
    {
      devicestate++;
      cout<<"channel up->"<<devicestate<<endl;   
    }
    virtual void buttonseven()
    {
      devicestate--;
      cout<<"channel down->"<<devicestate<<endl;   
    }
};


class dvd : public entertainmentdevice{
public :
    dvd(int newdevicestate,int newmaxsetting)
    {
        devicestate=newdevicestate;
        maxsetting=newmaxsetting;       
    }
   
};

class remote{
public:
    entertainmentdevice *dev;
    remote(entertainmentdevice *edev)
    {
        dev=edev;   
    }

    virtual void buttonfive(){
        dev->buttonfive();
    }
   virtual void buttonseven(){
       dev->buttonseven();
    }
   virtual void buttonnine()=0;
};


class tvremote:public remote{
    public :
    tvremote(entertainmentdevice *edev): remote(edev){}

    void buttonnine(){
        cout<<"Tv Muted"<<endl;
   
    }
};


class dvdremote:public remote{
    public :
    dvdremote(entertainmentdevice *edev): remote(edev){}

    void buttonnine(){
        cout<<"Run away DVD goind to explode"<<endl;   
    }
};



int main(){
    remote *r1=new tvremote(new tv(1,200));
    remote *r2=new dvdremote(new dvd(100,150));
    r1->buttonfive();
    r1->buttonseven();
    r1->buttonnine();
    cout<<"*********DVD*********"<<endl;
    r2->buttonfive();
    r2->buttonseven();
    r2->buttonnine();
}