#include <fstream>
#include <iostream>
#include <stdexcept>
#include <numeric>
#include <vector>
#include <algorithm>
#include "std_lib_facilities.h"

struct item{

    string name;
    double value;
    int id;


    item() : name(),value(),id() {}
    item(string pname,double pvalue,int pid) :name(pname),value(pvalue),id(pid){}

    friend istream& operator>>(istream& input, item& item){
		string line;
		getline(input, line);
		if(!line.empty()){
			size_t comma1 = line.find(',');
			item.name = line.substr(0,comma1);

			size_t comma2 = line.find(',', comma1+1);
			size_t diff = comma2 - (comma1+0);
			item.value = stod(line.substr(comma1 +1, diff));

			size_t endBracket = line.find('}', comma2);
			diff = endBracket - (comma2 + 2);
			item.id = stoi(line.substr(comma2 + 1, diff));
		}

		return input;
	}

    friend ostream& operator<<(ostream& output,item& item){
		output <<item.name<< "," <<item.value<< "," <<item.id<<std::endl;
		return output;
	}


};

bool abc_order(char a, char b){
	return tolower(a)<tolower(b);
}


struct sort_name{
	bool operator()(const item& pitem1, const item& pitem2) const{
		return std::lexicographical_compare(pitem1.name.begin(),pitem1.name.end(),pitem2.name.begin(),pitem2.name.end(),abc_order);
	}
};

struct sort_id{
	bool operator()(const item& pitem1,const item& pitem2) const{
		return pitem1.id<pitem2.id;
	}
};

struct sort_value{
	
	bool operator()(const item& pitem1,const item& pitem2) const{
		return pitem1.value<pitem2.value;
	}

};


struct remove_name{
	remove_name(string pname) : s(pname) {}
	bool operator()(const item& pitem1){
		return pitem1.name == s;
	}
	string s;
};



struct remove_id
{
	remove_id(int pid) : i(pid) {}
	bool operator()(const item& pitem1){
		return pitem1.id == i;
	}
	int i;
};




int main(){
try{
    string fromfile="items.txt";
	string tofile="newitems.txt";

	ifstream is{fromfile};
	ofstream os{tofile};

	istream_iterator<item>ii{is};
	istream_iterator<item>eos;
	ostream_iterator<item>oo{os,"\n"};

	vector<item>v{ii,eos};

	
	cout <<"Insert 2 new items:"<< endl;
	v.insert(v.begin(),item{"horse shoe",12.34,102});
	v.insert(v.begin(),item{"Canon S400",499.95,9988});
	for (item i:v)
		cout<<i<<endl;

	
	
	cout<<"sorting by name:"<< endl;
	sort(v.begin(),v.end(),sort_name());
	for (item i:v)
		cout<<i<<endl;

	
	
	cout<<"Sorting by id:"<<endl;
	sort(v.begin(),v.end(),sort_id());
	for (item i:v)
		cout<<i<<endl;

	
	cout<<"Sorting by value(decreasing):"<< endl;
	sort(v.begin(),v.end(),sort_value());
	for (item i:v)
		cout<<i<<endl;

	
	cout<<"Removing 2 items by name:"<<endl;
	auto it=std::find_if(v.begin(),v.end(),remove_name("drill"));
	v.erase(it);
	it=std::find_if(v.begin(),v.end(),remove_name("nail"));
	v.erase(it);
	for (item i:v)
		cout<<i<<endl;

	
	cout << "Removing 2 items by id:" << endl;
	it=std::find_if(v.begin(),v.end(),remove_id(99));	
	v.erase(it);
	it=std::find_if(v.begin(),v.end(),remove_id(33));	
	v.erase(it);
	for (item i:v)
		cout<<i<<endl;











}catch(std::exception& e){
std::cerr << "exception "<< e.what() <<'\n';
return 1;
}catch(...){
std::cerr <<"error\n";
return 2;
}
}