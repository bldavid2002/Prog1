#include <string>
#include <map>
#include <iostream>
#include <stdexcept>
#include <numeric>



template<typename K, typename V>
void print (const std::map< K,V>& m){
	//for(auto& 1 : m){
	for(std::pair<K,V> i : m){
		std::cout<< i.first <<" "<<i.second<<std::endl;
	}
	
	
}
void read_map(std::map<std::string, int>& m){
	std::string s;
	int i=0;
	while(m.size()<10){
		std::cin >> s >> i;
		//skulcs helyén i lesz
		//ha felülszeretnénk irni akkor az első
		m[s] = i;
		//m.insert(std::make:pair(s ,i));
	}	
	
} 

template<typename T, typename T2>
void copySwapMapElements(const std::map<T, T2>& m1, std::map<T2, T>& m2)
{
	for (const auto& p : m1)
		m2.insert({ p.second, p.first });
};





int main(){
try{
	std::map<std::string,int>msi;
	msi["a"]=1;
	msi["b"]=2;
	msi["ab"]=7;
	msi["efgh"]=98;
	msi["qv"]=76;
	msi["efh"]=61;
	msi["efh"]=60;
	msi["xc"]=23;
	msi["qwertz"]=11;
	msi["ax"]=1;
	
	std::cout<<"MSI map: "<<std::endl;
	print(msi);


	msi.erase("a");
	std::cout<<std::endl<<"EGy eleme törlése után: "<<std::endl;
	print(msi);
	
	msi.erase(msi.begin(),msi.end());
	std::cout<<std::endl<<"teljes törlése után: "<<std::endl;
	print(msi);

	
	std::cout<<std::endl<<"Adj meg 10 kulcs párost: "<<std::endl;
	read_map(msi);
	std::cout<<std::endl<<"Be-olvasás után: "<<std::endl;
	print(msi);
	
	
	
	//lehet használni az accumulatet is
	int total2=0;
	for(std::pair<std::string,int> i: msi){
	total2 += i.second;
	 
	}
	std::cout<<std::endl<<"összeg "<<total2<<std::endl;
	
	//kép
	std::map<int,std::string>mis;
	std::cout <<"mis map: "<<std::endl;
	copySwapMapElements(msi,mis);
	print (mis);
	
	
}catch(std::exception& e){
	std::cerr << "exception "<< e.what() <<'\n';
	return 1;
}catch(...){
	std::cerr <<"error\n";
	return 2;
}
}