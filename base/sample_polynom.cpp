#include <iostream>
#include <string>
#include <list>
#include "TPolynom.h"

using namespace std;

int main()
{
	string expression1, expression2;
	double res;
	setlocale(LC_ALL, "Russian");
	int s1;
	cout << "1 - add polynomials \n";
	cout << "2 - subtract polynomials \n";
	cout << "3 - calculate polynomial \n";
	cin >> s1;
	switch (s1)
	{
	case 1:
	{
		TPolinom mypl2, mypl1;
		cout << "Enter first polynomial: ";
		cin >> mypl1;
		cout << "Enter second polynomial: ";
		cin >> mypl2;
		mypl1.ToMonom();
		mypl2.ToMonom();
		cout << mypl1 + mypl2 << "\n";
		break;
	}
	case 2:
	{
		TPolinom mypl2, mypl1;
		cout << "Enter first polynomial: ";
		cin >> mypl1;
		cout << "Enter second polynomial: ";
		cin >> mypl2;
		mypl1.ToMonom();
		mypl2.ToMonom();
		cout << mypl1 - mypl2 << "\n";
		break;
	}
	case 3:
	{
		TPolinom mypl1;
		cout << "Enter polynomial: ";
		cin >> mypl1;
		int x, y, z;
		cout << "Enter x: \n";
		cin >> x;
		cout << "Enter y: \n";
		cin >> y;
		cout << "Enter z: \n";
		cin >> z;
		mypl1.ToMonom();
		cout << mypl1.Calculate(x, y, z) << "\n";
		break;
	}
	}
	return 0;
}
