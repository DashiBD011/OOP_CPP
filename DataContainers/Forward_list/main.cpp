#include<iostream>
using namespace std;

#define tab "\t"
#define delimeter "\n-----------------------------------------------------\n"


class Element
{
	int Data;        // Значение элемента
	Element* pNext;  // Указатель на следующий элемент 
	static int count;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		cout << "EConstructor:\t"<< this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
	friend class Iterator;
};

int Element::count = 0; // инициализация статической переменной

class Iterator
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr)
	{
		this->Temp = Temp;
		cout << "IConstructor:\t" << this << endl;
	}
	~Iterator()
	{
		cout << "IDestructor:\t" << this << endl;
	}

	//			Operators:
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

	bool operator==(const Iterator& other)const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const Iterator& other)const
	{
		return this->Temp != other.Temp;
	}

	Element*& operator->()
	{
		return Temp;
	}
	Element* get_current_address()
	{
		return Temp;
	}
};


class ForwardList 
{
	Element* Head;
	int size;
public:
	ForwardList() 
	{
		Head = nullptr; //DefaultConstructor создает пустой список
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	ForwardList(const ForwardList& other)
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
	ForwardList& operator=(const ForwardList& other)
	{
		if (this == &other)return *this;
		while (Head)pop_front();
		Element* Temp = other.Head;
		while (Temp)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}
		cout << "LCopyAssignment:" << this << endl;
		return *this;
	}

	//        Adding elements:
	void push_front(int Data)
	{
		/*Element* New = new Element(Data);
		New -> pNext = Head;
		Head = New;*/
		Head = new Element(Data, Head);
		size++;
	}

	void push_back(int Data)
	{
		// push_back не умеет работать с пустым списком
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		//Element* New = new Element(Data);
		Element* Temp = Head;
		while (Temp->pNext != nullptr)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element(Data);
		size++;
	}

	//        Erasing elements:
	void pop_front()
	{
		Element* Temp = Head;
		Head = Temp->pNext;
		delete Temp;
		size--;
	}

	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}

	void insert(int Data, int index)
	{
		if (index == 0)
		{
			push_front(Data);
			return;
		}
		//Element* New = new Element(Data);
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++, Temp = Temp->pNext)
			if (Temp->pNext == nullptr)break;
		/*Temp = Temp->pNext;
		New->pNext = Temp->pNext;
		Temp->pNext = New;*/
		Temp->pNext = new Element(Data, Temp->pNext);
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
		Element* Temp = Head;
		for (int i = 0; i < index-1; i++)
		{
			Temp = Temp->pNext;
		}
		Element* to_del = Temp->pNext;
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
		for (Iterator Temp = Head; Temp != nullptr; Temp++)
			cout << Temp.get_current_address() << tab << Temp->Data << tab << Temp->pNext << endl;;
		cout <<"Количество элементов в списке: "<< size << endl;
		cout <<"Общее количество элементов: "<< Element::count << endl;

	} 
};

//#define BASE_CHECK

void main()
{
	setlocale(LC_ALL, "");
	int n;
	cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.print();
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

	ForwardList list2(list);
	list2.print();

	ForwardList list3=list2;
	list3.print();
}