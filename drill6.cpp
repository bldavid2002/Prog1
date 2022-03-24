#include <iostream>
#include <string>
#include <vector>

using namespace std;

template<typename T>
struct S{
	S (T vv=0) : val{vv}{}
	T& get();
	const T& get() const;
	//setter
	void set(T new_t){val = new_t;}
	//tultelherés
	void operator=(const T& s);
	private:
 	T val;
};



//getter

template<typename T>
		T& S<T>::get() {
		return val;
}
//constatns 

template<typename T>
	const	T& S<T>::get() const{
		return val;
}
//tultelrhelés
template<typename T>
void S<T>::operator=(const T& s){
	val=s;
}	


template<typename T>
void read_val(T& v){
	cin >> v;
}

template<typename T>
std::ostream& operator<<(ostream& os,vector<T&> v){
	os<<"{";
	for(int i=0;i<v.size();++i){
		os << v[i]<<(i<v.size()-1 ? ", ": " ");
		 
	}
	os<<"}\n";
	return os;
//operátor tulterhelés hol fut le cout-ot használd hol futnak a dolgok

}

//bekérés
template<typename T>
istream& operator>>(istream is, vector<T>& v)
{	
	char ch = 0;
	is >> ch;
	if(ch != '{'){
		is.unget();
		return is;
	
	}
	for(T val; is >> val;){
		v.push_back(val);
		is >>ch;
		if(ch != '.') break;
	
	}
	return is;

}

//
int main(){


	S<int> s;
	S<int> si{37};
	S<char> c{'c'};
	S<double> d{3.2};
	S<std::string> ss{"Hello"};
	//S-tipusu vector ami inteket tartalmaz
	S<std::vector<int>> svi{std::vector<int>{1,2,3,4,5,6,7,8,9,10}};
	
	
	cout<<"S-int : "<< s.get()<<endl;
	cout<<"S-int : "<< si.get()<<endl;
	cout<<"S-char : "<< c.get()<<endl;
	cout<<"S-double : "<< d.get()<<endl;
	cout<<"S-string : "<< ss.get()<<endl;
	//cout<<"S-vector : "<< svi.val<<endl;
	
	for(auto& a : svi.get()){
		cout<<a<<";";
	}
	cout <<endl;
	
	c.set('s');
	cout<<"S-char : "<<c.get()<<endl;
	//lehet egyenlőség jelet használni
	d=42.1;
/*
	cout<<"S-double : "<< d.get()<<endl;
	 int ii;
	 read_val(ii);
	 S<int>i2{ii};
	 
	 double ddd;
	 read_val(ddd);
	 S<double>d2{ddd};
	 
	 string str;
	 read_val(str);
	 S<string>s2{str};
	 
	cout<<"S-string : "<< s2.get()<<endl;
	cout<<"S-int : "<< i2.get()<<endl;
	cout<<"S-double : "<< d2.get()<<endl;
*/
	cout << "S<vector<int>>: (format: { val, val, val}) ";
    vector<int> vec;
    read_val(vec);
    S<vector<int>> svi2 {vec};
	
//	cout << "S<vector<int>> svi2: " << svi2.get()<<endl;

}