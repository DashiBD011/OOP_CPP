#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimeter "\n-----------------------------------------------\n"

template<typename T>
class List
{
	class Element
	{
		T Data;       // Значение элемента
		Element* pNext; // Указатель на след. элемент
		Element* pPrev; // Указатель на пред. элемент
	public:
		Element(T Data, Element* pNext = nullptr, Element* pPrev = nullptr)
		{
			this->Data = Data;
			this->pNext = pNext;
			this->pPrev = pPrev;
#ifdef DEBUG
			cout << "EConstructor:\t\t" << this << endl;
#endif // DEBUG

		}
		~Element()
		{
#ifdef DEBUG
			cout << "EDestructor:\t\t" << this << endl;
#endif // DEBUG

		}
		friend class List<T>;
		

	};

	Element* Head;   // Указатель на начальный элемент
	Element* Tail;   // Указатель на конечный элемент
	unsigned int size;  // Размер списка
	
	class BaseIterator
	{
	protected:
		Element* Temp;
	public:
		BaseIterator(Element* Temp = nullptr) :Temp(Temp)
		{

#ifdef DEBUG
			cout << "BIConstructor:\t\t" << this << endl;
#endif // DEBUG

		}
		~BaseIterator()
		{
#ifdef DEBUG
			cout << "BIDestructor:\t\t" << this << endl;
#endif // DEBUG
		}
		bool operator==(const BaseIterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const BaseIterator& other)const
		{
			return this->Temp != other.Temp;
		}
		const T& operator*()const
		{
			return Temp->Data;
		}
		T& operator*()
		{
			return Temp->Data;
		}

	};
public:
	class Iterator :public BaseIterator
	{
	public:
		Iterator(Element* Temp = nullptr) :BaseIterator(Temp)
		{

#ifdef DEBUG
			cout << "IConstructor:\t\t" << this << endl;
#endif // DEBUG

	}
		~Iterator()
		{
#ifdef DEBUG
			cout << "IDestructor:\t\t" << this << endl;
#endif // DEBUG


		}
		Iterator& operator++()
		{
			BaseIterator::Temp = BaseIterator::Temp->pNext;
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator old = *this;
			BaseIterator::Temp = BaseIterator::Temp->pNext;
			return old;
		}
		Iterator& operator--()
		{
			BaseIterator::Temp = BaseIterator::Temp->pPrev;
			return *this;
		}
		Iterator operator--(int)
		{
			Iterator old = *this;
			BaseIterator::Temp = BaseIterator::Temp->pPrev;
			return old;
		}
	
	};
	class ReverseIterator:public BaseIterator
	{
	public:
		ReverseIterator(Element* Temp = nullptr) :BaseIterator(Temp)
		{
#ifdef DEBUG
			cout << "RIConstructor:\t\t" << this << endl;
#endif // DEBUG

		}
		~ReverseIterator()
		{
#ifdef DEBUG
			cout << "RIDestructor:\t\t" << this << endl;
#endif // DEBUG
		}
		ReverseIterator& operator++()
		{
			BaseIterator::Temp = BaseIterator::Temp->pPrev;
			return *this;
		}
		ReverseIterator operator++(int)
		{
			ReverseIterator old = *this;
			BaseIterator::Temp = BaseIterator::Temp->pPrev;
			return old;
		}
		ReverseIterator& operator--()
		{
			BaseIterator::Temp = BaseIterator::Temp->pNext;
			return *this;
		}
		ReverseIterator operator--(int)
		{
			ReverseIterator old = *this;
			BaseIterator::Temp = BaseIterator::Temp->pNext;
			return old;
		}

	
	};

	size_t getSize()const;
	Iterator begin();
	const Iterator begin()const;
	Iterator end();
	const Iterator end()const;
	ReverseIterator rbegin();
	ReverseIterator rend();
	List();
	explicit List(int size);
	List(const initializer_list<T>& il);
	List(const List<T>& other);
	List(List<T>&& other);
	~List();
	
	//               Operators:
	T& operator[](size_t Index);
	List<T>& operator=(const List<T>& other);
	List<T>& operator=(List<T>&& other);

