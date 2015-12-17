// класс или структура Монома (double коэффициент, целая свернутая степень)
#pragma once

class monom
{
private:
	double coefficient;
	short degree; // xyz, где x,y,z принадлежат [0..9], x - степень x
public:
	monom(double c=0, short d=0);
	double GetCoefficient();
	short GetDegree();
	void SetCoefficient(double c = 0);
	void SetDegree(short d = 0);
	friend bool operator ==(monom& left, monom& right);
	friend bool operator <(monom& left, monom& right);
	friend bool operator >(monom& left, monom& right);

};