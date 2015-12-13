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
	/*Node<Type>* Search(int pos)
	{
		if (pos<0 || pos>length)
		{
			trow("Выход за границы списка");
		}
		
	}*/
	void AddElement(Type x, int pos) // pos-1 search
	{
		
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

