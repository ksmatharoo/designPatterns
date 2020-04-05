#include<iostream>
using namespace std;

class item;

class visiter{
public:
	virtual int visit(item *ptr) = 0;
};;

class item{	
public:
	virtual int price() = 0;
	virtual int tax(visiter* _v) = 0;
};

class food:public item{	
public:
	virtual int price() { return 100;};
	virtual int tax(visiter* _v) { return _v->visit(this);  };
};

class liquor:public item{	
public:
	virtual int price() { return 500;};
	virtual int tax(visiter* _v) { return _v->visit(this);  };
};


class taxvisiter:public visiter
{
public:
	int visit(item *ptr)
	{
		food  *f = dynamic_cast<food*>(ptr);
		if(f)
			return (int)ptr->price() * (.05);
		liquor  *l = dynamic_cast<liquor*>(ptr);
		if(l)
			return (int)ptr->price() * (.10);

		return 0;
	}


	
};






int main(){

	visiter *v = new taxvisiter();

	item *i = new food();
	item *l = new liquor();

	cout<< i->tax(v)<<endl;
	cout<< l->tax(v)<<endl;

	return 0;




}