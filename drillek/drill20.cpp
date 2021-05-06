#include <list>
#include <vector>
#include <iostream>
#include <array>
#include "std_lib_facilities.h"

using namespace std;

template<typename T>
void nov(T& temp,const int value)
{
	for(auto& a : temp)
	{
		a=a+value;
	}
} 

template<typename T>
void printout(const T& temp, const string s)
{	
	cout << s << ": ";
	for(auto& a : temp)
	{
		cout << a << " ";
	}
	cout << endl;
}

template<typename Iter1,typename Iter2>
Iter2 m_copy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	while(f1!=e1)
	{
		*f2=*f1;
		++f1;
		++f2;
	}
	return f2;
}

int main()
try{
	const int size =10;
	array<int, size> arr = {0,1,2,3,4,5,6,7,8,9};
	vector<int> vect= {0,1,2,3,4,5,6,7,8,9};
	list<int> lis = {0,1,2,3,4,5,6,7,8,9};

	array<int,size> arr2=arr;
	vector<int> vect2 =vect;
	list<int> lis2=lis;

	cout << "array vector list" << endl;
	printout(arr2,"Array");
	printout(vect2,"Vector");
	printout(lis2,"List");

	nov(arr,2);
	nov(vect,3);
	nov(lis,5);

	cout << "Increase:" << endl;
	printout(arr,"Array");
	printout(vect,"Vector");
	printout(lis,"List");

	m_copy(arr.begin(),arr.end(),vect.begin());
	m_copy(lis.begin(),lis.end(),arr.begin());
	cout << "Másolás array->vector ; list ->array" << endl;
	printout(arr,"Array");
	printout(vect,"Vector");
	printout(lis,"List");

	auto fv=find(vect.begin(),vect.end(),3);
	auto dv=distance(vect.begin(),fv);

	auto fl=find(lis.begin(),lis.end(),27);
	auto dl=distance(lis.begin(),fl);

	if(dv==vect.size()) cout << "3-as szám nem eleme a vektornak" << endl;
	else {
		cout << "3-as itt található ";
		cout << dv << endl;
	}

	if(dl==lis.size()) cout << "27-es szám nem eleme a listának" << endl;
	else {
		cout << "27-es itt található";
		cout << dl << endl;
	}

	return 0;

}catch(exception& e){
	cout << "Error: " << e.what() << endl;
	return 1;
}catch(...){
	cout << "Unknown error" << endl;
	return 2;
}