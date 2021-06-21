#include"List.h"


template<typename T>size_t List<T>::getSize()const
{
	return size;
}
template<typename T>typename List<T>::Iterator List<T>::begin()
{
	return Head;
}
template<typename T>typename const List<T>::Iterator List<T>::begin()const
{
	return Head;
}
template<typename T>typename List<T>::Iterator List<T>::end()
{
	return nullptr;
}
template<typename T>typename const List<T>::Iterator List<T>::end()const
{
	return nullptr;
}
template<typename T>typename List<T>::ReverseIterator List<T>::rbegin()
{
	return Tail;
}
template<typename T>typename List<T>::ReverseIterator List<T>::rend()
{
	return nullptr;
}
template<typename T> List<T>::List()
{
	Head = Tail = nullptr;
	size = 0;
	cout << "LConstructor:\t\t" << this << endl;
}
template<typename T>List<T>::List(int size) :List()
{
	while (size--)push_back(0);
}
template<typename T> List<T>::List(const initializer_list<T>& il) : List()
{
	cout << typeid(il.begin()).name() << endl;
	for (T const* it = il.begin(); it != il.end(); it++)
	{
		push_back(*it);
	}
}
template<typename T>
List<T>::List(const List<T>& other) :List()
{
	//for (Iterator it = other.begin(); it != other.end();it++)push_back(*it);
	for (T i : other)push_back(i);
	cout << "LCopyConstructor:\t\t" << this << endl;
}
template<typename T>
List<T>::List(List<T>&& other)
{
	this->size = other.size;
	this->Head = other.Head;
	this->Tail = other.Tail;
	other.Head = other.Tail = nullptr;
	cout << "MoveConstructor:\t" << this << endl;

}
template<typename T> List<T>::~List()
{
	//while (Head)pop_front();
	while (Tail)pop_back();
	cout << "LDestructor:\t\t" << this << endl;

}

//               Operators:
template<typename T>
T& List<T>::operator[](size_t Index)
{
	Element* Temp;
	if (Index < size / 2)
	{
		Temp = Head;
		for (size_t i = 0; i < Index; i++)	Temp = Temp->pNext;
	}
	else
	{
		Temp = Tail;
		for (size_t i = 0; i < size - Index - 1; i++)Temp = Temp->pPrev;
	}
	return Temp->Data;
}
template<typename T>
List<T>& List<T>::operator=(const List<T>& other)
{
	if (this == &other)return *this;
	while (Head)pop_front();
	for (T i : other)push_back(i);
	cout << "LCopyAssignment:\t\t" << this << endl;
	return *this;
}
template<typename T>
List<T>& List<T>::operator=(List<T>&& other)
{
	while (Head)pop_front();
	this->size = other.size;
	this->Head = other.Head;
	this->Tail = other.Tail;
	other.Head = other.Tail = nullptr;
	cout << "MoveAssignment:\t\t" << this << endl;
	return *this;
}
//               Adding elements:
template<typename T> void List<T>::insert_first_element(T Data)
{
	Head = Tail = new Element(Data);
	size++;
}
template<typename T> void List<T>::push_front(T Data)
{
	if (Head == nullptr && Tail == nullptr)
	{
		insert_first_element(Data);
		return;
	}
	Head = Head->pPrev = new Element(Data, Head);
	size++;
}
template<typename T> void List<T>::push_back(T Data)
{
	if (Head == nullptr && Tail == nullptr)
	{
		insert_first_element(Data);
		return;
	}
	Tail = Tail->pNext = new Element(Data, nullptr, Tail);
	size++;
}
template<typename T> void List<T>::insert(unsigned int Index, T Data)
{

	if (Index > size)return;
	if (Index == 0)
	{
		push_front(Data);
		return;
	}
	if (Index == size)
	{
		push_back(Data);
		return;
	}

	Element* Temp;
	if (Index < size / 2)
	{
		Temp = Head;
		for (int i = 0; i < Index; i++)	Temp = Temp->pNext;
	}
	else
	{
		Temp = Tail;
		for (int i = 0; i < size - Index - 1; i++)Temp = Temp->pPrev;
	}

	Temp->pPrev = Temp->pPrev->pNext = new Element(Data, Temp, Temp->pPrev);
	size++;
}

//               Erasing elements:
template<typename T> void List<T>::pop_front()
{
	if (Head == Tail)
	{
		delete Head;
		Head = Tail = nullptr;
		size--;
		return;
	}
	Head = Head->pNext;
	delete Head->pPrev;
	Head->pPrev = nullptr;
	size--;
}
template<typename T> void List<T>::pop_back()
{
	if (Head == Tail)
	{
		delete Tail;
		Head = Tail = nullptr;
		size--;
		return;
	}
	Tail = Tail->pPrev;
	delete Tail->pNext;
	Tail->pNext = nullptr;
	size--;
}
template<typename T> void List<T>::erase(int Index)
{
	if (Index >= size)return;
	if (Index == 0)
	{
		pop_front();
		return;
	}
	if (Index == size - 1)
	{
		pop_back();
		return;
	}

	Element* Temp;
	if (Index < size / 2)
	{
		Temp = Head;
		for (int i = 0; i < Index; i++)	Temp = Temp->pNext;
	}
	else
	{
		Temp = Tail;
		for (int i = 0; i < size - Index - 1; i++)Temp = Temp->pPrev;
	}
	Temp->pPrev->pNext = Temp->pNext;
	Temp->pNext->pPrev = Temp->pPrev;
	delete Temp;
	size--;

}
//               Methods
template<typename T> void List<T>::print()
{
	for (Iterator Temp = begin(); Temp != end(); Temp++)
		cout << *Temp << tab;
	cout << endl;

	cout << "\nКоличество элементов списка: " << size << endl;
}
template<typename T> void List<T>::print_reverse()
{
	cout << "print_reverse:\n" << endl;
	for (Iterator Temp = Tail; Temp != nullptr; Temp--)
		cout << *Temp << tab;
	cout << endl;

	cout << "\nКоличество элементов списка: " << size << endl;
}

