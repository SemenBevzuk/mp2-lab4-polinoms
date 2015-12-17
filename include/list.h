#pragma once
#include <stdlib.h>

template <class Type>
class Node {
private:
	Type var;
	Node<Type> *next;
public:
	void SetVar(Type x) {
		var = x;
	}
	void SetNext(Node<Type> *n) {
		next = n;
	}
	Node<Type>* GetNext()
	{
		return next;
	}
	Type GetVar() {
		return var;
	}

	Node(Type x) {
		SetVar(x);
		SetNext(NULL);
	}
	Node(Type x, Node<Type>* n) {
		SetVar(x);
		SetNext(n);
	}
};

template <class Type>
class List
{
private:
	Node<Type>* head;
	Node<Type>* tail;

	int length;

public:
	List()
	{
		head = NULL;
		tail = NULL;
		length = 0;
	}
	Node<Type>* GetHead()
	{
		return head;
	}
	int GetLength()
	{
		return length;
	}
	void AddToHead(Type x) {
		Node<Type>* temp = new Node<Type>(x, head);
		head = temp;
		if (tail == NULL)
		{
			tail = temp;
		}
		length++;
	}
	
	void AddToTail(Type x) {
		Node<Type>* temp = new Node<Type>(x, NULL);
		if (tail!=NULL) {
			tail->SetNext(temp);
		}
		tail = temp;
		if (head == NULL)
		{
			head = temp;
		}
		length++;
	}

	Node<Type>* At(int pos)
	{
		if (pos<0 || pos>length)
		{
			throw("Выход за границы списка");
		}
		Node<Type>* current = head;
		for (int i = 0; i < pos; i++)
		{
			current = current->GetNext();
		}
		return current;
	}

	void AddElement(Type x, int pos) // pos-1 search
	{
		if (pos == 0)
		{
			AddToHead(x);
			return;
		}
		Node<Type>* current = At(pos-1);
		Node<Type>* temp = new Node<Type>(x,current->GetNext());
		current->SetNext(temp);
		length++;
	}

	void AddElementOrdeled(Type x)
	{
		Node<Type>* current = head;
		Node<Type>* previous = head;
		Node<Type>* temp = new Node<Type>(x);
		
		if ( x>current->GetVar() )
		{
			AddToHead(x);
			return;
		}

		while (x < current->GetVar())
		{
			previous = current;
			current = current->GetNext();
		}

		previous->SetNext(temp);
		temp->SetNext(current);

		length++;
	}

	void DeleteFirst() {
		if (length == 0) return;

		Node<Type> *temp = head;
		head = temp->GetNext();
		delete temp;
		if (length == 1) {
			head = tail = NULL;
		}
		length--;
	}
	void Delete() {
		while (length != 0) {
			DeleteFirst();
		}
	}
	~List()
	{
		Delete();
	}
};

