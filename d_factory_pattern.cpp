
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <iostream>
using namespace std;

class invoice {
public:
	virtual void print()=0;

};

class invoicewithheader:public invoice {
public:
	void print()
	{
     cout<<"\nInvoicewithheader";
	}

};

class invoicewithoutheader:public invoice {
public:
	void print()
	{
     cout<<"\nInvoicewithoutheader";
	}

};
class invoicefactory{
public:
 invoice* getinvoicetype(int in)
 {
  if (in=1)
	  return new invoicewithheader();
  if (in=2)

	  return  new invoicewithoutheader(); 
  else 
	  return NULL;
 }

};





int main()
{
invoicefactory *factory= new invoicefactory();
invoice *obj=NULL;

obj=factory->getinvoicetype(1);

obj->print();


}