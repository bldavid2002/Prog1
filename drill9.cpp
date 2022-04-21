#include<numeric> 
#include<iostream>
#include<cmath>
#include<cerrno>
#include "Matrix.h"
#include "MatrixIO.h"
#include<complex>
using namespace std;
using namespace Numeric_lib;



int main(){
try{
	cout<<"siz-of:\n";
	cout<<"char\t" <<sizeof(char)<<"\n";
	cout<<"short\t" <<sizeof(short)<<"\n";
	cout<<"int\t" <<sizeof(int)<<"\n";
	cout<<"long\t" <<sizeof(long)<<"\n";
	cout<<"float\t" <<sizeof(float)<<"\n";
	cout<<"double\t" <<sizeof(double)<<"\n";
	cout<<"int*\t" <<sizeof(int*)<<"\n";
	cout<<"double*\t" <<sizeof(double*)<<"\n";
	

	cout << "Matrix sizes: \n";
	Matrix<int> a(10);
	Matrix<int> b(100);
	Matrix<double> c(10);
	Matrix<int, 2> d(10,10);
	Matrix<int, 3> e(10,10,10);
	
	cout<<"10 int,10 elem\t\t" <<sizeof(a)<<"\n";
	cout<<"10 int,100 elem\t\t" <<sizeof(b)<<"\n";
	cout<<"10 double,10 elem\t\t" <<sizeof(c)<<"\n";
	cout<<"2D,10x10elem\t\t" <<sizeof(d)<<"\n";
	cout<<"3D,10x10x10 elem\t\t" <<sizeof(e)<<"\n";
	
	cout<<endl;
	cout<<"Number of elements:\n";
	cout<<"a :\t"<<a.size()<<"\n";
	cout<<"b :\t"<<b.size()<<"\n";
	cout<<"c :\t"<<c.size()<<"\n";
	cout<<"d :\t"<<d.size()<<"\n";
	cout<<"e :\t"<<e.size()<<"\n";
		
	int i;
	cout<<"\nEnter ints \n";
	while(cin>>i){
		errno=0;
		double d= sqrt(i);
		if(errno == EDOM)
			cout <<"no square root\n";
			
		else {
			cout<<"sqrt("<<i<<") ="<<d<<'\n';
			break;
		}	
	
	}
		
		
	cin.clear();//hibákat töröl
	cin.ignore();//felesleges araktereket
	cout<<"\nEnter 10 float ot: \n";
	Matrix<double> m(10);
	double d2;
	for(int i=0;i<m.size();++i){
	cin>>d2;
	if(!cin)
		throw runtime_error("error while reading from cin");
	else
		m[i]=d2;
	}	
	cout << "Matrix:\n"<<m<<'\n';
	cout<<endl;
    
	//szórzótábla mátrixban:
	cout<<"enter n :\n";
	int n;
	cin>>n;
	cout<<"enter m :\n";
	int m2;
	cin>>m2;
	Matrix<int,2> n2(n,m2);
	
	 for (int i = 0; i<n2.dim1(); ++i) {
        for (int j = 0; j<n2.dim2(); ++j) {
            n2(i,j) = (i+1)*(j+1);
           
        }
        cout << '\n';
    }
	cout<<n2<<'\n';	
		
	//7 es
	
	Matrix<complex<double>> m4(10);
	cout<<"\nEnter 10 complex numbers(Re,Im): \n";
	complex<double>comp;
	for(int i=0;i<10;++i){
		cin >> comp;
		if(!cin)throw runtime_error("Problem reading complex number!");
		m4[i]=comp;
	
	}
	complex<double> sum;
	for(Index i=0; i<m4.size();++i){
		sum+=m4[i];
		
	
	}
	cout<<"Sum: "<<sum<<'\n';
		
	//8
    cout<<endl;
	Matrix<int,2> M5(2,3);
	int m5;
	cout<<"Write 6 numbers for the matrix :\n";
	for(int i=0;i<M5.dim1();++i){
		for(int j=0;j<M5.dim2();++j){
				cin>>m5;
				M5(i,j)=m5;
		}

	}
	cout<<M5<<'\n';	
		

}catch(std::exception& e){
	std::cerr << "exception "<< e.what() <<'\n';
	return 1;
}catch(...){
	std::cerr <<"error-trycatch\n";
	return 2;
}
}






