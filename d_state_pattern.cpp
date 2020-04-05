#include <iostream>
using namespace std;



class ATMState{
public:
virtual void insertcard()=0;
virtual void insertpin(int)=0;
virtual void withdraw(int)=0;
};

class ATMMachine{
    ATMState *m_HasNoCash;
    ATMState *m_NoCard;
    ATMState *m_HasCard;
    ATMState *m_HasPin;
    int availabeCash;
    bool ValidPin;

    ATMState *m_atmstate;       
public:

    ATMMachine();


    void setATMstate(ATMState* newState)
    {
        m_atmstate=newState;
    }

    void insertcard(){               
        m_atmstate->insertcard();                   
    }
    void insertpin(int pin){               
        m_atmstate->insertpin(pin);           
    }

    void withdraw(int cash){
        m_atmstate->withdraw(cash);           

    }

    void ejectcard(){
        (*this).setATMstate(this->getHasNoCardState());
    }

   
    ATMState* getHasNoCashState(){ return m_HasNoCash;}
    ATMState* getHasNoCardState(){ return m_NoCard;}
    ATMState* getHasCardState(){ return m_HasCard;}
    ATMState* getHasPinState(){ return m_HasPin;}
   
   
    bool getPin(){return ValidPin; }

    void setPin(bool n){ ValidPin=n; }

    void setbalance(int b)    {    availabeCash=b;    }

    int getavailabeCash(){return availabeCash;}

};





class HasPin:public ATMState{
    ATMMachine *nATMMachine;
public:
    HasPin(ATMMachine *newATMMachine)
    {
        nATMMachine=newATMMachine;
    }

    void insertcard(){
        cout<<"Card is already present in Machine"<<endl;
    }

    void insertpin(int pin){
        cout<<"Card already has a Valid Pin"<<endl;

    }

    void withdraw(int withdrawal){
        int t= nATMMachine->getavailabeCash()- withdrawal;
        nATMMachine->setbalance(t);
        cout<<"Your have withdrawed "<<withdrawal<<endl;
        cout<<"Availabe Balance "<<nATMMachine->getavailabeCash()<<endl;

       
    }
};


class HasCard:public ATMState{
    public:
    ATMMachine *nATMMachine;

    HasCard(ATMMachine *newATMMachine)
    {
        nATMMachine=newATMMachine;
    }

    void insertcard(){       
    }


    void insertpin(int pin){
        if(pin==123)
        {
        cout<<"Welcome to InterNational Bank"<<endl;   
        nATMMachine->setATMstate(nATMMachine->getHasPinState());
        }          
        else
        {
            nATMMachine->setATMstate(nATMMachine->getHasCardState());
            cout<<"Invalid Pin,Insert Card Again";
        }
    

    void withdraw(int m){
       
    }
};






class HasNoCash:public ATMState{
    ATMMachine *nATMMachine;
public:
    HasNoCash(ATMMachine *newATMMachine)
    {
        nATMMachine = newATMMachine;
    }
    void insertcard(){

        nATMMachine->setATMstate(nATMMachine->getHasNoCardState());
          cout<<"Card Inserted"<<endl;
    }
    void insertpin(int pin){
    }
    void withdraw(int a){
    }

};


class NoCard:public ATMState
{
    ATMMachine *nATMMachine;
public:
    NoCard(ATMMachine *newATMMachine)
    {
        nATMMachine = newATMMachine;           
    }

    void insertcard()
    {
        nATMMachine->setATMstate(nATMMachine->getHasCardState());       
    }

    void insertpin(int pin){}
    void withdraw(int a){}
};



ATMMachine::ATMMachine(){
        m_HasNoCash= new HasNoCash(this);   
        m_NoCard=new NoCard(this);
        m_HasCard= new HasCard(this);
        m_HasPin=new HasPin(this);


        availabeCash=1000;
        ValidPin=false;

        m_atmstate=m_NoCard;
        if(availabeCash<0)
          m_atmstate=m_HasNoCash;
    }
   



int main(){
    ATMMachine *a=new ATMMachine;
   
    a->insertcard();
    a->insertpin(123);
    a->withdraw(100);
    a->ejectcard();
}