

#include "Simple_window.h"
#include "Graph.h"

using namespace Graph_lib;

int main()
{
	//13.1
	Point p1 {100,100};
	int x_max = 800;
	int y_max = 1000;
	
	Simple_window win (p1, x_max, y_max, "Chapter 13");
	
	//13.2
	Lines grid;
	
	for (int x = 0; x <= x_max; x += 100)
	{
		grid.add(Point{x, 0}, Point(x, x_max));
	}
	
	for (int y = 0; y <= x_max; y += 100)
	{
		grid.add(Point{0, y}, Point(x_max, y));
	}
	
	win.attach(grid);
	
	
	//13.3
	Vector_ref<Rectangle> r;
	
	for (int i = 0; i < 8; i++)
	{
		r.push_back(new Rectangle {Point{i*100, i*100}, 100, 100});
		r[i].set_fill_color(Color::red);
		win.attach(r[i]);
	}
	
	//13.4
	int size=200;

	Image image1 (Point{400, 600}, "image2.jpg");
	//image1.set_mask(Point(0,200), size, size);
	

	Image image2 (Point{600, 600}, "image2.jpg");
	//image2.set_mask(Point(0,200), size, size);


	Image image3 (Point{400, 0}, "image2.jpg");
	//image3.set_mask(Point(0,200), size, size);




	win.attach(image1);
	win.attach(image2);
	win.attach(image3);
	
	
	//13.5
	Image image5 (Point{0, 0}, "labda.jpg");
	image5.set_mask(Point(0,200), 100, 100);
	win.attach(image5);
	
	 int cnt = 1;
    while (cnt < 64){
        win.wait_for_button();
        if (cnt % 8 == 0) image5.move(-800, 100);   
        image5.move(100, 0);
        cnt++;
    }
	
	win.wait_for_button();
	
}
