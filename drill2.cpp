#include "Window.h"
#include "Graph.h"
#include "Simple_window.h"

#include <string>
#include <iostream>


using namespace Graph_lib;

int main(){
try{

	Point t1 {300, 50};
	Simple_window win {t1,  1000, 800, "My Window"};
	win.wait_for_button(); 
	
	
	int x_size = win.x_max(); 
	int y_size = win.y_max();
	int x_grid = 80;
	int y_grid = 40;
	
	
	Lines grid;
	for (int i=0; i<=x_size; i+=100)
	grid.add(Point{i,0},Point{i,y_size}); 
	for (int i=0; i<=y_size; i+=100)
	grid.add(Point{0,i},Point{x_size,i});
	
	win.attach(grid);
	win.wait_for_button();
	
	Rectangle rect1 {Point{0,0},100,100};
	Rectangle rect2 {Point{100,100},100,100};
	Rectangle rect3 {Point{200,200},100,100}; 
	Rectangle rect4 {Point{300,300},100,100}; 
	Rectangle rect5 {Point{400,400},100,100}; 
	Rectangle rect6 {Point{500,500},100,100};
	Rectangle rect7 {Point{600,600},100,100};
	Rectangle rect8 {Point{700,700},100,100};
	Rectangle rect9 {Point{800,800},100,100};
	
	rect1.set_fill_color(Color::red);
	rect2.set_fill_color(Color::red);
	rect3.set_fill_color(Color::red);
	rect4.set_fill_color(Color::red);
	rect5.set_fill_color(Color::red);
	rect6.set_fill_color(Color::red);
	rect7.set_fill_color(Color::red);
	rect8.set_fill_color(Color::red);
	rect9.set_fill_color(Color::red);
	
	win.attach(rect1);
	win.attach(rect2);
	win.attach(rect3);
	win.attach(rect4);
	win.attach(rect5);
	win.attach(rect6);
	win.attach(rect7);
	win.attach(rect8);
	win.attach(rect9);
	win.wait_for_button();
	
	
	//for(int i=0;i<=8;i++){
	//Rectangle rect {Point{i*100,i*100},100,100};
	//rect.set_fill_color(Color::red);
	//win.attach(rect);
	//win.wait_for_button();
	//}
	
	Image pic {Point{600, 200}, "badge.jpg"};
	pic.set_mask(Point{200,200},200,200); 
	win.attach(pic);
	win.set_label("kép");
	win.wait_for_button();

	Image pic2 {Point{200, 600}, "badge.jpg"};
	pic2.set_mask(Point{100,200},200,200); 
	win.attach(pic2);
	win.set_label("kép2");
	win.wait_for_button();

	Image pic3 {Point{300 ,0}, "badge.jpg"};
	pic3.set_mask(Point{100,200},200,200); 
	win.attach(pic3);
	win.set_label("kép3");
	win.wait_for_button();


	int xhely=0;
	int yhely=0;

	while(true){
		Image pic4 {Point{xhely ,yhely}, "badge.jpg"};
		pic4.set_mask(Point{100,200},100,100); 
		win.attach(pic4);
		win.set_label("kép4");
		win.wait_for_button();
		//ezzel eltakarhatja a piros átlót ás a már berakott képeket
		xhely=((rand()%8)*100);
		yhely=((rand()%8)*100);
}

}catch(exception& e){
	cerr << "exception "<< e.what() <<'\n';
	return 1;
}catch(...){
	cerr <<"error\n";
	return 2;

}
}
