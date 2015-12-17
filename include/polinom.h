// ����� ������� - ������������� ����������� ������ �������
// ������������ �������� ������, ������� ������, �������� ������,  
// ����� ������, �������� ���������(������� ������������� �������), 
// ��������� ���������
#pragma once
#include "monom.h"
#include "list.h"

class Polinom
{
private:
	List<monom>* polinom;
	int length;
public:
	Polinom();
	Polinom(const Polinom &x);
	~Polinom();
	void AddElement(monom x);
	int GetLength();
	
	void Simplify();
	monom& operator[](int pos);
	friend Polinom operator + (const Polinom& left, const Polinom& right);
	friend Polinom operator - (const Polinom& left, const Polinom& right);
};