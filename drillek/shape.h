//class Shape
class Shape {
public:
	void draw() const;

	virtual void move(int dx, int dy);

	void set_color(Color col) { lcolor = col; }
	Color color() const { return lcolor; }

	void set_style(Line_style sty) { ls = sty; }
	Line_style style() const { return ls; }

	void set_fill_color(Color col) { fcolor = col; }
	Color fill_color() const { return fcolor; }

	Point point(int i) const { return points[i]; }
	int number_of_points() const { return int(points.size()); }

	Shape(const Shape&) = delete;
	Shape& operator=(const Shape&) = delete;

	virtual ~Shape() { }

protected:
	Shape() {}
	Shape(initializer_list<Point> lst) { for (Point p : lst) add(p); }
	void add(Point p) { points.push_back(p); }
	void set_point(int i, Point p) { points[i] = p; }
	virtual void draw_lines() const;

private:
	vector<Point> points;
	Color lcolor {fl_color()};
	Line_style ls {0};
	Color fcolor {Color::invisible};
	
};