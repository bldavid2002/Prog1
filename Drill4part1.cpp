#include "Window.h"
#include "Graph.h"
#include "Simple_window.h"

#include <string>
#include <iostream>

using namespace Graph_lib;


double one(double x){return 1;}
double slope (double x){return x/2;}
double square(double x){return x* x;}
double sloping_cos(double x){return cos(x) + slope(x);}



int main(){
try{
    Point t1 {100, 100};
    Simple_window win {t1,  600, 400, "My Window"};
	win.wait_for_button();

    Axis x {Axis::x,Point{100, 300},400,20, " 1 == 20 pixels" };
    Axis y {Axis::y,Point{300, 500},400,20, " 1 == 20 pixels" };
    x.set_color(Color::red);
    y.set_color(Color::red);
    win.attach(x);
    win.attach(y);


    constexpr int r_min=-10;
    constexpr int r_max=11;
    constexpr int num_point=400;
    constexpr int x_scale=20;
    constexpr int y_scale=20;
    const Point orig {300,300};

    Function F1 {one,r_min,r_max,orig,num_point,x_scale,y_scale};
    Function F2 {slope,r_min,r_max,orig,num_point,x_scale,y_scale};
    Function F3 {square,r_min,r_max,orig,num_point,x_scale,y_scale};
    Function F4 {cos,r_min,r_max,orig,num_point,x_scale,y_scale};
    F4.set_color(Color::blue);        
    Function F5 {[](double x){return cos(x)+slope(x);},r_min,r_max,orig,num_point,x_scale,y_scale};

    win.attach(F1);
    win.attach(F2);
    win.attach(F3);
    win.attach(F4);
    win.attach(F5);
    win.wait_for_button();

}catch(exception& e){
		cerr << "exception "<< e.what() <<'\n';
		return 1;

}catch(...){
		cerr <<"error\n";
		return 2;
}

}



