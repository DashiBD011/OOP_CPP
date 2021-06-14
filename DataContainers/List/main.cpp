#include<iostream>
using namespace std;
using std::cout;
using std::cin;
using std::endl;

#define tab "\t"
#define delimeter "\n-----------------------------------------------\n"

class List
{
	class Element
	{
		int Data;       // Значение элемента
		Element* pNext; // Указатель на след. элемент
		Element* pPrev; // Указатель на пред. элемент
	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr)
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
		friend class List;
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
		const int& operator*()const
		{
			return Temp->Data;
		}
		int& operator*()
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
			Temp = Temp->pNext;
			return *this;
		}
		Iterator operator++(int)
		{
			Iterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		Iterator& operator--()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		Iterator operator--(int)
		{
			Iterator old = *this;
			Temp = Temp->pPrev;
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
			Temp = Temp->pPrev;
			return *this;
		}
		ReverseIterator operator++(int)
		{
			ReverseIterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}
		ReverseIterator& operator--()
		{
			Temp = Temp->pNext;
			return *this;
		}
		ReverseIterator operator--(int)
		{
			ReverseIterator old = *this;
			Temp = Temp->pNext;
			return old;
		}

	
	};

	size_t getSize()const	
	{
		return size;
	}
	Iterator begin()
	{
		return Head;
	}
	const Iterator begin()const
	{
		return Head;
	}
	Iterator end()
	{
		return nullptr;
	}
	const Iterator end()const
	{
		return nullptr;
	}
	ReverseIterator rbegin()
	{
		return Tail;
	}
	ReverseIterator rend()
	{
		return nullptr;
	}
	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t\t" << this << endl;
	}
	explicit List(int size) :List()
	{
		while (size--)push_back(0);
	}
	List(const initializer_list<int>& il) :List()
	{
		cout << typeid(il.begin()).name() << endl;
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}
	List(const List& other):List()
	{
		//for (Iterator it = other.begin(); it != other.end();it++)push_back(*it);
		for (int i : other)push_back(i);
		cout << "LCopyConstructor:\t\t" << this << endl;
	}
	List(List&& other)
	{
		this->size = other.size;
		this->Head = other.Head;
		this->Tail = other.Tail;
		other.Head = other.Tail = nullptr;
		cout << "MoveConstructor:\t" << this << endl;

	}
	~List()
	{
		//while (Head)pop_front();
		while (Tail)pop_back();
		cout << "LDestructor:\t\t" << this << endl; 

	}
	
	//               Operators:
	
	int& operator[](size_t Index)
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

	List& operator=(const List& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		for (int i : other)push_back(i);
		cout << "LCopyAssignment:\t\t" << this << endl;
		return *this;
	}
	List& operator=(List&& other)
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

	void insert_first_element(int Data)
	{
		Head = Tail = new Element(Data);
		size++;
	}

	void push_front(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			insert_first_element(Data);
			return;
		}
		Head = Head->pPrev = new Element(Data, Head);
		size++;
	}

	void push_back(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			insert_first_element(Data);
			return;
		}
		Tail = Tail->pNext = new Element(Data, nullptr, Tail);
		size++;
	}

	void insert(unsigned int Index, int Data)
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
	
	void pop_front()
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
	
	void pop_back()
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
	void erase(int Index)
	{
		if (Index >= size)return;
		if (Index == 0)
		{
			pop_front();
			return;
		}
		if (Index == size-1)
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
	void print()
	{
		for (Iterator Temp = begin(); Temp != end(); Temp++)
			cout << *Temp << tab;
		cout << endl;

		cout << "\nКоличество элементов списка: " << size << endl;
	}

	void print_reverse()
	{
		cout << "print_reverse:\n" << endl;
		for (Iterator Temp = Tail; Temp!=nullptr; Temp--)  
			cout << *Temp << tab;
		cout << endl;

		cout << "\nКоличество элементов списка: " << size << endl;
	}
};


//#define BASE_CHECK
//#define SIZE_CONSTRUCTOR_AND_INDEX_OPERATOR
//#define ITERATORS_CHECK

List operator+(const List& left, const List& right)
{
	/*List result;

	for (List::Iterator it = left.begin(); it != left.end(); it++)
		result.push_back(*it);
	
	for (List::Iterator it = right.begin(); it != right.end(); it++)
		result.push_back(*it);

	return result;*/
	List cat = left;
	for (int i : right)cat.push_back(i);
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


	List list1 = { 3, 5, 8, 13, 21 };
	list1.print();
	List list2 = { 1, 2, 4, 6 };
	list2.print();

	List list3;
	list3 = list1 + list2;
	list3.print();
	cout << delimeter;
	list3.print_reverse();



#endif // ITERATORS_CHECK

	List list = { 2,4,6,8,7 };
	List list2(list);     // CopyConstructor
	list2.print();

	cout << delimeter;
	List list3;
	list3 = list;         // CopyAssignment
	list3.print();
}