	//               Adding elements:
	void insert_first_element(T Data);
	void push_front(T Data);
	void push_back(T Data);
	void insert(unsigned int Index, T Data);

	//               Erasing elements:
	void pop_front();
	void pop_back();
	void erase(int Index);

	//               Methods
	void print();
	void print_reverse();
};



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
template<typename T>
List<T>::List(const initializer_list<T>& il) :List()
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



//#define BASE_CHECK
//#define SIZE_CONSTRUCTOR_AND_INDEX_OPERATOR
//#define ITERATORS_CHECK
//#define COPY_METHODS_CHECK
#define TEMPLATES_CHECK

template<typename T>
List<T> operator+(const List<T>& left, const List<T>& right)
{
	List<T> cat = left;
	for (T i : right)cat.push_back(i);
	return cat;
}

void main()
{
	setlocale(LC_ALL, "Russian");
	//int n; cout << "Введите размер списка:"; cin >> n;

#ifdef BASE_CHECK
	int value;
	int index;
	List list;
	for (int i = 0; i < n; i++)
		list.push_back(rand() % 100);
	//list.push_front(rand() % 100);

	list.print();
	cout << delimeter << endl;;

	//cout << "Введите значение добавляемого элемента: "; cin >> value;
	//list.push_back(value);
	//list.print();
	//list.print_reverse();


	/*list.pop_back();
	list.print();*/

	//cout << delimeter << endl;;
	//cout << "Введите индекс добавляемого элемента: "; cin >> index;
	//cout << "Введите значение добавляемого элемента: "; cin >> value;
	//list.insert(index,value);
	//list.print();
	//cout << delimeter << endl;;
	//list.print_reverse();
	//
	//cout << delimeter << endl;;
	//cout << "Введите индекс удаляемого значения: "; cin >> index;
	//list.erase(index);
	//list.print();
	//list.print_reverse();

#endif // BASE_CHECK

#ifdef SIZE_CONSTRUCTOR_AND_INDEX_OPERATOR
			//List list = n;      // Type conversion from int to List
	List list(n);
	for (size_t i = 0; i < list.getSize(); i++) list[i] = rand() % 100;
	for (size_t i = 0; i < list.getSize(); i++)cout << list[i] << tab;
	cout << endl;
	list.print();
#endif // SIZE_CONSTRUCTOR_AND_INDEX_OPERATOR

#ifdef ITERATORS_CHECK

	List list = { 3,5,8,13,21 };
	list.print();

	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;

	cout << delimeter;
	cout << "Iterator:\n" << endl;
	for (List::Iterator it = list.begin(); it != list.end(); it++)
		cout << *it << tab;
	cout << endl;

	cout << delimeter;
	list.print_reverse();

	cout << delimeter;
	cout << "ReverseIterator:\n" << endl;
	for (List::ReverseIterator it = list.rbegin(); it != list.rend(); it++)
		cout << *it << tab;
	cout << "\n" << endl;

	cout << delimeter;
	List list2(list);     // CopyConstructor
	list2.print();

	cout << delimeter;
	List list3;
	list3 = list;         // CopyAssignment
	list3.print();


	//cout << delimeter;
	//list2.insert(3,100);
	//list2.print();


	



#endif // ITERATORS_CHECK

#ifdef COPY_METHODS_CHECK

	List<int> list1 = { 3, 5, 8, 13, 21 };
	list1.print();
	List<int> list2 = { 1, 2, 4, 6 };
	list2.print();

	List<int> list3;
	list3 = list1 + list2;
	list3.print();
	cout << delimeter;
	list3.print_reverse();

#endif // COPY_METHODS_CHECK

#ifdef TEMPLATES_CHECK

	List<int> i_list = { 3,5,8,13,21 };
	i_list.print();
	
	List<double> d_list = { 2.5, 3.14, 5.2, 8.3 };
	d_list.print();

	List<string> s_list = { "What", "can", "I", "do" };
	for (string i : s_list)cout << i << tab;
	cout << endl;

#endif // TEMPLATES_CHECK

}