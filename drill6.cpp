#include "std_lib_facilities.h"

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

//bekérés

template<typename T>
istream& operator>>(istream& is, vector<T>& v)
{	
	char ch = 0;
	is >> ch;
	if(ch != '{'){
		is.unget();
		return is;
	
	}
	for(T val; is >> val;){
		v.push_back(val);
		cin >>ch;
		if(ch != ',') break;
	
	}
	return is;
	

}







template<typename T>
void read__val(T& k){
	cin >> k;
}

template<class T> ostream& operator<<(ostream& os, const vector<T>& v){
	os<<"{";
	for(int i=0;i<v.size();++i){
		os << v[i]<<(i<v.size()-1 ? ", ": " ");
		 
	}
	os<<"}\n";
	return os;
//operátor tulterhelés hol fut le cout-ot használd hol futnak a dolgok

}




template<typename T> istream& operator>>(istream& is, S<T>& ss)
{
    T v;
    cin >> v;
    if (!is) return is;
    ss = v;
    return is;
}









int main(){

try{
	S<int> s;
	S<int> si{37};
	S<char> c{'c'};
	S<double> d{3.2};
	S<string> ss{"Hello"};
	//S-tipusu vector ami inteket tartalmaz
	vector<int> vi;
	vi.push_back(1);
	vi.push_back(2);
	vi.push_back(3);
	S<vector<int>> svi(vi);
	
	
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
	
	vi[1]=12;
	svi.set(vi);
	for(int i=0;i<svi.get().size();++i){
		cout<< svi.get()[i] <<";";
	}

	cout<<"\nS-double : "<< d.get()<<endl;
	 int ii;
	 read__val(ii);
	 S<int>i2{ii};
	 
	 double ddd;
	 read__val(ddd);
	 S<double>d2{ddd};
	 
	 string str;
	 read__val(str);
	 S<string>s2{str};
	 
	cout<<"S-string : "<< s2.get()<<endl;
	cout<<"S-int : "<< i2.get()<<endl;
	cout<<"S-double : "<< d2.get()<<endl;

	cout << "S<vector<int>>: (format: { val, val, val}) \n";
   
   

	
    
	read__val(svi);
	cout << "S<vector<int>> svi2: " << svi.get()<<endl;
	
}catch (exception& e) {
    cerr << "Exception: " << e.what() << "\n";
}
catch (...) {
    cerr << "Exception\n";
}
}