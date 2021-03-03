#include "Simple_window.h"
#include "Graph.h"



int main()
{
    using namespace Graph_lib;

    //7.2
	Simple_window win {Point{100,100}, 600, 400, "Canvas"};

	//7.3
	Axis x {Axis::x, Point{20,300}, 280, 10, "x axis"};
	Axis y {Axis::y, Point{20,300}, 280, 10, "y axis"};
	y.set_color(Color::cyan);
	y.label.set_color(Color::dark_red);

	//7.4
	Function sine {sin,0,100,Point{20,150},1000,50,50};
	sine.set_color(Color::yellow);
	
	//7.5
	Polygon haromszog;
	haromszog.add(Point{300,200});
	haromszog.add(Point{350,100});
	haromszog.add(Point{400,200});
	haromszog.move(150,90);
	haromszog.set_color(Color::blue);
	haromszog.set_style(Line_style::dash);
	haromszog.set_fill_color(Color::green);
	
	//7.6
	Rectangle teglalap {Point{500,300}, 50, 100};
	teglalap.set_color(Color::green);
	teglalap.set_style(Line_style::dash);
	teglalap.set_fill_color(Color::green);
	

	
	Closed_polyline tobb_szog;
	tobb_szog.add(Point{100,50});
	tobb_szog.add(Point{200,50});
	tobb_szog.add(Point{250,75});
	tobb_szog.add(Point{200,100});
	tobb_szog.add(Point{100,100});
	tobb_szog.add(Point{50,75});

	
	tobb_szog.set_color(Color::dark_green);
	tobb_szog.set_style(Line_style(Line_style::dash,3));
	tobb_szog.set_fill_color(Color::black);

	//7.7

	//7.8 7.9
	Text szoveg {Point{50,50}, "Szia, grafikus vilag :D!"};
	szoveg.set_font(Font::times_bold);
	szoveg.set_font_size(30);
	szoveg.set_color(Color::white);


	//7.9
	Image kep {Point{100,50},"index.jpg"};
	//kep.move(100,200);
	




	//7.10
	Circle kor {Point{100,200},50};
	Circle e {Point{100,200}, 25};
	e.set_color(Color::dark_red);	
	Mark m {Point{100,200},'x'};

	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
	<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};
	Image cal {Point{225,225},"logo1.jpg"};
	cal.set_mask(Point{40,40},200,150);
	
	
	






	win.attach(kep);
	win.attach(m);
	win.attach(kor);
	win.attach(e);
	
	win.attach(tobb_szog);
	win.attach(teglalap);
	win.attach(haromszog);
	win.attach(sine);
	win.attach(y);
	win.attach(x);
	win.attach(cal);
	win.attach(sizes);
	win.attach(szoveg);

	win.wait_for_button();

}
