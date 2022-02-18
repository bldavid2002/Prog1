#include "Window.h"
#include "Graph.h"
#include "Simple_window.h"

#include <string>
#include <iostream>

using namespace Graph_lib;

int main(){

	try{	//ez az ablak és ey pont
		Point t1 {100, 100};
		Simple_window win {t1,  600, 400, "My Window"};
		win.wait_for_button();            	
		
		
		//x-tengely
		Axis xa {Axis::x, Point{20, 300}, 280, 10, "x axis"};
		win.attach(xa);
		
		win.set_label("X-axis");
		win.wait_for_button();
	        
	        
	        //y-tengely + szinezés
	        Axis ya {Axis::y, Point{20, 300},280,20,"y axis"};
	        ya.set_color(Color::cyan);
	        ya.label.set_color(Color::dark_red);
	        win.attach(ya);
	        
	        win.set_label("y-axis");
	        win.wait_for_button();
	        
	        
	        //sinus 	          
	        Function sine{sin, 0, 100, Point{20, 150}, 1000, 50, 50};
	        win.attach(sine);
	        
	        win.set_label("sine");
	        win.wait_for_button();
	        
	        
	        
	        
	        
	        //Hátomzög
	        Polygon poly;
	        poly.add(Point{300, 200});
	        poly.add(Point{350, 100});
	        poly.add(Point{400, 200});
	        
	        poly.set_color(Color::red);
	        poly.set_style(Line_style::dash);
	        win.attach(poly);
	        
	        win.set_label("triangle");
	        win.wait_for_button();
	        
	        //Négyszög ötszög
	        Rectangle r {Point{200, 200}, 100, 50};
	        win.attach(r);
	        
	        Closed_polyline poly_rect;
	        poly_rect.add(Point{100, 50});
		poly_rect.add(Point{200, 50});
		poly_rect.add(Point{200, 100});
		poly_rect.add(Point{100, 100});
		poly_rect.add(Point{50, 75});
		
		
		win.attach(poly_rect);	        
	        win.wait_for_button();
		
		//szinezés vonal stílus
		r.set_fill_color(Color::yellow);
		poly.set_style(Line_style(Line_style::dash, 4));
		poly_rect.set_style(Line_style(Line_style::dash, 4));
		poly_rect.set_fill_color(Color::green);	        
	        
	        win.set_label("color");
	        win.wait_for_button();
	        
	        
	        //szöveg
	        Text t{Point{150, 150}, "Hello graphical Word!"};
	        t.set_font(Font::times_bold);
	        t.set_font_size(20);
	        win.attach(t);
	        
	        win.set_label("text");
	        win.wait_for_button();
	        	        
	        //Kép

			Image pic {Point{100, 50}, "badge.jpg"};
			win.attach(pic);
			win.set_label("kép");
			win.wait_for_button();

			//mozgatás
			
			
			pic.move(100,200);
			win.set_label("mozgatott kep");
			win.wait_for_button();
	        
	        //Eclips
			Circle kor {Point{100,200},50};
			Ellipse el {Point{100,200},75,25};
			el.set_color(Color::dark_red);
			Mark mark{Point{100,215},'x'};

			win.attach(kor);
			win.attach(el);
			win.attach(pic);
			win.attach(mark);
			win.set_label("Eclips");
			win.wait_for_button();


	        ostringstream oss;
			oss<<"screen size: "<<x_max()<<"*"<<y_max()<<";window size: "<<win.x_max()<<"*"<<win.y_max();
	        Text meret{Point{125, 20},oss.str()};

			win.attach(meret);
			win.set_label("Méret szöveg");
			win.wait_for_button();
	        

	}catch(exception& e){
		cerr << "exception "<< e.what() <<'\n';
		return 1;
	}catch(...){
		cerr <<"error\n";
		return 2;
	}
 