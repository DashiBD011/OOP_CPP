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
#endif // DEBUG
			cout << "EConstructor:\t" << this << endl;


		}
		~Element()
		{
#ifdef DEBUG
			cout << "EDestructor:\t" << this << endl;
#endif // DEBUG

		}
		friend class List;
	};

	Element* Head;   // Указатель на начальный элемент
	Element* Tail;   // Указатель на конечный элемент
	unsigned int size;  // Размер списка
public:
	class Iterator
	{
		Element* Temp;
	public:
		Iterator(Element* Temp = nullptr) :Temp(Temp)
		{

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
		bool operator==(const Iterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const Iterator& other)const
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

	class ReverseIterator
	{
		Element* Temp;
	public:
		ReverseIterator(Element* Temp = nullptr) :Temp(Temp)
		{
#ifdef DEBUG
			cout << "RIConstructor:\t" << this << endl;
#endif // DEBUG

		}
		~ReverseIterator()
		{
#ifdef DEBUG
			cout << "RIDestructor:\t" << this << endl;
#endif // DEBUG
		}
		ReverseIterator& operator++()
		{
			Temp = Temp->pNext;
			return *this;
		}
		ReverseIterator operator++(int)
		{
			ReverseIterator old = *this;
			Temp = Temp->pNext;
			return old;
		}
		ReverseIterator& operator--()
		{
			Temp = Temp->pPrev;
			return *this;
		}
		ReverseIterator operator--(int)
		{
			ReverseIterator old = *this;
			Temp = Temp->pPrev;
			return old;
		}
		bool operator==(const ReverseIterator& other)const
		{
			return this->Temp == other.Temp;
		}
		bool operator!=(const ReverseIterator& other)const
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

	size_t getSize()const
	{
		return size;
	}
	Iterator begin()
	{
		return Head;
	}
	Iterator end()
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
		cout << "LConstructor:\t" << this << endl;
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
	List(const List& other)
	{
		Element* Temp = other.Head;
		while (Temp)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}
		cout << "LCopyConstructor:\t" << this << endl;
	}
	
	~List()
	{
		//while (Head)pop_front();
		while (Tail)pop_back();
		cout << "LDestructor:\t" << this << endl; 

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
		Element* Temp = other.Head;
		while (Temp)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}
		cout << "LCopyAssignment:\t" << this << endl;
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

	List list = { 3,5,8,13,21 };
	list.print();

	/*for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;*/
	
	cout << delimeter;
	cout << "Iterator:\n" << endl;
	for (List::Iterator it = list.begin(); it != list.end(); it++)
		cout << *it << tab;
	cout << endl;

	cout << delimeter;
	list.print_reverse();

	cout << delimeter;
	cout << "ReverseIterator:\n" << endl;
	for (List::ReverseIterator it = list.rbegin(); it != list.rend(); it--)
		cout << *it << tab;
	cout <<"\n"<< endl;

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

	
}