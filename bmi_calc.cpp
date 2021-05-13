#include<iostream>
#include<exception>
#include<math.h>

using namespace std;

class Bad_input{};

class Szemely
{
public:
	Szemely() {}
	Szemely(double m, double s, char n, int kor): magassag(m), suly(s), nem(n), eletkor(kor) {}

	double get_magassag() const { return magassag; }
	double get_suly() const { return suly; }
	char get_nem() const { return nem; }
	int get_eletkor() const { return eletkor; }

	void set_magassag(const double& m) { magassag = m; }
	void set_suly(const double& s) { suly = s; }
	void set_nem(const char& n) { nem = n; }
	void set_eletkor(const int& k) { eletkor = k; }
private:
	double magassag;
	double suly;
	char nem;
	int eletkor;
};

istream& operator>>(istream& is, Szemely& sz)
{
	double s, m;
	int kor;
	char n;
	is >> m >> s >> n >> kor;
	if (!is) return is; // hibakezeles
	sz.set_magassag(m);
	sz.set_suly(s);
	sz.set_nem(n);
	sz.set_eletkor(kor);
	return is;
}

ostream& operator<<(ostream& os, const Szemely& sz)
{
	return os << sz.get_magassag() << ' ' << sz.get_suly() << ' ' << sz.get_nem() << ' ' << sz.get_eletkor();
}


int main()
try {
	auto BMI = [](const Szemely& sz) { return sz.get_suly()/pow(sz.get_magassag(),2); }; // jelenleg az auto egy fuggveny pointert helyettesit
	Szemely sz1;
	cout << "Kerem adja meg a szemely adatait ilyen formatumban: <magassag(m)> <suly(kg)> <nem(f/n)> <eletkor(ev)>" << endl;
	cin >> sz1;
	cout << "Szemely1 adatai: "<< sz1 << endl;
	cout << "Szemely1 BMI index: ";
	cout << BMI(sz1) << endl << endl;


	Szemely sz2{1.2, 50, 'f', 20};
	cout << "Szemely2 adatai: " << sz2 << endl;
	cout << "Szemely2 BMI indexe: " << BMI(sz2) << endl;
	return 0;
} catch (exception& e) {
	cerr << e.what() << endl;
	return 1;
} catch (...) {
	cerr << "Something went wrong!" << endl;
	return 2;
}
