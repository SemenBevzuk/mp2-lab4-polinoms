#include "monom.h"

monom::monom(double c, short d)
{
	coefficient = c;
	degree = d;
}

monom::monom(const monom& x)
{
	coefficient = x.GetCoefficient();
	degree = x.GetDegree();
}

double monom::GetCoefficient() const
{
	return coefficient;
}

short monom::GetDegree() const
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

monom& monom::operator=(const monom& right)
{
	if (this == &right) {
		return *this;
	}
	coefficient = right.GetCoefficient();
	degree = right.GetDegree();
	return *this;
}

bool operator==(const monom& left,const monom& right)
{
	if (left.GetDegree() != right.GetDegree())
	{
		return false;
	}
	if (left.GetCoefficient() != right.GetCoefficient())
	{
		
	}
	return true;
}

bool operator!=(const monom& left, const monom& right)
{
	return !(left == right);
}

bool operator < (const monom& left, const monom& right)
{
	if (left.GetDegree() <= right.GetDegree())
	{
		return  true;
	}
	return false;
}

bool operator > (const monom& left,const monom& right)
{
	if (left.GetDegree() >= right.GetDegree()) {
		return  true;
	}
	return false;
}

monom operator + (const monom& left, const monom& right)
{
	if (!(left == right))
	{
		//return 0;
		throw("Different degrees.");
	}
	monom res(left.GetCoefficient() + right.GetCoefficient(),left.GetDegree());
	return res;
}

monom operator - (const monom& left, const monom& right) {
	if (!(left == right)) {
		//return 0;
		throw("Different degrees.");
	}
	monom res(left.GetCoefficient() - right.GetCoefficient(), left.GetDegree());
	return res;
}