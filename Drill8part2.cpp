#include <fstream>
#include <iostream>
#include <stdexcept>
#include <numeric>
#include <vector>
#include <algorithm>
using namespace std;



template<typename C>
void print(const C& c,char sep='\n'){
 std::cout<< "Container elements:\n";
 
 	for(const auto elem: c){
 		std::cout <<elem<<sep;
 	
 	}
 	
 	std::cout<<std::endl;

};

template<typename C>
void sum(const C& c){
	std::cout<<"vd-Összege: "<<std::endl;
	int s=0;
	for(const auto elem: c){
 		s=s+elem;	
 	
 	}
 	std::cout<<s<<std::endl;
};
/*
class Less_than {
	double v;
	public:
		Less_than(double vv) : v{vv}{}
		bool operator()(const double val){return val < v;}
		};
		*/

int main(){
try{

	const std::string iname {"numbers.txt"};
	std::ifstream ifs {iname};
	if(!ifs) throw std::runtime_error("error "+iname);
	
	
	std::vector<double> vd;
	for(double d; ifs >> d;){
		vd.push_back(d);
		
	}
	
	print(vd);
	
	
	std::vector<int> vi(vd.size());
	/*for(auto& d :vd){
	
		vi.push_back(d);
	}
	*/
	std::copy(vd.begin(),vd.end(),vi.begin());
	print(vi);
	
	//egymásmellet
	for(int i=0;i<vd.size();i++){
	 std::cout << vd[i] <<'\t'<< vi[i]<<std::endl;	}

	double	sumvd=0;
	double sumvi=0;
	 for(int i=0;i<vd.size();i++){
		 sumvd= sumvd+vd[i];
	 }
	 std::cout <<"Összeg-vd: "<<std::endl;
	 std::cout <<sumvd<<std::endl;
	 sum(vd);

	 for(int i=0;i<vi.size();i++){
		 sumvi= sumvi+vi[i];
	 }
	 std::cout <<"Összeg-vi: "<<std::endl;
	 std::cout <<sumvi<<std::endl;
	 
	 double diff=sumvd-sumvi;
	 std::cout <<"Diff of vd nad vi : "<<diff<<std::endl;
	 std::cout <<std::endl;


	
	std::reverse(vd.begin(),vd.end());
	print(vd);
	
	double vd_mean = sumvd/vd.size();
	std::cout<<"mean values of vd:"<<vd_mean<<std::endl;
	
	
	
	std::vector<double> vd2 ;
	//double it=copy_if(vd.begin(),vd.end(),vd2.begin(),vd2.end(),Less_than(vd_mean)); 
	int n=0;
	for(int i=0;i<vd.size();i++){
			if (vd[i]<vd_mean){
				i++;
				vd2.push_back(vd[i]);
			}
	}
	print(vd2);

	std::cout<<"vd -sortolva:"<<std::endl;
	std::sort(vd.begin(),vd.end());
	print(vd);
	
	

}catch(std::exception& e){
	std::cerr << "exception "<< e.what() <<'\n';
	return 1;
}catch(...){
	std::cerr <<"error\n";
	return 2;
}
}