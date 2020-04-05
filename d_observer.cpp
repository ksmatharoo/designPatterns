///http://sourcemaking.com/design_patterns/observer/cpp/1

#include<iostream>
#include<vector>
using namespace std;

//Intent
//Define a one-to-many dependency between objects so that when oneobject changes
//state, all its dependents are notified and updatedautomatically.
//Also Known As
//Dependents, Publish-Subscribe
//Motivation
//A common side-effect of partitioning a system into a collection ofcooperating
//classes is the need to maintain consistency betweenrelated objects. You don't
//want to achieve consistency by making theclasses tightly coupled, because that
//reduces their reusability.


//http://www.youtube.com/watch?v=wiQdrH2YpT4


class subject;
class observer;


class observer{
public:
    virtual void update(int,int,int)=0;

};

class subject
{
public:
    virtual void rregister(observer*)=0;
    virtual void unregister(observer*)=0;
    virtual void notify(void)=0;

};

class subscriber:public observer{
public:
    int m_ibm;
    int m_google;
    int m_apple;
    static int observerid;
    int obid;

public:
    subscriber(subject *p){
        p->rregister(this);       
        obid=observerid++;
    }
  	 void printprice(){
        cout<<"Observer ID "<<obid<<endl;
        cout<<"IBM "<<m_ibm<<endl;
        cout<<"Google "<<m_google<<endl;
        cout<<"Apple "<<m_apple<<endl;
		cout<<"\n";

    }
    void update(int x,int y,int z)
    {
    m_ibm=x;
    m_google=y;
    m_apple=z;
    printprice();
    }



};
int subscriber::observerid=1;

class publisher:public subject{
private:  
    vector<observer*> ob;
    int ibm;
    int apple;
    int google;
    public :
		publisher(){}
        
        void rregister(observer *newobserver){
            ob.push_back(newobserver);
       
        }
        void unregister(observer *del){
			for(unsigned int i=0;i<ob.size();i++)
			{
             if(ob[i]==del)
			 {
				 ob.erase(ob.begin()+i);
				 return;
			 }
			
			}
           // ob.erase(ob.end()-1);
        }
        void notify(void)
        {
            vector<observer*>::iterator it;
			for(it=ob.begin();it!=ob.end();it++)
            {   
                (*it)->update(ibm,apple,google);
            }
			/*for (int i = 0;i<ob.size();i++)				 
				ob[i]->update(ibm,apple,google);    */

        }
        
        void setprice(int x,int y,int z)
        {
         ibm=x;
         apple=y;
         google=z;
         notify();
         }


};

int main()
{
    publisher *p= new publisher();   
    subscriber *s1=new subscriber(p);
	subscriber *s=new subscriber(p); 
	
    p->setprice(200,800,500);	
	p->setprice(1200,1800,1500);
	p->unregister(s1);
	p->setprice(120,180,150);

	

}