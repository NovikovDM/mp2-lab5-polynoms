#ifndef __TPOLYNOM_H__
#define __TPOLYNOM_H__

#include<iostream>
#include<cstdlib>
#include<iterator>
#include "TList.h"

using namespace std;
class TPolinom
{
	struct Monom
	{
		int koef;
		int degree;
		string name;
		Monom(int _koef = 1, int _degree = 0)
		{
			koef = _koef;
			degree = _degree;
		}
		Monom operator +(const Monom &m)
		{
			if (this->degree != m.degree)
				throw "incorrect addition";
			Monom tmp;
			tmp.koef = this->koef + m.koef;
			tmp.degree = this->degree;
			tmp.name = this->name;
			return tmp;
		}

		Monom operator -(const Monom &m)
		{
			if (this->degree != m.degree)
				throw "incorrect addition";
			Monom tmp;
			tmp.koef = this->koef - m.koef;
			tmp.degree = this->degree;
			tmp.name = this->name;
			return tmp;
		}
	};

	TList<Monom> Polinom;
	string startpolinom;
public:
	TPolinom(string i = " ") { startpolinom = i; }
	TPolinom(const TPolinom & pl);
	string StartPolinom() { return startpolinom; }
	void ToMonom();
	int Calculate(int _x, int _y, int _z);
	bool Operand(char op);
	bool XYZ(char op);
	bool IsOperation(char elem);
	float Coef(char elem);
	void Space(string str);
	int DegreePr(char elem);
	bool Proverka(string str);
	TPolinom operator+(TPolinom & pl);
	TPolinom operator-(TPolinom & pl);
	TPolinom &operator=(const TPolinom & pl);
	bool operator==(const TPolinom & pl)const;
	friend ostream & operator<<(ostream & os, TPolinom & pl);
	friend istream & operator>>(istream &is, TPolinom &pl);
	int GetDegree(char p);
};
#endif