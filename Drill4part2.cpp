#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>



using namespace std;



class Person{
	public:
		Person (){}
		//Person(string n,int a) : n{n},a{a}{
		Person(string f,string l,int a) : f{f},l{l},a{a}{
		if (a <= 0 || a > 150){
		 	throw runtime_error("invalide age");
		}
		
		string n = f + l;
		
		for(char c : n){
		 	switch(c){
		 	 case ':':
		 	 case '%':
		 	 case '#':
		 	 case '(':
		 	 case '=':
		 	 case '$':

		 	 throw runtime_error("invalid name");
		 	 	break;
		 	 default:
		 	  	break;		 	
		 	}
		}
		};
		string first() const {return f;}
		string last() const {return l;}
		//string name() const {return n;}
		int age() const{return a;}
		
		
		
	private:
		//string n;
		string f;  
		string l;
		int a;

};

ostream& operator<<(ostream& os,const Person& p){
		return os<< p.first() <<" "<< p.last() <<" "<<p.age();
}

istream& operator<<(istream& is, Person& p){
		//string n;
		string f;
		string l;
		int a;
		
		//is>>n>>a;
		is>>f>>l>>a;
		p=Person(f,l,a);
		return is;
}




int main(){
	//Person p;
	//p.age=63;
	//p.name="Goofy";
	// p = Person{"goofy","a",63};
 	
 	//cout<<p.name<<" "<<p.age<<endl;
 	//cout<<p<<endl;
 	
 	
 	vector<Person> vec;
 	
 	for(Person p; cin <<  p;){
 		if(p.first()=="end"){
			 cout<< "vége" <<'\n'; 
			 break;
			 }
 		vec.push_back(p);
 	}

 	for(Person p: vec)
 		cout <<p<< endl;
 	
 	

}