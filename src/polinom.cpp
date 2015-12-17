#include "polinom.h"
#include <ostream>
#include <iostream>

Polinom::Polinom()
{
	polinom = new List<monom>;
	length = 0;
}

Polinom::Polinom(const Polinom& x)
{
	length = x.length;
	
	polinom = new List < monom > ;

	if (polinom->GetHead() != NULL)
	{
		polinom->Delete();
	}

	Node<monom> *current = x.polinom->GetHead();
	Node<monom> *previous = x.polinom->GetHead();

	while (current->GetNext() != NULL)
	{
		polinom->AddElementOrdered(current->GetVar());
		current = current->GetNext();
	}
	polinom->AddElementOrdered(current->GetVar());
}

Polinom::~Polinom()
{
	//polinom->Delete();
}

void Polinom::AddElement(monom x)
{
	polinom->AddElementOrdered(x);
	length = polinom->GetLength();
}

int Polinom::GetLength()
{
	return length;
}

monom& Polinom::operator[](int pos)
{
	if (pos<0 || pos> length)
	{
		throw("Out of the list.");
	}
	Node<monom>* current = polinom->GetHead();
	for (int i = 0; i < pos; i++)
	{
		current = current->GetNext();
	}
	return current->GetVar();
	
}

void Polinom::Simplify()
{
	if (length == 1)
	{
		return;
	}
	Node<monom>* current = polinom->GetHead()->GetNext();
	Node<monom>* previous = polinom->GetHead();
	Node<monom>* temp = new Node < monom >(0);//промежуточный 

	while (current != NULL)
	{
		if (current->GetVar().GetDegree() == previous->GetVar().GetDegree())
		{
			temp->SetVar(previous->GetVar() + current->GetVar()); 
			previous->SetVar(temp->GetVar());
			if (current->GetNext() == NULL) {
				previous->SetNext(NULL);
				polinom->SetLength(polinom->GetLength() - 1);
				length = polinom->GetLength();
				return;
			}
			temp = current;
			current = current->GetNext();
			previous->SetNext(current);
			delete(temp);
			polinom->SetLength(polinom->GetLength() - 1);
			length = polinom->GetLength();

			continue;
		}
		previous = current;
		current = current->GetNext();
	}
}

Polinom operator + (const Polinom& left, const Polinom& right)
{
	Polinom res;
	Node<monom>* current = left.polinom->GetHead();
	while (current != NULL)
	{
		res.AddElement(current->GetVar());
		current = current->GetNext();
	}

	current = right.polinom->GetHead();
	while (current != NULL) {
		res.AddElement(current->GetVar());
		current = current->GetNext();
	}
	res.Simplify();

	return res;
}