// The Facade Design Pattern decouples or separates the client 
// from all of the sub components

// The Facades aim is to simplify interfaces so you don't have 
// to worry about what is going on under the hood
//http://www.newthinktank.com/2012/09/facade-design-pattern-tutorial/


//Intent

//Provide a unified interface to a set of interfaces in a subsystem. Facade defines
//a higher-level interface that makes the subsystem easier to use.

//Motivation

//Structuring a system into subsystems helps reduce complexity. A common design
//goal is to minimize the communication and dependencies between subsystems. One
//way to achieve this goal is to introduce a facade object that provides a single,
//simplified interface to the more general facilities of a subsystem.
//



#include<iostream>
using namespace std;

class WelcomeToBank{		
public:
	WelcomeToBank() {			
	cout<<"Welcome to ABC Bank"<<endl;
	cout<<"We are happy to give you your money if we can find it\n"<<endl;					
	}		
};
class AccountNumberCheck{

int accountNumber;

public :
	AccountNumberCheck(){accountNumber = 12345678;}
	int getAccountNumber() { return accountNumber; }
     bool accountActive(int acctNumToCheck){	
	if(acctNumToCheck == getAccountNumber()) {		
		return true;		
	} else {		
		return false;		
	}
}
};

class SecurityCodeCheck {	
    int securityCode ;	
public:
	SecurityCodeCheck(){securityCode = 1234;}
	int getSecurityCode() { return securityCode; }	
 bool isCodeCorrect(int secCodeToCheck){		
		if(secCodeToCheck == getSecurityCode()) {			
			return true;			
		} else {			
			return false;			
		}		
	}	
};

class FundsCheck {	
	double cashInAccount;	
public:
FundsCheck()
	{
		cashInAccount = 1000.00;
		cout<<"Intial Balance is "<<cashInAccount<<endl;
}
	double getCashInAccount() { return cashInAccount; }	
	void decreaseCashInAccount(double cashWithdrawn) { cashInAccount -= cashWithdrawn; }	
	void increaseCashInAccount(double cashDeposited) { cashInAccount += cashDeposited; }	
	bool haveEnoughMoney(double cashToWithdrawal) {		
		if(cashToWithdrawal > getCashInAccount()) {			
	cout<<"Error: You don't have enough money"<<endl;
	cout<<"Current Balance: " << getCashInAccount()<<endl;			
			return false;			
		} else {
			decreaseCashInAccount(cashToWithdrawal);			
			cout<<"Withdrawal Complete: Current Balance is "<< getCashInAccount()<<endl;			
			return true;			
		}		
	}
	
	 void makeDeposit(double cashToDeposit) {
		
		increaseCashInAccount(cashToDeposit);
		
		cout<<"Deposit Complete: Current Balance is "<< getCashInAccount()<<endl;
		
	}
	
};




 class BankAccountFacade {
	
	 int accountNumber;
	 int securityCode;
	
	AccountNumberCheck acctChecker;
	SecurityCodeCheck codeChecker;
	WelcomeToBank bankWelcome;
	FundsCheck fundChecker;	
	
	
public:
	BankAccountFacade(int newAcctNum, int newSecCode){
		
		accountNumber = newAcctNum;
		securityCode = newSecCode;		
	   	}
	
	 int getAccountNumber() { return accountNumber; }
	
	 int getSecurityCode() { return securityCode; }
	
	
	 void withdrawCash(double cashToGet){
		
		if(acctChecker.accountActive(getAccountNumber()) &&
				codeChecker.isCodeCorrect(getSecurityCode()) &&
				fundChecker.haveEnoughMoney(cashToGet)) {
					
					cout<<"Transaction Complete\n"<<endl;
					
				} else {
					
					cout<<"Transaction Failed\n"<<endl;
					
				}
		
	}
	
	
	 void depositCash(double cashToDeposit){
		
		if(acctChecker.accountActive(getAccountNumber()) &&
				codeChecker.isCodeCorrect(getSecurityCode())) {
			
					fundChecker.makeDeposit(cashToDeposit);
					
					cout<<"Transaction Complete\n"<<endl;
					
				} else {
					
					cout<<"Transaction Failed\n"<<endl;
					
				}
		
	}
	
};


int main(){
        BankAccountFacade *accessingBank = new BankAccountFacade(12345678, 1234);		
		accessingBank->withdrawCash(50.00)	;				
		accessingBank->withdrawCash(900.00);
		accessingBank->depositCash(200.00);


}