
#include "std_lib_facilities.h"

struct Person{
private:
	string first_name;
	string last_name;
	int a;
public:
	Person(){}
	Person(string ff,string ll, int aa);
	void set_fname(const string& fn) { first_name = fn; }
	void set_sname(const string& sn) { last_name = sn; }
	void set_age(const int& aa) { a = aa; }		
	string fname() const {return first_name;}
	string lname() const {return last_name;}
	int age() const {return a;}
	
};

Person::Person(string ff,string ll, int aa):first_name(ff),last_name(ll),a(aa){
	if(aa<0 || aa>150){error("Invalid Age.");}
	string nn=ff+ll;
	for(char c:nn){
		if(c==';' || c==':' || c=='"' || c=='[' || c==']' || c=='*' || c=='&' || c=='^' || c=='%' || c=='$' || c=='#' || c=='@' || c=='!'){
			error("Invalid name.");
		}
	}
}

ostream& print_person(ostream& os, Person p){
	os<<"Name: "<<p.fname()<<" "<<p.lname()<<" age: "<<p.age()<<endl;
	return os;
}

istream& read_person(istream& is, Person& p){
	string f;
	string l;
	int a;
	is>>f>>l>>a;
	p=Person(f,l,a);
	return is;
}

istream& operator>>(istream& is, Person& p)
{
    string f, s;
    int age;
    is >> f >> s >> age;
    if (!is) return is;

    p.set_fname(f);
    p.set_sname(s);
    p.set_age(age);

    return is;
}

ostream& operator<<(ostream& os, const Person& p)
{
    os << p.fname() << ' ' << p.lname() << ' ' << p.age();
    return os;
}

int main(){

	Person p("Goofy","Somebody",63);
	print_person(cout,p);

	Person p1;
	read_person(cin,p1);
	print_person(cout,p1);
	
	vector<Person> v(3);
	cout<<"Adj meg 3 nevet"<<endl;
	for(int i=0; i<v.size() ;++i)
	{
	
		cin >> v[i];
	
	}
	cout << endl;

	for(int i=0;i<3;i++) cout << v[i] << endl;





	/*for(Person p; read_person(cin,p);){
		if(p.fname()=="end"){break;}
		v.push_back(p);
	}
	for(Person p:v){
		print_person(cout,p);
	}
*/
	return 0;
}