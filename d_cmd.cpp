
// cmd pattern decouples the commands and the underlying object
// you just need to pass the underlying concrete object on which you want to call the command
// to the command concrete object
// 

#include<iostream>
using namespace std;

//#define TV_EXAMPLE
#define STOCK_ORDER
#ifdef TV_EXAMPLE
class cmd{
public:
virtual void execute()=0;
};

class device{
public:
	virtual void on() = 0;
	virtual void off() = 0;

	//virtual void volincrease() = 0;
	//virtual void voldcrease() = 0;
};


class tv:public device{

public:
	void on()
	{
	cout<<"TV on";
	}
	void off()
	{
	cout<<"TV off";
	}
};


class on:public cmd{
public:
	on(device *_d):d(_d){}
	device *d;

 void execute()
 {
	 d->on();
 }
};


class off:public cmd{
public:
	off(device *_d):d(_d){}
	device *d;

 void execute()
 {
	 d->off();
 }
};
#endif

#ifdef STOCK_ORDER
class cmd{
public:
	virtual void execute()=0;
};

class stockInstrument{
public:
	virtual void buy()= 0;
	virtual void sell() = 0;	
};

class equity:public stockInstrument{
public:
	void buy(){  cout<<"buy order";}
	void sell() { cout<<"sell order";}
};

class buyorder:public cmd{
public:
	buyorder(stockInstrument *_pin):pin(_pin){}
	stockInstrument *pin;

	void execute()
	{
		this->pin->buy();
	}

};


class sellorder:public cmd{
public:
	sellorder(stockInstrument *_pin):pin(_pin){}
	stockInstrument *pin;

	void execute()
	{
		this->pin->buy();
	}

};




#endif

int main()
{
#ifdef TV_EXAMPLE
	cmd *on = new on(new tv());
	tvon->execute();
#endif

#ifdef STOCK_ORDER
	cmd *buy = new buyorder(new equity);
	buy->execute();
#endif

}