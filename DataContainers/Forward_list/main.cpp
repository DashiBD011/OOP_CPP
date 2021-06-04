﻿#include<iostream>
using namespace std;

#define tab "\t"
#define delimeter "\n-----------------------------------------------------\n"

template<typename T>class Iterator;
template<typename T>class ForwardList;

template<typename T>
class Element
{
	T Data;        // Значение элемента
	Element<T>* pNext;  // Указатель на следующий элемент 
	static int count;
public:
	Element(T Data, Element<T>* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
#ifdef DEBUG
		cout << "EConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Element()
	{
		count--;
#ifdef DEBUG
		cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

	}
	friend class ForwardList<T>;
	friend class Iterator<T>;
};

template<typename T>
int Element<T>::count = 0; // инициализация статической переменной

template<typename T>
class Iterator
{
	Element<T>* Temp;
public:
	Iterator(Element<T>* Temp = nullptr)
	{
		this->Temp = Temp;
#ifdef DEBUG
		cout << "IConstructor:\t" << this << endl;
#endif // DEBUG

	}
	~Iterator()
	{
#ifdef DEBUG
		cout << "IDestructor:\t" << this << endl;
#endif // DEBUG

	}

	//			Operators:
	Iterator<T>& operator++()
	{
		Temp = Temp->pNext;
		return *this;
	}

	Iterator<T> operator++(int)
	{
		Iterator<T> old = *this;
		Temp = Temp->pNext;
		return old;
	}

	bool operator==(const Iterator<T>& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const Iterator<T>& other)const
	{
		return this->Temp != other.Temp;
	}

	Element<T>*& operator->()
	{
		return Temp;
	}
	Element<T>* get_current_address()
	{
		return Temp;
	}
	T& operator*()
	{
		return Temp->Data;
	}
	const T& operator*()const
	{
		return Temp->Data;
	}
};

template<typename T>
class ForwardList
{
	Element<T>* Head;
	int size;
public:
	Iterator<T> getHead()
	{
		return Head;
	}
	Iterator<T> begin()
	{
		return Head;
	}
	Iterator<T> end()
	{
		return nullptr;
	}
	ForwardList()
	{
		Head = nullptr; //DefaultConstructor создает пустой список
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	ForwardList(initializer_list<T>il) :ForwardList()
	{
		//il - это контейнер, такой же, как наш ForwardList
		//У любого контейнера есть методы begin() и end(),
		//которые возвращают указатели на начало и конец контейнера
		cout << typeid(il.begin()).name() << endl;
		for (T const* it = il.begin(); it != il.end(); it++)
		{
			//it - это итератор, который проходит по il
			push_back(*it);
		}
	}

	ForwardList(const ForwardList<T>& other)
	{
		Element* Temp = other.Head;
		while (Temp)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}
		cout << "LCopyConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		while (Head) pop_front();
		cout << "LDestructor:\t" << this << endl;
	}

	//			Operators:
	ForwardList<T>& operator=(const ForwardList<T>& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		Element<T>* Temp = other.Head;
		while (Temp)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}
		cout << "LCopyAssignment:" << this << endl;
		return *this;
	}

	//        Adding elements:
	void push_front(T Data)
	{
		/*Element* New = new Element(Data);
		New -> pNext = Head;
		Head = New;*/
		Head = new Element<T>(Data, Head);
		size++;
	}

	void push_back(T Data)
	{
		// push_back не умеет работать с пустым списком
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		//Element* New = new Element(Data);
		Element<T>* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element<T>(Data);
		size++;
	}

	//        Erasing elements:
	void pop_front()
	{
		Element<T>* Temp = Head;
		Head = Temp->pNext;
		delete Temp;
		size--;
	}

	void pop_back()
	{
		Element<T>* Temp = Head;
		while (Temp->pNext->pNext)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}

	void insert(T Data, int index)
	{
		if (index == 0)
		{
			push_front(Data);
			return;
		}
		//Element* New = new Element(Data);
		Element<T>* Temp = Head;
		for (int i = 0; i < index - 1; i++, Temp = Temp->pNext)
			if (Temp->pNext == nullptr)break;
		/*Temp = Temp->pNext;
		New->pNext = Temp->pNext;
		Temp->pNext = New;*/
		Temp->pNext = new Element<T>(Data, Temp->pNext);
		size++;
	}
	void erase(int index)
	{
		if (index > size)return;
		if (index == 0)
		{
			pop_front();
			return;
		}
		Element<T>* Temp = Head;
		for (int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		Element<T>* to_del = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		delete to_del;
		size--;
	}
	//        Methods
	void print()
	{
		/*Element* Temp = Head;
		while (Temp != nullptr)
		{
			cout << Temp << "\t" << Temp->Data << "\t" << Temp->pNext << endl;
			Temp = Temp->pNext;
		}*/
		for (Iterator<T> Temp = Head; Temp != nullptr; Temp++)
			//cout << Temp.get_current_address() << tab << Temp->Data << tab << Temp->pNext << endl;
			cout << *Temp << tab;
		cout << endl;
		cout << "Количество элементов в списке: " << size << endl;
		cout << "Общее количество элементов: " << Element<T>::count << endl;

	}
};

//#define BASE_CHECK
//#define ITERATOR_CHECK
//#define RANGE_BASED_ARRAY
//#define RANGE_BASED_LIST

void main()
{
	setlocale(LC_ALL, "");

#ifdef BASE_CHECK
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList<int> list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list = list;
	list.print();
#endif // BASE_CHECK

#ifdef ITERATOR_CHECK
	for (Iterator it = list.getHead(); it != nullptr; it++)
	{
		*it = rand() % 100;
	}
	list.print();
#endif // ITERATOR_CHECK

#ifdef BASE_CHECK
	//list.pop_front();
	//list.print();
	//list.pop_back();
	//list.print();
	//list.push_back(1000);
	int value;
	int index;
	cout << "Введите добавляемое значение: "; cin >> value;
	cout << "Введите индекс добавляемого значения: "; cin >> index;
	list.insert(value, index);
	list.print();
	cout << "Введите индекс удаляемого значения: "; cin >> index;
	list.erase(index);
	list.print();
	//cout << "Еще один список:\n" << endl;
	//ForwardList list2;
	//list2.push_back(3);
	//list2.push_back(5);
	//list2.push_back(8);
	//list2.print();

#endif // BASE_CHECK

	//ForwardList list2(list);
	//list2.print();
	//
	//ForwardList list3 = list2;
	//list3.print();

#ifdef RANGE_BASED_ARRAY

	int arr[] = { 3,5,8,13,21 };
	for (int i = 0; i < size(arr); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
	for (int i : arr)// Range-based for (цикл for для контейнера)
	{
		cout << i << tab;
	}
	cout << endl;

#endif // RANGE_BASED_ARRAY

#ifdef RANGE_BASED_LIST
	ForwardList<int> list = { 3,5,8,13,21 };
	list.print();
	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;
#endif // RANGE_BASED_LIST

	ForwardList<double> list = { 2.5, 3.14, 8.3, 5.4, 7.2 };
	for (double i : list)
	{
		cout << i << tab;
	}
	cout << endl;

}