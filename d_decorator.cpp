#include<iostream>
#include<string>
using namespace std;

//Intent
//Attach additional responsibilities to an object dynamically. Decorators provide
//a flexible alternative to subclassing for extending functionality.
//Also Known As
//Wrapper

//Motivation
//Sometimes we want to add responsibilities to individual objects, not to an entire
//class. A graphical user interface toolkit, for example, should let you add
//properties like borders or behaviors like scrolling to any user interface
//component.

//One way to add responsibilities is with inheritance. Inheriting a border from
//another class puts a border around every subclass instance. This is inflexible,
//however, because the choice of border is made statically. A client can't control
//how and when to decorate the component with a border.
//	A more flexible approach is to enclose the component in another object that adds
//the border. The enclosing object is called a decorator. The decorator conforms
//to the interface of the component it decorates so that its presence is transparent
//to the component's clients. The decorator forwards requests to the component and
//may perform additional actions (such as drawing a border) before or after
//forwarding. Transparency lets you nest decorators recursively, thereby allowing
//an unlimited number of added responsibilities.

// visit the video for more understanding 
//  http://www.youtube.com/watch?v=j40kRwSm4VE 

class pizza{
public:
virtual string description()=0;
virtual int getcost()=0;
};


class plainpizza:public pizza{
public:
    string description()
    { 
    return "PlainBase";
    }
    int getcost(){
    return 10;
    }
};

class topping:public pizza{
protected:
    pizza *temp;
public:
topping(pizza *t)
{
    temp=t;
}

    string description()
    { 
        return temp->description();
    }
    int getcost(){
        return temp->getcost();
    }
};

class peppypaneer:public topping{
    public:
    typedef topping base;

    peppypaneer(pizza *p):base(p){}

    string description()
    { 
        return base::description()+ "+paneer";
    }
    int getcost(){
        return base::getcost()+5;
    }
};



class tomatosauce:public topping{
    typedef topping base;
public:
    tomatosauce(pizza *p):base(p){}
    string description()
    { 
        return base::description()+ "+tomato";
    }
    int getcost(){
        return base::getcost()+2;
    }
};





   
int main(){

pizza *x=new tomatosauce(new peppypaneer(new plainpizza));

cout<<x->description()<<endl;
cout<<x->getcost()<<endl;


}