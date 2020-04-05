#include<iostream>
#include<vector>
#include<string>
using namespace std;

class directorystructure{
public:
	virtual void display()=0;
	virtual void add(directorystructure*){};
};

class file :public directorystructure{
	string name;
public:
	file(string _name):name(_name){
	}
	void display(){
		cout<<"  "<<name<<endl;
	}


};


class directory: public directorystructure{
	string name;
	vector <directorystructure*> v1; 
public:
	directory(string _name):name(_name){}	
	void add(directorystructure *ds)
	{
		v1.push_back(ds);
	}
	void display(){
		cout<<"d_"<<name<<endl;
		vector <directorystructure*>::iterator it;
		it=v1.begin();
		while(it!=v1.end()){		
			(*it)->display();
			it++;		
		}
	}
};



int main(){

	directorystructure *fs=new directory("root");

	fs->add(new file("file1"));
    fs->add(new file("file2"));
	
	directorystructure *etc= new directory("etc");
	fs->add(etc);
	etc->add(new file("etcfile1"));
	etc->add(new file("etcfile2"));
	
    fs->add(new file("file3"));


	directorystructure *bin= new directory("bin");
	bin->add(new file("binfile1"));
	bin->add(new file("binfile2"));

	fs->add(bin);

    fs->display();
	cout<<"Etc directory"<<endl;
	etc->display();
	cout<<"Bin directory"<<endl;
	bin->display();



}