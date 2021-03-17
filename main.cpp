/*
    g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images`
*/
#include "Simple_window.h"
#include "Graph.h"

int main()
{

    int xmax = 600;
    int ymax = 400;

   Simple_window win{Point{100,100},
			xmax, ymax, "Graphics classes"};


	Line l (Point{100,100}, Point{200,200});

	win.attach(l);

	Lines ll {Point{100,100}, Point{200,200},
	Point{400,400}, Point{500,500}};

	win.attach(ll);

	win.wait_for_button();





   }


