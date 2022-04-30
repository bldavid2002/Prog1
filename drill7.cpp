#include <iostream>
#include <string>
#include <vector>
#include <array>
#include <list>
//#include <stdexception>

#include "std_lib_facilities.h"

template<typename C>

void print(const C& c){
	for(auto& i : c){
		std::cout<<i<<' ';
	
	}
	std::cout<<std::endl;	
};

template<typename C>
void inc(C& c,int n){
	for(auto& i : c){
		i +=n;
	
	}
	std::cout<<std::endl;	
};


template<typename Iter1, typename Iter2>
// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 oraicopy(Iter1 f1, Iter1 e1, Iter2 f2){
	for(Iter1 p = f1; p != e1; ++p){
		*f2=*p;
		f2++;
	}

	return f2;
}



int main(){
try{

constexpr int size = 10; 

int arr[size];
for(int i = 0; i<size;++i) arr[i] =i;

	std::array<int,size> ai;
	std::copy(arr,arr+size,ai.begin());

	vector<int> vi(size);
	std::copy(arr,arr+size,vi.begin());

	std::list<int> li(size);
	std::copy(arr,arr+size,li.begin());
	
	std::array<int,size> ai2=ai;
	vector<int> vi2=vi;
	std::list<int> li2=li;




	print(ai2);
	print(li2);
	print(vi2);
	
	
	inc(ai2,2);
	inc(li2,5);
	inc(vi2,7);
	
	print(ai2);
	print(li2);
	print(vi2);
	
	oraicopy(ai2.begin(), ai2.end(), vi2.begin());
	oraicopy(li2.begin(), li2.end(), ai2.begin());
	
	print(ai2);
	print(li2);
	print(vi2);
	
	vector<int>::iterator vit;
	vit = std::find(vi2.begin(),vi2.end(),3);
	if(vit==vi2.end()){
		std::cout <<"Found at: "<<std::distance(vi2.begin(),vit)<<std::endl;
		}
	else{
	std::cout<<"not found"<<std::endl;
	}	


}catch(exception& e){
	cerr << "exception "<< e.what() <<'\n';
	return 1;
	}catch(...){
	cerr <<"error\n";
}
}