#include "monom.h"

monom::monom(double c, short d)
{
	coefficient = c;
	degree = d;
}

double monom::GetCoefficient()
{
	return coefficient;
}

short monom::GetDegree()
{
	return degree;
}

void monom::SetCoefficient(double c)
{
	coefficient = c;
}

void monom::SetDegree(short d)
{
	degree = d;
}

bool operator==(monom& left, monom& right)
{
	if (left.GetDegree() != right.GetDegree())
	{
		return false;
	}
	else 
	{
		if (left.GetCoefficient() != right.GetCoefficient())
		{
			return false;
		}
	}
	return true;
}

bool operator < (monom& left, monom& right)
{
	if (left.GetDegree() < right.GetDegree())
	{
		return  true;
	}
	return false;
}

bool operator > (monom& left, monom& right)
{
	if (left.GetDegree() > right.GetDegree()) {
		return  true;
	}
	return false;
}